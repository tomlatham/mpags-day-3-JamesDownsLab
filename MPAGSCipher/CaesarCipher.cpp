//
// Created by james on 01/11/2019.
//

#include "CaesarCipher.h"


CaesarCipher::CaesarCipher(const size_t key): key_{key} {}

CaesarCipher::CaesarCipher(const std::string& key): key_{0} {
        // check to see whether string can be parsed as a number
        bool stringIsNumber{true};
        for (const auto& elem: key){
            if (! std::isdigit(elem)){
                stringIsNumber=false;
            }
        }
        if (stringIsNumber) {
            key_ = std::stoul(key);
        }
        else{
            std::cout << "String cannot be parsed as integer" << std::endl;
        }
}

