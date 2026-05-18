#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    size_t n = 0; 

    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 1;

    std::list<int> L;
    std::cout << "Enter " << n << " elements: ";
    std::copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(L));
    std::list<int> result;
    size_t index = 1; 
    std::copy_if(L.begin(), L.end(), std::back_inserter(result), [&index](int) {
        return (index++ % 2) != 0; 
    });
    L = std::move(result);

    std::cout << "Resulting list: ";

    std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
