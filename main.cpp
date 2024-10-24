// RSA Encyrption Algorithm in C++
//
// Created by Gleb Belyakov on 10/21/2024

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

#include "WriteData.h"

using namespace std;

class KeyGen {

public:
    unsigned p; // chosen prime number
    unsigned q; // chose prime number
    unsigned n; // p*q
    unsigned phi_n; // phi_n = (p-1)*(q-1)
    unsigned e; // must be coprime with e & phi_n, 1 < e < phi_n
    unsigned d; // chose d so that this statement is true | d*e(mod phi_n) = 1

    void NumberInputPrompt();
    void MessageInputPrompt();
    void PrimalityCheck();
    unsigned Calculate_n();
    unsigned Calculate_nphi();
    unsigned Calculate_e();
    unsigned Calculate_d();
};

void KeyGen::NumberInputPrompt(){ // prompt the key generator to input two prime numbers
    cout << "Please enter a prime number (Must be a positive whole number)..." << endl;
    cin >> p;
    cout << "Pretty please import another prime number?" << endl;
    cin >> q;
}

void KeyGen::MessageInputPrompt(){ // Patched message input skipping whitespaces
    cout << "Please enter a message: " << endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::getline(std::cin, storedMessage);
    cout << storedMessage << endl;
}

void KeyGen::PrimalityCheck() { // check if p + q values are actually prime or not
    vector<unsigned> p_factors;

    for(unsigned i = 2; i <= static_cast<unsigned>(sqrt(p)); i++){
        if(p % i == 0) { // check if i factors evenly into p, if so push_back i and p/i
            p_factors.push_back(i);
            p_factors.push_back(p/i);
        }
    }

        vector<unsigned> q_factors;

    for(unsigned i = 2; i <= static_cast<unsigned>(sqrt(q)); i++){
        if(q % i == 0) { // check if i factors evenly into q, if so push_back i and q/i
            q_factors.push_back(i);
            q_factors.push_back(q/i);
        }
    }

    if(p_factors.size() != 0 || q_factors.size() !=0){
        throw (runtime_error("ERROR: Non prime input detected"));
    }
}

unsigned KeyGen::Calculate_n() {
    n = p * q;
    return n;
}

unsigned KeyGen::Calculate_nphi() {
    phi_n = (p-1)*(q-1);
    return phi_n;
}

unsigned KeyGen::Calculate_e() {
    unsigned i = 2;
    while(i < phi_n) {
        if(gcd(i, phi_n) == 1)
        break;
    else i++;
    }
    e = i;
    // Select the first gcd between i & phi_n
    return e;
}

unsigned KeyGen::Calculate_d() { 
// remember that d needs to satisify the following equation.
// d*e(mod phi_n) = 1
    unsigned k = 1;

    while(((k * phi_n) + 1) % e != 0)
        k++;
    d = ((k * phi_n) + 1) / e;
    return d;
}

int main(int argc, const char * argv[]) {
    WriteData writeData;

    try{
        KeyGen obj1;
        obj1.NumberInputPrompt();
        obj1.PrimalityCheck();
        cout << "The calculated n value is: " << obj1.Calculate_n() << endl;
        cout << "The calculated phi(n) value is: " << obj1.Calculate_nphi() << endl;
        cout << "The calculated value of e is: " << obj1.Calculate_e() << endl;
        cout << "The calculated value of d is: " << obj1.Calculate_d() << endl;
        // Eventually add the ability to write each value on a file
        obj1.MessageInputPrompt();
        writeData.EncryptMessage(storedMessage);
        // writeData.WriteDecryptedMessage();

    } catch(runtime_error & s) {
        cout << s.what() << endl;
    }
    return 0;
}