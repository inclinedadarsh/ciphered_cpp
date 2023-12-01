#include <iostream>
#include <cctype>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class SubstitutionCipher
{
private:
    mutable unordered_map<char, char> substitutionMap;

public:
    SubstitutionCipher(const string &key)
    {
        if (key.length() != 26)
        {
            throw invalid_argument("Key must be a string of 26 unique letters.");
        }

        for (char ch : key)
        {
            if (!isalpha(ch) || substitutionMap.count(ch) > 0)
            {
                throw invalid_argument("Key must be a string of 26 unique letters.");
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            substitutionMap['a' + i] = tolower(key[i]);
            substitutionMap['A' + i] = toupper(key[i]);
        }
    }

    string encrypt(const string &text) const
    {
        string result = text;

        for (char &ch : result)
        {
            if (isalpha(ch))
            {
                ch = substitutionMap[ch];
            }
        }

        return result;
    }

    string decrypt(const string &text) const
    {
        unordered_map<char, char> reverseMap;

        for (const auto &entry : substitutionMap)
        {
            reverseMap[entry.second] = entry.first;
        }

        string result = text;

        for (char &ch : result)
        {
            if (isalpha(ch))
            {
                ch = reverseMap[ch];
            }
        }

        return result;
    }
};
