#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
//! Transliterate char to string
bool processCommandLine(
                        const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFile,
                        std::string& outputFile,
                        bool& encrypt,
                        bool& decrypt,
                        size_t& key

);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
