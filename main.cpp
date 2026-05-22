#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cmath>

/**
 * @brief Функциональный объект сравнения абсолютных значений двух чисел.
 * * Используется для определения, является ли модуль первого числа строго меньшим,чем модуль второго числа.
 */
struct less_abs {
    /**
     * @brief Перегруженный оператор круглых скобок для выполнения сравнения по модулю.
     * @param a Первое сравниваемое число.
     * @param b Второе сравниваемое число.
     * @return true Если |a| < |b|
     * @return false В противном случае.
     */
    bool operator()(const int a, const int b) const {
        return std::abs(a) < std::abs(b);
    }
};

/**
 * @brief Главная функция.
 * * Программа считывает пороговое значение K, затем последовательность целых чисел
 * до конца ввода После этого производит поиск с конца вектора первого элемента,чей модуль строго больше, чем модуль K.
 * * @return int Статус завершения программы (0 — успешно, 1 — ошибка ввода K).
 */
int main() {
    int K;

    std::cout << "Введите K (> 0), а затем элементы вектора: \n";

    // Проверка корректности ввода переменной K
    if (!(std::cin >> K)) {
        return 1;
    }

    std::vector<int> V;

    // Считывание элементов вектора из стандартного потока ввода
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(V));

    // Подключение пространства имен плейсхолдеров (_1, _2 и т.д.) для работы с std::bind
    using namespace std::placeholders;

    /**
     * Поиск первого элемента с конца вектора, удовлетворяющего условию.
     */
    auto it = std::find_if(V.rbegin(), V.rend(), std::bind(less_abs(), K, _1));

    std::cout << "Результат: ";
    // Если элемент, удовлетворяющий условию, найден
    if (it != V.rend()) {
        std::cout << *it << std::endl;
    }
    // Если ни один элемент не подошел под критерий поиска
    else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
