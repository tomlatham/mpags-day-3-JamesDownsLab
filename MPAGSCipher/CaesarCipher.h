//
// Created by james on 01/11/2019.
//

#ifndef MPAGSCIPHER_CAESARCIPHER_H
#define MPAGSCIPHER_CAESARCIPHER_H

#include <vector>
#include <string>
#include <iostream>

class CaesarCipher {
    public:
        explicit CaesarCipher(const size_t key);
        explicit CaesarCipher(const std::string& key);

        size_t key_;
};


#endif //MPAGSCIPHER_CAESARCIPHER_H
