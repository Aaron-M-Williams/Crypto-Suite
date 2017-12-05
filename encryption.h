#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class encryption
{
    public:
        encryption();
        void encrypt(string ifile, string ofile);
        bool dictionaryChecker(const std::string phrase);

    protected:

    private:
};

#endif // ENCRYPTION_H
