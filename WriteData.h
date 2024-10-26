// Header file for writedata class
#ifndef WRITEDATA_H
#define WRITEDATA_H

#include <string>

class WriteData {
public:
    void EncryptMessage(const std::string& sentMessage, int e, int n);
    void DecryptMessage();

    void PureTextToASCII(const std::string& sentMessage);
    void AsciiToPureText(const std::string& sentMessage);

    void WriteToTXT(const std::string& messageToWrite);

    int ModulusExponent(int base, int exp, int mod);
};

extern std::string storedMessage;
extern std::string combinedAsciiValue;
extern std:: string encryptedMessage;

#endif
