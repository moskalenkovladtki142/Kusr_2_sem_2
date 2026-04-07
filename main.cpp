#include <iostream>
#include <list>
#include <iterator>

int main() {
    std::list<int> L;
    int n, value;

    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 1;

    std::cout << "Enter " << n << " elements: ";
    for (int k = 0; k < n; ++k) {
        std::cin >> value;
        L.push_back(value);
    }
    for (auto i = L.begin(); i != L.end(); ) {
        auto next_it = i;
        if (++next_it != L.end()) {
            i = L.erase(next_it);
        } else {
            break;
        }
    }
    std::cout << "Resulting list: ";
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
