#include "OptionList.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>


using namespace std;

int main()
{
    while (true)
    {
        string encryptOrDecrypt = "";
        cout << "Encryption or Decryption? (E or D): ";
        cin >> encryptOrDecrypt;

        while (!(encryptOrDecrypt == "E" || encryptOrDecrypt == "e" || encryptOrDecrypt == "D" || encryptOrDecrypt == "d"))
        {
            cout << "invalid input." << endl;
            cout << "Encryption or Decryption? (E or D): ";
            cin >> encryptOrDecrypt;
        }

        //Encryption
        if (encryptOrDecrypt == "E" || encryptOrDecrypt == "e")
        {
            string encryptionType = "";
            cout << "\n=======================================================================================================================" << endl;
            cout << "                                              |     ENCRYPTION TYPES:     |" << endl;
            cout << "                                              |___________________________|" << endl;
            cout << "   1) caesar cipher" << endl;
            cout << "   2) steganography: string to image" << endl;
            cout << "   3) string to binary" << endl;
            cout << "   4) Single-Byte XOR" << endl;
            cout << "   5) Multi-Byte XOR" << endl;
            cout << "=======================================================================================================================" << endl;

            cout << "\n\n";
            cout << "\nChoose an option (1, 2, 3, 4, or 5) or type 'exit' to go back: ";
            cin >> encryptionType;
            //
            if (encryptionType == "1")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                                |      ENCRYPTION:      |" << endl;
                cout << "                                                |     CAESAR CIPHER     |" << endl;
                cout << "                                                |_______________________|\n" << endl;

                encryptCaesar();
                cout << "\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            //embeds a message within an image
            else if (encryptionType == "2")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                         |             ENCRYPTION:                |" << endl;
                cout << "                                         |     STEGANOGRAPHY: IMAGE TO STRING     |" << endl;
                cout << "                                         |________________________________________|\n" << endl;

                string filename = "";
                string message = "";
                cout << "Save your image to [project directory] and then" << endl;
                cout << "Enter image filename (with extension): ";
                cin >> filename;
                cout << "Enter the message you want to embed within the image: " << endl;
                cin >> message;

                //STEGANOGRAPHY();

                cout << "\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            //converts string to binary
            else if (encryptionType == "3")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        ENCRYPTION:       |" << endl;
                cout << "                                              |     STRING TO BINARY     |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                stringToBinary();

                cout << "\n\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }
            else if (encryptionType == "4")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        ENCRYPTION:       |" << endl;
                cout << "                                              |     SINGLE BYTE XOR      |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                XOR_ENCRYPT();

                cout << "\n\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }
            else if (encryptionType == "5")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        ENCRYPTION:       |" << endl;
                cout << "                                              |      MULTI-BYTE XOR      |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                XORMULTI();

                cout << "\n\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            //returns to previous menu ("Encryption or Decryption?")
            else if (encryptionType == "exit")
            {
                cout << endl;
                break;
            }

            else
            {
                cout << "invalid input." << endl;
            }

        }

        //Decryption
        else if (encryptOrDecrypt == "D" || encryptOrDecrypt == "d")
        {
            string decryptionType = "";
            cout << "\n=======================================================================================================================" << endl;
            cout << "                                              |     DECRYPTION TYPES:     |" << endl;
            cout << "                                              |___________________________|" << endl;
            cout << "1) caesar cipher" << endl;
            cout << "2) steganography: image to string" << endl;
            cout << "3) binary to string" << endl;
            cout << "4) Single-Byte XOR" << endl;
            cout << "5) Multi-Byte XOR" << endl;
            cout << "=======================================================================================================================" << endl;

            cout << "\n\n";
            cout << "\nChoose an option (1, 2, 3, 4, or 5) or type 'exit' to go back: ";
            cin >> decryptionType;

            //
            if (decryptionType == "1")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                                |      DECRYPTION:      |" << endl;
                cout << "                                                |     CAESAR CIPHER     |" << endl;
                cout << "                                                |_______________________|\n" << endl;
                decryptCaesar();

                cout << "\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            //extracts a message hidden within an image
            else if (decryptionType == "2")
            {
                cout << "\n=======================================================================================================================" << endl;
                cout << "                                         |             DECRYPTION:                |" << endl;
                cout << "                                         |     STEGANOGRAPHY: IMAGE TO STRING     |" << endl;
                cout << "                                         |________________________________________|\n" << endl;

                string filename = "";
                cout << "Save your image to [project directory] and then" << endl;
                cout << "Enter image filename (with extension): ";
                cin >> filename;

                cout << "\n=======================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            //converts binary to string
            else if (decryptionType == "3")
            {

                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        DECRYPTION:       |" << endl;
                cout << "                                              |     BINARY TO STRING     |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                binaryToString();

                cout << "\n========================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }

            else if (decryptionType == "4")
            {

                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        DECRYPTION:       |" << endl;
                cout << "                                              |     SINGLE BYTE XOR      |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                XOR_DECRYPT();

                cout << "\n========================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }
            else if (decryptionType == "5")
            {

                cout << "\n=======================================================================================================================" << endl;
                cout << "                                              |        DECRYPTION:       |" << endl;
                cout << "                                              |      MULTI-BYTE XOR      |" << endl;
                cout << "                                              |__________________________|\n" << endl;

                XORMULTI();

                cout << "\n========================================================================================================================" << endl;
                cout << "\n\n\n\n\n\n\n";
            }
            else if (decryptionType == "exit")
            {
                cout << endl;
                break;
            }

            else
            {
                cout << "invalid input." << endl;
                cin.clear();
                cin.ignore();
            }
        }
    }

    return 0;
}
