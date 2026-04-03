#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

int main() {
    std::string name;
    std::cout << "Введите имя файла: ";
    std::cin >> name;

    std::ifstream inputFile(name);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << name << std::endl;
        return 1;
    }

    std::istream_iterator<int> start(inputFile);
    std::istream_iterator<int> end;
    std::ostream_iterator<int> out_it(std::cout, " ");

    int counter = 0;

    std::remove_copy_if(start, end, out_it, [&counter](int) {
        counter++;
        return (counter % 2 == 0); 
    });

    std::cout << std::endl;
    inputFile.close();

    return 0;
}
