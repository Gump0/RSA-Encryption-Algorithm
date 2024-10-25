#include "WriteData.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

std::string storedMessage = "";
std::string combinedAsciiValue = "";
long long block = 0; // Used in 'PuretextToBlocks()' method

void WriteData::EncryptMessage(const std::string& sentMessage) {
   
    PuretextToBlocks(sentMessage);
    WriteToTXT(combinedAsciiValue); // bugged atm if output is 102114101 101 the written msg will be '101'
}

void WriteData::DecryptMessage(){ //
    // cout << "Calling method to decrypt msg: " << endl;
}

void WriteData::PuretextToBlocks(const std::string& sentMessage) { // takes a string of characters and converts each character to a block of ASCII values
    int blockSize = 3; // # of characters combined per block

    for(int i = 0; i < sentMessage.length(); i++){ // convert each character in 'sentMessage' to ASCII value
        int asciiValue = static_cast<int>(sentMessage[i]);

        if (!combinedAsciiValue.empty()) {
            combinedAsciiValue += " "; // Add a space before the next value, except for the first
        }
        combinedAsciiValue += std::to_string(asciiValue);
    }
    cout << "Converted message to ASCII: " << combinedAsciiValue << endl;
}

void WriteData::BlocksToPuretext(const std::string& sentMessage) { // takes a block of ASCII number data and converts it back to readable text

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