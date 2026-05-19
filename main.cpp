#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<std::string> V;
    std::map<char, int> M;

    std::cout << "Введите слова: " << std::endl;
    std::copy(std::istream_iterator<std::string>(std::cin), 
              std::istream_iterator<std::string>(), 
              std::back_inserter(V));

    for (std::vector<std::string>::iterator it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += it->size(); 
    }

    std::cout << "\nРезультат (буква : суммарная длина слов):" << std::endl;
    
    for (std::map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
