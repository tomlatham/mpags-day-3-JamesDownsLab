#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "CipherMode.hpp"

// Define a struct to contain the settings
struct ProgramSettings {
    bool helpRequested;
    bool versionRequested;
    std::string inputFile;
    std::string outputFile;
    std::string cipher_key;
    CipherMode cipherMode;
};

bool processCommandLine(
        const std::vector<std::string>& args,
        ProgramSettings& programSettings
        );

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
