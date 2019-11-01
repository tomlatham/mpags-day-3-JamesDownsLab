//
// Created by james on 01/11/2019.
//

#include "CaesarCipher.hpp"


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

std::string CaesarCipher::applyCipher(const std::string &inputText, const bool encrypt)
{
    // Create the output string
    std::string outputText {};


    // Make sure that the key is in the range 0 - 25
    const size_t truncatedKey { key_ % alphabetSize_};

    // Loop over the input text
    char processedChar {'x'};
    for ( const auto& origChar : inputText ) {

        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for ( size_t i{0}; i < alphabetSize_; ++i ) {

            if ( origChar == alphabet[i] ) {

                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if ( encrypt ) {
                    processedChar = alphabet[ (i + truncatedKey) % alphabetSize_ ];
                } else {
                    processedChar = alphabet[ (i + alphabetSize_ - truncatedKey) % alphabetSize_ ];
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }
    return outputText;
}

