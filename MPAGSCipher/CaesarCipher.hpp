//
// Created by james on 01/11/2019.
//

#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>
#include <string>
#include <iostream>

class CaesarCipher {
    public:
        explicit CaesarCipher(const size_t key);
        explicit CaesarCipher(const std::string& key);

        size_t key_;

        std::string applyCipher(const std::string& inputText, const bool encrypt);

    private:
        const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        const size_t alphabetSize_ = alphabet.size();
};


#endif //MPAGSCIPHER_CAESARCIPHER_H
