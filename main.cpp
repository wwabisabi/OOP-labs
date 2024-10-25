#include <iostream>
#include <string>
#include "eliminate_unset_bits.h"

int main() {
    std::string input;
    std::cin >> input; // Считываем строку из стандартного ввода
    long result = eliminate_unset_bits(input);
    std::cout << result << std::endl; // Выводим результат в стандартный вывод
    return 0;
}
