#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "runCaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool& encrypt, const bool& decrypt )
{
    // Create the alphabet container and output string
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string output_str{""};
    int position{0}; 

    // Loop over the input text
    for (size_t i = 0; i < inputText.size(); i++){
    // For each character find the corresponding position in the alphabet
    char character{inputText[i]};
    position = alphabet.find(character);

    // Apply the shift (+ve or -ve depending on encrypt/decrypt)
    // to the position, handling correctly potential wrap-around
    if (encrypt == true){
        //determine the new character and add it to the output string
        output_str += alphabet[(position + key%26)%26];
    } 
    else if (decrypt == true){
        output_str += alphabet[(position + (26 -key%26))%26];
    }
    }
    // Finally (after the loop), return the output string
    return output_str;
}