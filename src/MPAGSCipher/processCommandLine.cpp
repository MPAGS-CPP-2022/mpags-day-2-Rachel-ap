#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "processCommandLine.hpp"

//process the command line arguments 
bool processCommandLine(
                        const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFile,
                        std::string& outputFile,
                        bool& encrypt,
                        bool& decrypt,
                        size_t& key
)
{    const std::size_t nCmdLineArgs{args.size()};


// Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option

            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = args[i + 1];
                ++i;
            }

        } else if (args[i] == "-encrypt") 
        {// Next element is filename unless "-encrypt " is the last argument
            if (i == nCmdLineArgs -1){
                std::cerr << "[error] -encrypt requires a key to be given" << std::endl;
                //exit main with non-zero return to indicate failure
                return false;
                
            }
            else {
                // Got key, so assign value and advance past it
                encrypt = true;
                key = std::stoi(args[i+1]);
                ++i;

            }
        } 
        else if (args[i] == "-decrypt")
        {
            if (i ==nCmdLineArgs -1){
                std::cerr << "[error] -decrypt requires a key to be given" << std::endl;
                //exit main with non-zero return to indicate failure
                return false;
            }
            else{
                //Got key, so assign value and advance past it
                decrypt = true;
                key = std::stoi(args[i+1]);
                ++i;
            }
        }
        
        
        
            else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return false;
        }
    }
return true;

}
