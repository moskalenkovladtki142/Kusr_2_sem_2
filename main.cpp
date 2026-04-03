#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> V;
    std::cout << "Введите элементы вектора (для окончания ввода нажмите Ctrl+Z или введите не число): ";
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(V));

    if (V.empty()) {
        std::cout << "Вектор пуст!" << std::endl;
        return 0;
    }

    for (auto i = V.begin(); i != V.end(); ++i) {
        i = V.erase(i);
        if (i == V.end()) {
            break;
        }
    }

    // Вывод результата
    std::cout << "Результат после удаления элементов с нечетными номерами: ";
    for (int val : V) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
