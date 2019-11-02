#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help is returned", "[commandline]"){
    ProgramSettings programSettings {
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args {"MpagsCipher", "-h"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.helpRequested == true);
}

TEST_CASE("Version no is returned", "[commandline]"){
    ProgramSettings programSettings {
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args {"MpagsCipher", "--version"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.versionRequested == true);
}

TEST_CASE("Input file is returned correctly", "[commandline]"){
    ProgramSettings programSettings {
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args {"MpagsCipher", "-i", "test_input.txt"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.inputFile == "test_input.txt");
}

TEST_CASE("Output file is returned correctly", "[commandline]") {
    ProgramSettings programSettings{
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args{"MpagsCipher", "-o", "test_output.txt"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.outputFile == "test_output.txt");
}

TEST_CASE("Cipher key is parsed correctly", "[commandline]"){
    ProgramSettings programSettings{
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args{"MpagsCipher", "-k", "15"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.cipher_key == "15");
}

TEST_CASE("Cipher mode is parsed correctly", "[commandline]"){
    ProgramSettings programSettings{
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args{"MpagsCipher", "--decrypt"};
    processCommandLine(args, programSettings);
    REQUIRE(programSettings.cipherMode == CipherMode::Decrypt);
}