#include "encryption.h"

using namespace std;

encryption::encryption(){};

void encryption::encrypt(string ifile, string ofile) {
    //This section reads in all the lines from the input file.
    string line;
    string plaintext;
    ifstream inpt;
    inpt.open(ifile.c_str());
    if (!inpt) {
        cout << "The file does not exist. " << endl;
        return;
    }
    else if (inpt.is_open()) {
        while (getline(inpt,line)) {
            plaintext += line;

            if (!inpt.eof()) {
                plaintext += 10;
            }
        }
        inpt.close();
    }

    //This block performs the encryption on the input string
    cout << "Enter the encryption key: ";
    string key;
    cin >> key;
    string ciphertext;
    int i = 0;
    while (i != plaintext.length()) {
        ciphertext += plaintext[i] ^ key[i % key.size()];
        if (ciphertext[i] == 26)
            //the ascii value 26 causes the program to crash, so instead I assigned that ascii value to something 32 bits higher.
            ciphertext[i] = 58;
        i++;
    }

    //This block assigns the xor-ed string to the txt file.
    ofstream outpt;
    outpt.open(ofile.c_str(), ofstream::out | ofstream::trunc);
    if (outpt.is_open()) {
        outpt << ciphertext;
    }
    outpt.close();
    cout << ciphertext << "\n" << endl;
}
