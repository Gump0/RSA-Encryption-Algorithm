// Header file for writedata class
#ifndef WRITEDATA_H
#define WRITEDATA_H

#include <string>

class WriteData {
public:
    void EncryptMessage(const std::string& sentMessage);
    void DecryptMessage();

    void BlocksToPuretext(const std::string& sentMessage);
    void PuretextToBlocks(const std::string& sentMessage);

    void WriteToTXT(const std::string& messageToWrite);
};

extern std::string storedMessage;
extern std::string combinedAsciiValue;

#endif
