#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Добавлена функция быстрой сортировки

void quicksort(int *arr, int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

int main() {
    
    // Будет много букв, установим поддержку русской кодировки
    setlocale(0, "");
    
    // Создаём пустой массив staticArray на 100 значений
    int staticArray[100];
    
    // После созддания неотсортированного массива, найдем в нем мин и макс элементы и замерим скорость их поиска
    int minInUnsorted;
    int maxInUnsorted;
    duration<double> searchMaxAndMinInUnsorted;
    
    // Главное меню состоит из 2-х пунктов. Это связано с тем, что для выполнения остальных необходимо создать массив
    int userChoice;
    
    cout << "\t\tЗадание к практической работе №2 ОДНОМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ\n";
    cout << "\n";
    cout << "\t\t\t\tВыберите пункт меню:\n";
    cout << "\n";
    cout << "\t1) Создать массив размерности N = 100. Заполнить случайными INT в диапазоне от -99 до 99.\n";
    cout << "\n";
    cout << "\t2) Выход.\n";
    cout << "\n";
    cout << "Ваш выбор: ";
    
    cin >> userChoice;
    cout << "\n";
    
    
    switch (userChoice)
    {
            // Целочисленный массив размерности N = 100, созданный ранее заполним случайными значениями в диапазоне от -99 до 99.
        case 1:
        {
            // Заполняем массив случайными числами от -99 до 99
            for (int i = 0; i < 100; i++) {
                staticArray[i] = rand() % 199 - 99;
            }
            
            // Для выполнения дальнейшей задачи по сравнению поиска Мин и Макс элементов в массиве и скорости их поиска, заранее сделаем необходимые измерения
            minInUnsorted = staticArray[0];
            maxInUnsorted = staticArray[0];
            // Начало замера времени поиска Мин и Макс элементов в неотсортированном массиве
            auto startToSearchMaxAndMinInUnsorted = system_clock::now();
            for (int index = 0; index < 100; index++)
            {
                if (staticArray[index] <= minInUnsorted)
                {
                    minInUnsorted = staticArray[index];
                }
                if (staticArray[index] >= maxInUnsorted)
                {
                    maxInUnsorted = staticArray[index];
                }
            }
            // Конец замера времени поиска Мин и Макс элементов в неотсортированном массиве
            auto endToSearchMaxAndMinInUnsorted = system_clock::now();
            searchMaxAndMinInUnsorted = endToSearchMaxAndMinInUnsorted - startToSearchMaxAndMinInUnsorted;
            
            cout << "\t\t\t\t\Создал и заполнил, вот результат:\n ";
            for (int i = 0; i < 100; i++) {
                cout << staticArray[i] << " ";
            }
            cout << "\n";
            cout << "\n" << "\t\t\t\t\Теперь погоняем массив: ";
            cout << "\n";
            
            // После первоначального заполнения массива случайными значениями, предлагаем выбрать что необходимо сделать с ним далее
            int nextChoice;
            
            cout << "\n";
            cout << "\t1) Отсортируем и определим время, затраченное на сортировку.\n";
            cout << "\n";
            cout << "\t2) Найти MAX и MIN элемент отсортированного и неотсортированного массива. Подсчитайть время поиска этих элементов.\n";
            cout << "\n";
            cout << "\t3) Вывести среднее значение MAX и MIN и все числа, которые ему равны.\n";
            cout << "\n";
            cout << "\t4) Вывести количество элементов в отсортированном массиве, которые меньше введенного числа a.\n";
            cout << "\n";
            cout << "\t5) Вывести количество элементов в отсортированном массиве, которые больше введенного числа b.\n";
            cout << "\n";
            cout << "\t6) Ввести число и проверить есть-ли оно в массиве бинарничком.\n";
            cout << "\n";
            cout << "\t7) Поменять местами элементы массива. Вывести скорость обмена.\n";
            cout << "\n";
            cout << "\t8) Бонус в виде QuickSort.\n";
            cout << "\n";
            cout << "\t9) Заполнить массив случайными числами.\n";
            cout << "\n";
            
            
            cout << "Выбирай далее: ";
            
            // Этот блок необходим для возможности запуска каждого пункта меню многократно до тех пор, пока не нажата клавиша 0
            auto p = false;
            while(p != true)
            {
                cin >> nextChoice;
                cout << "\n";
                
                switch (nextChoice)
                {
                        // Отсортировать заданный в пункте 1 элементы массива […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono
                    case 1:
                    {
                        // Отсортируем массив пузырьком и замерим скорость сортировки
                        auto bubbleSortTime = system_clock::now();
                        for (int j = 0; j <= 99; j++) {
                            for (int index = 0; index <= 98; index++)
                            {
                                if (staticArray[index] >= staticArray[index + 1])
                                {
                                    swap(staticArray[index], staticArray[index + 1]);
                                }
                            }
                        }
                        auto endCountingTime = system_clock::now();
                        duration<double> elapsed = endCountingTime - bubbleSortTime;
                        
                        // Выведем отсортированный массив и время, затраченное на сортировку
                        for (int i = 0; i < 100; i++) {
                            cout << staticArray[i] << " ";
                        }
                        cout << "\n";
                        cout << std::fixed << "Сортирнул пузырьком за: " << elapsed.count() << " секунд" << "\n";
                        cout << "\n";
                        break;
                    }
                        // Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono
                    case 2:
                    {
                        // Найдем минимальный элемент отсортированного массива и замерим время его поиска
                        auto startToSearchMinimum = system_clock::now();
                        cout << "Минимальный элемент отсортированного массива: " << staticArray[0] << "\n";
                        auto finishSearchingMinimum = system_clock::now();
                        duration<double> timeForSearchMinimum = finishSearchingMinimum - startToSearchMinimum;
                        cout << fixed << "Время на поиск минимального элемента в отсортированном массиве: " << timeForSearchMinimum.count() << " секунд" "\n";
                        
                        // Найдем максимальный элемент отсортированного массива и замерим время его поиска
                        auto startToSearchMaximum = system_clock::now();
                        cout << "Максимальный элемент отсортированного массива: " << staticArray[99] << "\n";
                        auto finishSearchingMaximum = system_clock::now();
                        duration<double> timeForSearchMaximum = finishSearchingMaximum - startToSearchMaximum;
                        cout << fixed << "Время на поиск максимального элемента в отсортированном массиве: " << timeForSearchMaximum.count() << " секунд" "\n";
                        cout << "\n";
                        
                        // В этом блоке обратимся к заранее созданным переменным и значениям в ним
                        cout << "Минимальный элемент неотсортированного массива: " << minInUnsorted << "\n";
                        cout << "Максимальный элемент неотсортированного массива: " << maxInUnsorted << "\n";
                        cout << fixed << "Время на поиск минимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
                        cout << fixed << "Время на поиск максимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
                        cout << "\n";
                        break;
                    }
                        // Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. Выводит индексы всех элементов, которые равны этому значению, и их количество
                    case 3:
                    {
                        // Выведем среднее значение между максимум и минимум
                        int middle = (staticArray[0] + staticArray[99]) / 2;
                        cout << "Среднее значение максимального и минимального числа: " << middle << "\n";
                        cout << "\n";
                        
                        // Ищем в массиве числа, равные среднему
                        int numberInArray = 0;
                        for (int i = 0; i < 100; i++) {
                            if (staticArray[i] == middle) {
                                numberInArray += 1;
                                cout << "Нашел значение в массиве на позиции " << i << "\n";
                                cout << "Всего таких в массиве " << numberInArray << "\n";
                                cout << "\n";
                            }
                        }
                    }
                        break;
                        // Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем
                    case 4:
                    {
                        
                        // Ищем в массиве количество чисел, меньше введённого
                        cout << "Для поиска элементов в отсортированном массиве, которые меньше числа a, введите a: ";
                        int a;
                        int totalLowerThanA = 0;
                        cin >> a;
                        for (int i = 0; i < 100; i++) {
                            if (staticArray[i] < a) {
                                totalLowerThanA += 1;
                            }
                        }
                        cout << "меньше числа a: " << totalLowerThanA << " элементов";
                        cout << "\n";
                        
                    }
                        break;
                        // Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем
                    case 5:
                    {
                        // Ищем в массиве количество чисел, больше введённого
                        cout << "Для поиска элементов в отсортированном массиве, которые больше числа b, введите b: ";
                        int b;
                        int totalHigherThanB = 0;
                        cin >> b;
                        for (int i = 0; i < 100; i++) {
                            if (staticArray[i] > b) {
                                totalHigherThanB += 1;
                            }
                        }
                        cout << "больше числа b: " << totalHigherThanB << " элементов \n";
                        cout << "\n";
                        
                    }
                        break;
                        // Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. (*)
                    case 6:
                    {
                        bool ifFound = false;
                        
                        int numberToCheck;
                        int minIndex = 0;
                        int maxIndex = 99;
                        int currentIndex = (maxIndex + minIndex) / 2;
                        
                        
                        cout << "Какое число необходимо найти в массиве? ";
                        cin >> numberToCheck;
                        
                        // Пройдемся перебором и замерим время
                        auto startDirectSearch = system_clock::now();
                        for (int i = 0; i < 100; i++) {
                            if (staticArray[i] == numberToCheck) {
                                ifFound = true;
                            }
                        }
                        auto finishDirectSearch = system_clock::now();
                        duration<double> timeForDirectSearch = finishDirectSearch - startDirectSearch;
                        
                        
                        // Пройдемся бинарным поиском и замерим время
                        auto startBinary = system_clock::now();
                        while (numberToCheck != staticArray[currentIndex]) {
                            if ((maxIndex - minIndex) == 1) {
                                cout << "Такого числа в массиве нет" << "\n";
                                break;
                            }
                            
                            if (numberToCheck > staticArray[currentIndex]) {
                                minIndex = currentIndex;
                                currentIndex = (maxIndex + minIndex) / 2;
                                
                            } else if (numberToCheck < staticArray[currentIndex]) {
                                maxIndex = currentIndex;
                                currentIndex = (maxIndex + minIndex) / 2;
                            }
                            
                        }
                        if (numberToCheck == staticArray[currentIndex]) {
                            cout << "Найден на позиции " << currentIndex << "\n";
                        }
                        auto finishBinary = system_clock::now();
                        duration<double> timeForBinarySearch = finishBinary - startBinary;
                        
                        cout << fixed << "Разница между Бинарным поиском и перебором " << timeForBinarySearch.count() - timeForDirectSearch.count()<< " секунд" << "\n";
                        cout << "\n";
                        break;
                        
                        
                    }
                        // Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono
                    case 7:
                    {
                        
                        //  Меняем два введенных элемента в массиве
                        cout << "Чтобы поменять местами два элемента массива, введи их индексы:  ";
                        cout << "\n";
                        int elementToChangeOne;
                        int elementToChangeTwo;
                        cout << "Первый: ";
                        cin >> elementToChangeOne;
                        cout << "Второй: ";
                        cin >> elementToChangeTwo;
                        cout << "\n";
                        
                        //  Замеряем время на замену
                        auto startExchange = system_clock::now();
                        swap(staticArray[elementToChangeOne], staticArray[elementToChangeTwo]);
                        auto finishExchange = system_clock::now();
                        duration<double> exchangeDuration = finishExchange - startExchange;
                        cout << fixed << "Поменял за: " << exchangeDuration.count() << " секунд" "\n";
                        cout << "\n";
                        
                        // Выводим готовый массив (после замены)
                        cout << "Смотри как поменял: " << "\n";
                        for (int i = 0; i < 100; i++) {
                            cout << staticArray[i] << " ";
                        }
                        cout << "\n";
                        break;
                    }
                    case 8:
                    {
                        // А теперь сортирнём Квиком
                        int end = 99 - 1, begin = 0;
                        auto startQuickSortTime = system_clock::now();
                        quicksort(staticArray, end, begin);
                        auto endQuickSortTime = system_clock::now();
                        duration<double> qsortTime = endQuickSortTime - startQuickSortTime;
                        cout << "Отсортированный Квиком массив: " << "\n";
                        for (int i = 0; i < 99; i++)
                        cout << staticArray[i] << " ";
                        cout << fixed <<  "\n" << "Затрачено: " << qsortTime.count() << " секунд" "\n";
                        getchar();
                        break;
                    }
                        
                    case 9:
                    {
                        // Заполняем массив случайными числами от -99 до 99
                        for (int i = 0; i < 100; i++) {
                            staticArray[i] = rand() % 199 - 99;
                        }
                        cout << "\t\t\t\t\Создал и заполнил, вот результат:\n ";
                        for (int i = 0; i < 100; i++) {
                            cout << staticArray[i] << " ";
                        }
                        cout << "\n";
                    }
                        break;
                    case 0:
                    {
                        p = true;
                        cout << "Спасибо\n ";
                        exit(0);
                    }
                }
                cout << "Выбирай ещё или нажми ноль для выхода: ";
                cout << "\n";
            }
            
        }
            // Обработка выхода из программы
        case 2:
        {
            cout << "Спасибо\n ";
        }
            exit(0);
        default:
        {
            cout << "Введите число 1 или 2\n ";
        }
    }
}
