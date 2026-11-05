#include <random>
#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<typename T>
using massive = vector<T>;

massive<int> random_massive(const int len);
void print_massive(const massive<int>& arr);
unsigned int bubble_algorithm(massive<int>& arr);
unsigned int insert_algorithm(massive<int>& arr);
unsigned int Hoar_algorithm(massive<int>& arr);

int main() {
    std::setlocale(LC_ALL, "");

    const size_t trials = 50;
    const size_t arrLen = 10000;

    unsigned long long int total_bubble = 0;
    unsigned long long int total_insert = 0;
    unsigned long long int total_hoare = 0;

    massive<int> demo = random_massive(15);
    cout << "=== Исходный массив ===" << endl;
    print_massive(demo);

    massive<int> demo_copy = demo;
    unsigned int ops_bubble = bubble_algorithm(demo_copy);
    cout << "\n=== После пузырьковой сортировки ===" << endl;
    print_massive(demo_copy);
    cout << "Количество операций сравнения (ops): " << ops_bubble << endl;

    demo_copy = demo;
    unsigned int ops_insert = insert_algorithm(demo_copy);
    cout << "\n=== После сортировки вставками ===" << endl;
    print_massive(demo_copy);
    cout << "Количество операций сравнения (ops): " << ops_insert << endl;

    demo_copy = demo;
    unsigned int ops_hoare = Hoar_algorithm(demo_copy);
    cout << "\n=== После сортировки Хоара ===" << endl;
    print_massive(demo_copy);
    cout << "Количество операций сравнения (ops): " << ops_hoare << endl;

    cout << "\n\n== Запуск тестирования: " << arrLen << " элементов, " << trials << " прогонов ==\n" << endl;

    for (size_t i = 0; i < trials; i++) {
        massive<int> data = random_massive(arrLen);

        // Прогон пузырьковой сортировки
        massive<int> data_copy = data;
        total_bubble += bubble_algorithm(data_copy);

        // Прогон сортировки вставками
        data_copy = data;
        total_insert += insert_algorithm(data_copy);

        // Прогон сортировки Хоара
        data_copy = data;
        total_hoare += Hoar_algorithm(data_copy);
    }

    // --- Вывод итоговых результатов ---
    cout << " СРЕДНИЕ РЕЗУЛЬТАТЫ ПОСЛЕ " << trials << " ПРОГОНОВ:" << endl;
    cout << "1. Пузырьковая сортировка:           " << total_bubble / trials << " сравнений" << endl;
    cout << "2. Сортировка вставками (бин. поиск): " << total_insert / trials << " сравнений" << endl;
    cout << "3. Быстрая сортировка Хоара:         " << total_hoare / trials << " сравнений" << endl;

    return 0;
}


/**
 * @brief Заполняет массив случайными числами в диапазоне [-100, 100]
 */
massive<int> random_massive(const int len) {
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(-100, 100);
    massive<int> arr(len);
    for (auto& elem : arr) {
        elem = dist(rng);
    }
    return arr;
}

/**
 * @brief Выводит элементы массива на экран
 */
void print_massive(const massive<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i + 1 < arr.size()) cout << ", ";
    }
    cout << endl;
}

/**
 * @brief Сортировка массива пузырьковым методом
 */
unsigned int bubble_algorithm(massive<int>& arr) {
    if (arr.size() <= 1) return 0;
    unsigned int ops = 0;

    for (size_t pass = 0; pass < arr.size() - 1; pass++) {
        for (size_t idx = 1; idx < arr.size() - pass; idx++) {
            ops++;
            if (arr[idx - 1] > arr[idx]) {
                swap(arr[idx - 1], arr[idx]);
            }
        }
    }
    return ops;
}

/**
 * @brief Сортировка вставками с бинарным поиском места вставки
 */
unsigned int insert_algorithm(massive<int>& arr) {
    if (arr.size() <= 1) return 0;
    unsigned int ops = 0;

    for (size_t i = 1; i < arr.size(); i++) {
        int val = arr[i];
        
        // Бинарный поиск места для вставки в отсортированной части [0, i)
        size_t start = 0, end = i;
        while (start < end) {
            size_t mid = start + (end - start) / 2;
            ops++; // Считаем операцию сравнения
            if (arr[mid] < val) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        arr.erase(arr.begin() + i);
        arr.insert(arr.begin() + start, val);
    }
    return ops;
}

/**
 * @brief Быстрая сортировка методом Хоара (через разделение на кучки)
 */
unsigned int Hoar_algorithm(massive<int>& arr) {
    if (arr.size() <= 1) return 0;
    unsigned int ops = 0;

    int pivot = arr[arr.size() / 2];
    massive<int> left_pile;
    massive<int> middle_pile;
    massive<int> right_pile;

    for (int x : arr) {
        ops++; // Сравнение x < pivot
        if (x < pivot) {
            left_pile.push_back(x);
        }
        else {
            ops++; // Сравнение x == pivot (если первое условие ложно)
            if (x == pivot) {
                middle_pile.push_back(x);
            }
            else {
                right_pile.push_back(x);
            }
        }
    }

    ops += Hoar_algorithm(left_pile);
    ops += Hoar_algorithm(right_pile);

    size_t idx = 0;
    for (int x : left_pile)   arr[idx++] = x;
    for (int x : middle_pile) arr[idx++] = x;
    for (int x : right_pile)  arr[idx++] = x;

    return ops;
}
