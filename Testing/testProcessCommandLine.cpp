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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
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
    bool res { processCommandLine(args, programSettings) };
    REQUIRE(res);
    REQUIRE(programSettings.cipherMode == CipherMode::Decrypt);
}

// An example of a case where you check that errors are correctly identified
TEST_CASE("Key option entered with no key specified"){
    ProgramSettings programSettings{
            false,
            false,
            "",
            "",
            "",
            CipherMode::Encrypt};
    std::vector<std::string> args{"MpagsCipher", "-k"};
    bool res { processCommandLine(args, programSettings) };
    REQUIRE( !res );
}
