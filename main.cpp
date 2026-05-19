#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    std::list<int> L;
    
    std::cout << "Ввод элементов: ";
    
    std::copy(std::istream_iterator<int>(std::cin), 
              std::istream_iterator<int>(), 
              std::back_inserter(L));

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
