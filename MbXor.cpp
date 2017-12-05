#include "MbXor.h"

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
                key[z] == ' ';
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
int count = 0;
std::string s = "";
std::string dictionary[] = {"the","and","you","that","was","for","are","with","his","they","this","have","from","one",
"had","word","but","not","what","all","were","when","your","can","said","there","use","each","which","she","how","their",
"will","other","about","out","many","then","them","these"};

bool MbXor::dictionaryChecker(const string phrase){
    bool b = false;
    size_t pos;
    for(int i = 0; i < sizeof(dictionary)/sizeof(dictionary[0]); i++){
        pos = phrase.find(dictionary[i]);
        if(count==3){
            return true;
        }
        else if (pos != std::string::npos) {
            count++;
            s = dictionary[i];
            b = true;
       }
    }
    return b;
}


/*if (plainText[d] < 32 || plainText[d] > 126) {
                key[d % keyLength] += 1;
                plainText = "0";
                break;
            }*/
