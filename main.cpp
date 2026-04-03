#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

int main() {
    std::vector<std::string> V;
    std::map<char, int> M;
    int N;

    std::cout << "Введите количество слов: ";
    std::cin >> N;

    std::cout << "Введите " << N << " слов (ЗАГЛАВНЫМИ БУКВАМИ): " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;
        V.push_back(word);
    }
    for (std::vector<std::string>::iterator it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += it->size(); 
    }

    std::cout << "\nРезультат (буква : суммарная длина слов):" << std::endl;
    for (std::map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}
