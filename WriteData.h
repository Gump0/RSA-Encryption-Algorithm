// Header file for writedata class
#ifndef WRITEDATA_H
#define WRITEDATA_H

#include <string>

class WriteData {
public:
    void WriteEncryptedMessage();
    void WriteDecryptedMessage();
};

extern std::string storedMessage;

#endif
