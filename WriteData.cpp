#include "WriteData.h"
#include <iostream>
#include <fstream>

using namespace std;

std::string storedMessage = "";

void WriteData::WriteEncryptedMessage(const std::string& sentMessage) {
    string filename = "secretmsg.txt";
    string message = sentMessage;

    ofstream outFile(filename);

    PuretextToEncrypted(sentMessage);

    if(outFile.is_open()) {
        outFile << message;
        outFile.close();
        cout << "Secret message written to 'scretmsg.txt': " << endl;
    }
    else { 
        cout << "ERROR: Secret message failed to write to file: " << endl;
    }
}

void WriteData::WriteDecryptedMessage(){
    // cout << "Calling method to decrypt msg: " << endl;
}

void PuretextToEncrypted(const std::string& sentMessage) {

}