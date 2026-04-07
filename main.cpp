#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

struct WordComparator {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b; 
    }
};

int main() {
    std::string name1, name2;
    std::cout << "Введите имя первого файла: ";
    std::cin >> name1;
    std::cout << "Введите имя второго файла: ";
    std::cin >> name2;

    std::ifstream file1(name1);
    std::ifstream file2(name2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Ошибка при открытии файлов." << std::endl;
        return 1;
    }
    std::istream_iterator<std::string> it1_begin(file1), it1_end;
    std::istream_iterator<std::string> it2_begin(file2), it2_end;
    std::ostream_iterator<std::string> out_it(std::cout, " ");

    std::merge(it1_begin, it1_end, 
               it2_begin, it2_end, 
               out_it, 
               WordComparator());

    std::cout << std::endl;

    file1.close();
    file2.close();

    return 0;
}
