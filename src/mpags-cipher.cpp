#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TransformChar.hpp"
#include "processCommandLine.hpp"


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};


    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile))
    {
        return 1;
    }    
    
    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    char in_char{'x'};
    std::string inputText;
    
    // Read in user input from stdinfile
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::ifstream inputStream{inputFile};

        if (!inputStream.good()){
            std::cerr << "unable to open file" << std::endl;
            return 1;
        }

        while(inputStream >> in_char){
            inputText += transformChar(in_char);
        }
    }

    else{
        while(std::cin >> in_char){

            inputText += transformChar(in_char);
        }
    }

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::ofstream outputStream{outputFile};

        if (!outputStream.good())
        {
            std::cerr << "Unable to open file for writing " << std::endl;
            return 1;

        }

        outputStream << inputText << std::endl;


    }




    //Print out the transliterated text
    std::cout << inputText <<std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}

