#include <iostream>
#include <cctype>

using namespace std;

class ShiftCipher
{
public:
    static string encrypt(const string &text, int key)
    {
        string result = text;

        for (char &ch : result)
        {
            if (isalpha(ch))
            {
                char base = islower(ch) ? 'a' : 'A';
                ch = (ch - base + key + 26) % 26 + base;
            }
        }

        return result;
    }

    static string decrypt(const string &text, int key)
    {
        return encrypt(text, -key); // Corrected decryption handling negative key
    }
};
