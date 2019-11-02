#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Encryption works with a string key of 5", "[cipher]"){
    CaesarCipher caesarCipher {"5"};
    std::string output {caesarCipher.applyCipher("HELLO", CipherMode::Encrypt)};
    REQUIRE(output == "MJQQT");
}


TEST_CASE("Encryption works with an integer key of 32", "[cipher]"){
    CaesarCipher caesarCipher {32};
    std::string output {caesarCipher.applyCipher("HELLO", CipherMode::Encrypt)};
    REQUIRE(output == "NKRRU");
}

TEST_CASE("Decryption works with a string key of 10", "[cipher]"){
    CaesarCipher caesarCipher {"10"};
    std::string output {caesarCipher.applyCipher("ROVVY", CipherMode::Decrypt)};
    REQUIRE(output == "HELLO");
}

TEST_CASE("Decryption works with an integer key of 150", "[cipher]"){
    CaesarCipher caesarCipher {150};
    std::string output {caesarCipher.applyCipher("BYFFIQILFX", CipherMode::Decrypt)};
    REQUIRE(output == "HELLOWORLD");
}