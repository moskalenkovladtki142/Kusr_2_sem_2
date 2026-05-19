#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    std::list<int> L;

    std::cout << "Введите элементы: ";
    std::copy(std::istream_iterator<int>(std::cin), 
              std::istream_iterator<int>(), 
              std::back_inserter(L));

    for (auto i = L.begin(); i != L.end(); ++i) {
        L.insert(i, -1); 
    }

    std::cout << "Resulting list: ";
    std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
