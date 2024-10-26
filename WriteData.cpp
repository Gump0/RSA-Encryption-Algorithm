#include "WriteData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

std::string storedMessage = "";
std::string combinedAsciiValue = "";
std::string encryptedMessage = "";
long long block = 0; // Used in 'PureTextToASCII()' method

void WriteData::EncryptMessage(const std::string& sentMessage, int e, int n) {
    PureTextToASCII(sentMessage);

    std::istringstream iss(combinedAsciiValue);
    std::string numberString;
    std::vector<int> encryptedAsciiValues;

    while (iss >> numberString) { // Read each integer from the list of ASCII values
        int asciiInt = std::stoi(numberString); // convert string to int
        int encryptedInt = ModulusExponent(asciiInt, e, n);

        if(!encryptedMessage.empty())
            encryptedMessage += " ";
        encryptedMessage += to_string(encryptedInt);
    }
    WriteToTXT(encryptedMessage);
    cout << "Encrypted message: " << encryptedMessage << endl;
}

int WriteData::ModulusExponent(int base, int exp, int mod) { // calculate encrypted value using modular exponentiation
    long long result = 1;
    long long baseMod = base % mod;

    while(exp > 0) {
        if(exp % 2 == 1) 
            result = (result * baseMod) % mod;

        exp = exp >> 1; // Divide exp by 2
        baseMod = (baseMod * baseMod) % mod;
    }
    return static_cast<int>(result);
}

void WriteData::DecryptMessage() { //
    // cout << "Calling method to decrypt msg: " << endl;
}

void WriteData::PureTextToASCII(const std::string& sentMessage) { // takes a string of characters and converts each character to a block of ASCII values
    for(int i = 0; i < sentMessage.length(); i++){ // convert each character in 'sentMessage' to ASCII value
        int asciiValue = static_cast<int>(sentMessage[i]);

        if (!combinedAsciiValue.empty()) 
            combinedAsciiValue += " "; // Add a space before the next value, except for the first
        combinedAsciiValue += std::to_string(asciiValue);
    }
    cout << "Converted message to ASCII: " << combinedAsciiValue << endl;
}

void WriteData::AsciiToPureText(const std::string& sentMessage) { // takes a block of ASCII number data and converts it back to readable text

}

void WriteData::WriteToTXT(const std::string& messageToWrite) { 
    string filename = "secretmsg.txt";
    ofstream outFile(filename);
    // Write secret message to .txt file
    if(outFile.is_open()) {
        outFile << messageToWrite;
        outFile.close();
        cout << "Secret message written to 'secretmsg.txt': " << endl;
    }
    else { 
        cout << "ERROR: Secret message failed to write to file: " << endl;
    }
}