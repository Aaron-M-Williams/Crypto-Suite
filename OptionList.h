#ifndef OPTIONLIST_H_INCLUDED
#define OPTIONLIST_H_INCLUDED
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
#include "MbXor.h"
#include "encryption.h"

//#include "stringToBinary.cpp"
//#include "binaryToString.cpp"
//#include "dictionaryChecker.cpp"
//#include "Caesar.cpp"
//#include "singlebyteXOREncrypy.cpp"
//#include "stringToBinary.cpp"


void stringToBinary();

void binaryToString();
void encryptCaesar();
void decryptCaesar();
std::string XOR();
void XORMULTI();


using namespace std;




//CAESAR LOGIC FOR ENCRYPTION AND DECRYPTION
void encryptCaesar(){
    cout << "Please enter what you would like to encrypt: ";
    string userInfo;
    getline(cin, userInfo);
    cin.clear();
    cin.ignore(1000000, '\n');

    cout << "\nPlease enter your key value: ";
    int key = 0;

    //input validation for encryption key
    while (key < 1){
        cin >> key;
        if (key < 1){
            cout << "\nInvalid encryption input. Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    int i = 0;
    int newLetter = 0;
    long length = userInfo.length();
    while (i < length){
        if(isalpha(userInfo[i])){
            int start = 0;
            if(userInfo[i] < 97){
                start = 65;
                newLetter = (((int)userInfo[i] + key - start) % 26) + start;
                userInfo[i] = (char)newLetter;
            }
            else{
                start = 97;
                int newLetter = (((int)userInfo[i] + key - start) % 26) + start;
                userInfo[i] = (char)newLetter;

            }
        }
        i++;
    }
    cout << "Encrypted information: " << userInfo << "\n";
}
void decryptCaesar(){
    cout << "Please enter what you would like to decrypt: ";
    string userInfo;
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, userInfo);

    cout << "Do you know the key? yes or no. ";

    bool optionBool = false;
    string option = " ";
    string y ="yes";
    string n = "no";

    while (optionBool == false){
        getline(cin, option);
        if (option == "yes" || option == "no"){
            optionBool = true;
        }

        else {
            cout << "Invalid input. Please type either yes or no. \n";
        }
    }
    if (option == "yes"){
        cout << "\nPlease enter your key value (1-26): ";
        int key = 0;

        //input validation for encryption key
        while (key < 1){
            cin >> key;
            if (key < 1 || key > 26){
                cout << "\nInvalid encryption input. Try again.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        int i = 0;
        int newLetter = 0;
        long length = userInfo.length();
        while (i < length){
            if(isalpha(userInfo[i])){
                int start = 0;
                if(userInfo[i] < 97){
                    start = 65;
                    newLetter = (((int)userInfo[i] - start - key +26) % 26) + start ;
                    userInfo[i] = (char)newLetter;
                }
                else{
                    start = 97;
                    int newLetter = (((int)userInfo[i] - start- key +26) % 26)+ start;
                    userInfo[i] = (char)newLetter;

                }
            }
            i++;
        }
        cout << "Decrypted information: " << userInfo << "\n";
    }
    if (option == "no"){
        for(int j =1; j < 27; j++){
            string helper = userInfo;
            int i = 0;
            int newLetter = 0;
            int key = j;
            long length = helper.length();
            while (i < length){
                if(isalpha(helper[i])){
                    int start = 0;
                    if(helper[i] < 97){
                        start = 65;
                        newLetter = (((int)helper[i] - start - key +26) % 26) + start;
                        helper[i] = (char)newLetter;
                    }
                    else{
                        start = 97;
                        int newLetter = (((int)helper[i] - start- key +26) % 26) + start;
                        helper[i] = (char)newLetter;

                    }
                }
                i++;
            }
            cout << "Key option: " << key << "\nDecrypted information: " << helper << "\n";
        }
    }
}


class XOR
{
public:
    XOR();
    virtual ~XOR();
protected:
private:
};

string XOR(string input, char key){
    string XORString = input;
    string newXOR = "";
    for(int i = 0; i < input.size();i++){
        newXOR += XORString[i]^(int(key+i))%255;
    }
    return newXOR;
}
void XOR_ENCRYPT() {
    /*char key = 'q';
    std::cout << XOR("X",key);
    return 0;*/
    /*The lines above are for manual testing if needed*/
    string phrase1 = "";
    cout << "Enter a phrase to encrypt: ";
    cin.ignore();
    getline(cin, phrase1);
    cout << "Enter a key to encrypt with: ";
    char key1;
    cin >> key1;
    cout << XOR(phrase1, key1) << endl;
    return;
}

void XOR_DECRYPT() {
    /*char key = 'q';
    std::cout << XOR("X",key);
    return 0;*/
    /*The lines above are for manual testing if needed*/
    bool b = true;
    while (b) {
        string x = "";
        cout << "Would you like to decrypt with a key? (Y or N): ";
        cin >> x;
        if (x == "y" || x == "Y") {
            string phrase = "";
            cout << "Enter a phrase to decrypt: ";
            cin.ignore();
            std::getline(std::cin, phrase);
            cout << "Enter a key to decrypt with: ";
            char key2;
            cin >> key2;
            std::cout << XOR(phrase, key2) << endl;
            return;
        } else if (x == "n" || x == "N") {
            char keys[] = {'!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
                           '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
                           'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                           'X', 'Y', 'Z', '[', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'I', 'j',
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|',
                           '}', '~'
                           };
            int end = 92;
            int count = 0;
            string s;
            cout << "Enter phrase: ";
            cin >> s;
            for (int i = 0; i < 92; i++) {
                count++;
                cout << count << " possible combination out of " << end << " using " << keys[i] << ":"
                     << XOR(s, keys[i]) << endl;
                return;
            }

        }
        else
        {
            b = false;
            cout << "Invalid option";

            return;
        }

    }
}


void binaryToString()
{
    string binary = "";
    cout << "Enter the binary you wish to be decrypted: " << endl;
    cin.ignore();
    getline(cin, binary);

    string output = ""; //what the binary will be converted to

    //removes spaces from binary input
    string::iterator end_pos = remove(binary.begin(), binary.end(), ' ');
    binary.erase(end_pos, binary.end());

    if (binary.length()%8 != 0)
    {
        cout << "\ninvalid input. NOTE: binary must be in 8-bit form. "<< endl;
        return;
    }

    for (int i = 0; i < binary.length()/8; i++)
    {
        int chunkTotal = 0; //the base-10 representation of the 8-bit binary value

        for (int k = 0; k < 8; k++)
        {
            int a = (binary[k+(8*i)])-48; //either a 1 or 0
            chunkTotal += a * (pow(2, (7-k)));

            if (a != 0 && a != 1)
            {
                cout << "\ninvalid input. Only the '0', '1', and ' ' characters may be used for binary input." << endl;
                return;
            }
        }
        output += char(chunkTotal);
    }

    cout << "\nDecrypted message:" << "\n'" << output << "'" << endl;

    return;
}


void stringToBinary()
{
    string str = "";

    cout << "Enter the string you wish to be encrypted: " << endl;
    cin.ignore();
    getline(cin,str);
    cout << "\nEncrypted message: '";

    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        cout << bitset<8>(str.c_str()[i]);

        if (i != size-1)
        {
            cout << " ";
        }
        else
        {
            cout << "'";
        }
    }

    return;
}






using namespace std;

MbXor::MbXor() {
    cout << "Enter the string you want decrypted in the text file that pops up.  Then save the file and close it.  Press enter to continue" << endl;
    string x;
    cin >> x;
    system("ciphertext.txt");
    ifstream inpt;
    inpt.open("ciphertext.txt");
    string line;
    if (!inpt) {
        cout << "The file does not exist. " << endl;
        return;
    }
    else if (inpt.is_open()) {
        while (getline(inpt,line)) {
            ctext += line;

            if (!inpt.eof()) {
                ctext += 10;
            }
        }
        inpt.close();
    }
}

MbXor::MbXor(string nameOfFile) {
    ifstream inpt;
    inpt.open(nameOfFile.c_str());
    string line;
    if (!inpt) {
        cout << "The file does not exist. " << endl;
        return;
    }
    else if (inpt.is_open()) {
        while (getline(inpt,line)) {
            ctext += line;

            if (!inpt.eof()) {
                ctext += 10;
            }
        }
        inpt.close();
    }
}

void MbXor::determineKeyLength() {
    double hammingWeightArray[ctext.length()];
    int minPosition = 0;

    //This loop tests key lengths from 1 to 40
    for (int i = 1; i <= 40 && i < ctext.size(); ++i) {
        string holder = ctext;
        string toBeDestroyed = ctext;
        string sub = ctext.substr(0, i);
        toBeDestroyed.erase(0,i);
        toBeDestroyed += sub;
        int hammingWeight = 0;

        //Adds up the ones in each character for each key length.  The hammingWeight that comes out of it
        //represents the hamming weight for that key length.
        for (int j = 0; j < ctext.length(); j++) {
            char temp = holder[j] ^ toBeDestroyed[j];

            while (temp != 0) {
                if (temp % 2 != 0) {
                    hammingWeight++;
                }
                temp = (temp / 2);
            }
        }

        //Adds to the HW array and calculates the minimum key length.
        //Need to check Math
        for (int k = 1; k <= i; k++) {
            if ((i % k) == 0) {
                hammingWeightArray[k-1] += hammingWeight / (40 / k);
                if (hammingWeightArray[k - 1] < hammingWeightArray[minPosition]) {
                    minPosition = k - 1;
                }
            }
        }

        cout << "The Hamming weight of Key Length " << i << " is: ";
        if (i < 10)
            cout << "   " << hammingWeight << endl;
        else
            cout << "  " << hammingWeight << endl;
    }
    for (int z = 0; z < 41; z++) {
        cout << "Hamming weight in the array is: " << hammingWeightArray[z] << endl;
    }
    cout << "\n\nThe most likely key length is: " << (minPosition + 1) << endl;
}



void MbXor::printOptions(int keyLength) {
    /*Two if blocks:
        (1) check to see if the result of xor-ing two character is in the normal ascii range,
            if not, ++ the key's ascii value at that spot.
        (2) check if the key character is the last normal ascii value. if it is, then make the next chacter in the string ++ and
        the current character the min ascii value.  Should probably do this part in the outside loop. */
    string key;
    string maxKeyValue;
    cout << ctext << endl;
    for (int z = 0; z < keyLength; z++) {
        key += " ";
        maxKeyValue += "~";
    }

    while (key < maxKeyValue) {
        int d = 0;
        string plainText = "";
        cout << "Key is: " << key << endl;

        while (d < ctext.size()) {
            plainText += ctext[d] ^ key[d % keyLength];
            d++;
            //static int be = 0;  //Theses lines are a test
            //be++;               //Also a test
            //cout << be;         //Still a test
        }

        if(dictionaryChecker(plainText)) {
            cout << "YOU DID IT!!!" << endl;
            cout << plainText;
        }

        bool temp = false;
        for (int z = keyLength - 1; z > 0; z--) {
            if (key[z] == '~') {
                temp = true;
                key[z] = ' ';
                key[z-1] += 1;
            }
        }
        if (!temp) {
            key[keyLength - 1] += 1;
        }
    }
    cout << "FINISHED!" << endl;
}



/*Program takes in a user inputted phrase and then checks for common words in the phrase. Returns true if any common phrases are found.*/
struct holder {
    int count = 0;
    std::string s = "";
    std::string dictionary[40] = {"the", "and", "you", "that", "was", "for", "are", "with", "his", "they", "this", "have",
                                "from", "one",
                                "had", "word", "but", "not", "what", "all", "were", "when", "your", "can", "said",
                                "there", "use", "each", "which", "she", "how", "their",
                                "will", "other", "about", "out", "many", "then", "them", "these"};
};

bool MbXor::dictionaryChecker(const string phrase){
    holder temp;
    bool b = false;
    size_t pos;
    for(int i = 0; i < sizeof(temp.dictionary)/sizeof(temp.dictionary[0]); i++){
        pos = phrase.find(temp.dictionary[i]);
        if(temp.count==3){
            return true;
        }
        else if (pos != std::string::npos) {
            temp.count++;
            temp.s = temp.dictionary[i];
            b = true;
        }
    }
    return b;
}

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

void XORMULTI(){
    cout << "Encrypt or Decrypt? ('e' or 'd')" << endl;
    char holder;
    cin >> holder;

    if (holder == 'e') {
        string readfile;
        cout << "What is the name of the file you want to open? (Do not include the extension)" << endl;
        cin >> readfile;
        readfile += ".txt";

        ifstream infile(readfile.c_str());
        while(!infile.good()) {
            cout << "That file does not exist.  Please enter a correct file name: " << endl;
            readfile.clear();
            cin >> readfile;
            readfile += ".txt";
            ifstream infile(readfile.c_str());
        }
        system(readfile.c_str());
        string writefile;
        cout << "What is the name of the file you want to write to? (Do not include the extension)" << endl;
        cin >> writefile;
        writefile += ".txt";

        encryption* pleasework = new encryption();
        pleasework->encrypt(readfile, writefile);
        cout << "The new string has been stored in the file " << writefile << endl;
    }

//    else if (holder == 'd') {
//        cout << "Do you already have the string saved in a text file (y/n)?" << endl;
//        char decision;
//        cin >> decision;
//
//        if (decision == 'n') {
//            MbXor decryption;
//            cout << "Enter the key length: ";
//            int keysize;
//            cin >> keysize;
//            decryption.printOptions(keysize);
//        }
//        else {
//            cout << "What file is it stored in? (Do not include the extension)";
//            string fileholder;
//            cin >> fileholder;
//            fileholder += ".txt";
//            MbXor decryption(fileholder);
//            cout << "Enter the key length: ";
//            int keysize;
//            cin >> keysize;
//            decryption.printOptions(keysize);
//
//        }
//        //Add a break until a user pushes enter.
//
//    }
}

#endif // OPTIONLIST_H_INCLUDED
