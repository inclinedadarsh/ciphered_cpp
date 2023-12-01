#include <iostream>
#include <stdexcept>
#include "ShiftCipher.h"        // Include the ShiftCipher class header file
#include "SubstitutionCipher.h" // Include the SubstitutionCipher class header file
#include "XORCipher.h"          // Include the XORCipher class header file

using namespace std;

int main()
{
    do
    {
        int operationChoice;
        int algorithmChoice;

        cout << "Choose operation:\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> operationChoice;

        if (operationChoice == 1 || operationChoice == 2)
        {
            cout << "Choose algorithm:\n";
            cout << "1. Shift Cipher\n";
            cout << "2. Substitution Cipher\n";
            cout << "3. XOR Cipher\n";
            cout << "Enter your choice: ";
            cin >> algorithmChoice;
        }
        else if (operationChoice == 3)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cerr << "Invalid operation. Please try again.\n";
            continue;
        }

        try
        {
            switch (operationChoice)
            {
            case 1: // Encrypt
                switch (algorithmChoice)
                {
                case 1:
                {
                    int key;
                    string text;

                    cout << "Enter shift key: ";
                    cin >> key;

                    cin.ignore(); // Consume the newline character
                    cout << "Enter text: ";
                    getline(cin, text);

                    string encrypted = ShiftCipher::encrypt(text, key);

                    cout << "Encrypted: " << encrypted << "\n";
                    break;
                }
                case 2:
                {
                    string key;
                    string text;

                    cout << "Enter substitution key (26 unique letters): ";
                    cin >> key;

                    try
                    {
                        SubstitutionCipher substitutionCipher(key);

                        cin.ignore(); // Consume the newline character
                        cout << "Enter text: ";
                        getline(cin, text);

                        string encrypted = substitutionCipher.encrypt(text);

                        cout << "Encrypted: " << encrypted << "\n";
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "Error: " << e.what() << "\n";
                    }

                    break;
                }
                case 3:
                {
                    string binaryKey;
                    string text;

                    cout << "Enter binary key: ";
                    cin >> binaryKey;

                    try
                    {
                        XORCipher xorCipher(binaryKey);

                        cin.ignore(); // Consume the newline character
                        cout << "Enter text: ";
                        getline(cin, text);

                        string encrypted = xorCipher.encrypt(text);

                        cout << "Encrypted: " << encrypted << "\n";
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "Error: " << e.what() << "\n";
                    }

                    break;
                }
                default:
                    cerr << "Invalid algorithm choice. Please try again.\n";
                }
                break;
            case 2: // Decrypt
                switch (algorithmChoice)
                {
                case 1:
                {
                    int key;
                    string text;

                    cout << "Enter shift key: ";
                    cin >> key;

                    cin.ignore(); // Consume the newline character
                    cout << "Enter text: ";
                    getline(cin, text);

                    string decrypted = ShiftCipher::decrypt(text, key);

                    cout << "Decrypted: " << decrypted << "\n";
                    break;
                }
                case 2:
                {
                    string key;
                    string text;

                    cout << "Enter substitution key (26 unique letters): ";
                    cin >> key;

                    try
                    {
                        SubstitutionCipher substitutionCipher(key);

                        cin.ignore(); // Consume the newline character
                        cout << "Enter text: ";
                        getline(cin, text);

                        string decrypted = substitutionCipher.decrypt(text);

                        cout << "Decrypted: " << decrypted << "\n";
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "Error: " << e.what() << "\n";
                    }

                    break;
                }
                case 3:
                {
                    string binaryKey;
                    string text;

                    cout << "Enter binary key: ";
                    cin >> binaryKey;

                    try
                    {
                        XORCipher xorCipher(binaryKey);

                        cin.ignore(); // Consume the newline character
                        cout << "Enter text: ";
                        getline(cin, text);

                        string decrypted = xorCipher.decrypt(text);

                        cout << "Decrypted: " << decrypted << "\n";
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "Error: " << e.what() << "\n";
                    }

                    break;
                }
                default:
                    cerr << "Invalid algorithm choice. Please try again.\n";
                }
                break;
            default:
                cerr << "Invalid operation choice. Please try again.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
        }

    } while (true);

    return 0;
}
