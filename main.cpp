#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cmath>

struct less_abs {
    bool operator()(const int a, const int b) const {
        return std::abs(a) < std::abs(b);
    }
};

int main() {
    int K;

    std::cout << "Введите K (> 0), а затем элементы вектора: \n";

    if (!(std::cin >> K)) {
        return 1;
    }

    std::vector<int> V;

    std::copy(std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(V));

    using namespace std::placeholders;

    auto it = std::find_if(V.rbegin(), V.rend(), std::bind(less_abs(), K, _1));

    std::cout << "Результат: ";
    if (it != V.rend()) {
        std::cout << *it << std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
