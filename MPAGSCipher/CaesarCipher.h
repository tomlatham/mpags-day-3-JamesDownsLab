//
// Created by james on 01/11/2019.
//

#ifndef MPAGSCIPHER_CAESARCIPHER_H
#define MPAGSCIPHER_CAESARCIPHER_H

#include <vector>

class CaesarCipher {
    public:
        CaesarCipher(const size_t key);

        size_t key_;
};


#endif //MPAGSCIPHER_CAESARCIPHER_H
