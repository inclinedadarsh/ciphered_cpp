#include <iostream>
#include <bitset>
#include <stdexcept>

using namespace std;

class XORCipher
{
private:
    string key;

public:
    XORCipher(const string &binaryKey) : key(binaryKey)
    {
        if (key.find_first_not_of("01") != string::npos)
        {
            throw invalid_argument("Key must be a binary string.");
        }
    }

    string encrypt(const string &text) const
    {
        string result = text;
        const size_t keyLength = key.length();

        for (size_t i = 0; i < result.length(); ++i)
        {
            result[i] ^= key[i % keyLength] - '0'; // Bitwise XOR operation
        }

        return result;
    }

    string decrypt(const string &text) const
    {
        return encrypt(text); // XOR decryption is the same as encryption
    }
};
