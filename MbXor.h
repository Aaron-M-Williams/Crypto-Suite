#ifndef MBXOR_H
#define MBXOR_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

class MbXor
{
    public:
        MbXor();
        MbXor(string nameOfFile);
        void determineKeyLength();
        void printOptions(int keyLength);
        bool dictionaryChecker(const string phrase);

    protected:

    private:
        string ctext;
        ifstream inputFile;
};

#endif // MBXOR_H
