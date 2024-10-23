// Header file for writedata class
#ifndef WRITEDATA_H
#define WRITEDATA_H

#include <string>

class WriteData {
public:
    void WriteEncryptedMessage(const std::string& sentMessage);
    void WriteDecryptedMessage();
};

extern std::string storedMessage;

#endif
