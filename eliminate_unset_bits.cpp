#include "eliminate_unset_bits.h"

long eliminate_unset_bits(const std::string& number) {
    std::string binary_str;
    for (char c : number) {
        if (c == '0' || c == '1') {
            binary_str += c;
        }
    }

    std::string ones_only;
    for (char c : binary_str) {
        if (c == '1') {
            ones_only += '1';
        }
    }

    if (ones_only.empty()) {
        return 0;
    }

    long result = std::stol(ones_only, nullptr, 2);
    return result;
}
