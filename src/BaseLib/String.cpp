#include "String.h"
#include <cctype>
#include <sstream>

using namespace std;

namespace BaseLib
{

// Default constructor
String::String()
{
    _Value = "";
}

// Parameterized constructor
String::String(string Value)
{
    _Value = Value;
}

void String::SetValue(string Value)
{
    _Value = Value;
}

string String::GetValue()
{
    return _Value;
}

short String::Length(string S1)
{
    return S1.length();
}

short String::Length()
{
    return _Value.length();
}

short String::CountWords(string S1)
{
    string delim = " "; // delimiter  
    short Counter = 0;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            Counter++;
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        Counter++; // Count the last word
    }

    return Counter;
}

short String::CountWords()
{
    return CountWords(_Value);
}

string String::UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

void String::UpperFirstLetterOfEachWord()
{
    _Value = UpperFirstLetterOfEachWord(_Value);
}

string String::LowerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

void String::LowerFirstLetterOfEachWord()
{
    _Value = LowerFirstLetterOfEachWord(_Value);
}

string String::UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

void String::UpperAllString()
{
    _Value = UpperAllString(_Value);
}

string String::LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

void String::LowerAllString()
{
    _Value = LowerAllString(_Value);
}

char String::InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

string String::InvertAllLettersCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }
    return S1;
}

void String::InvertAllLettersCase()
{
    _Value = InvertAllLettersCase(_Value);
}

short String::CountLetters(string S1, enWhatToCount WhatToCount)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;

        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
    }

    return Counter;
}

short String::CountCapitalLetters(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }
    return Counter;
}

short String::CountCapitalLetters()
{
    return CountCapitalLetters(_Value);
}

short String::CountSmallLetters(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }
    return Counter;
}

short String::CountSmallLetters()
{
    return CountSmallLetters(_Value);
}

short String::CountSpecificLetter(string S1, char Letter, bool MatchCase)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }

    return Counter;
}

short String::CountSpecificLetter(char Letter, bool MatchCase)
{
    return CountSpecificLetter(_Value, Letter, MatchCase);
}

bool String::IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

short String::CountVowels(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }

    return Counter;
}

short String::CountVowels()
{
    return CountVowels(_Value);
}

vector<string> String::Split(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

vector<string> String::Split(string Delim)
{
    return Split(_Value, Delim);
}

string String::TrimLeft(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}

void String::TrimLeft()
{
    _Value = TrimLeft(_Value);
}

string String::TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

void String::TrimRight()
{
    _Value = TrimRight(_Value);
}

string String::Trim(string S1)
{
    return (TrimLeft(TrimRight(S1)));
}

void String::Trim()
{
    _Value = Trim(_Value);
}

string String::JoinString(vector<string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string String::JoinString(string arrString[], short Length, string Delim)
{
    string S1 = "";

    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string String::ReverseWordsInString(string S1)
{
    vector<string> vString;
    string S2 = "";

    vString = Split(S1, " ");

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }

    S2 = S2.substr(0, S2.length() - 1); // Remove the last space

    return S2;
}

void String::ReverseWordsInString()
{
    _Value = ReverseWordsInString(_Value);
}

string String::ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase)
{
    vector<string> vString = Split(S1, " ");

    for (string& s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = sRepalceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sRepalceTo;
            }
        }
    }

    return JoinString(vString, " ");
}

string String::ReplaceWord(string StringToReplace, string sRepalceTo)
{
    return ReplaceWord(_Value, StringToReplace, sRepalceTo);
}

string String::RemovePunctuations(string S1)
{
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }

    return S2;
}

void String::RemovePunctuations()
{
    _Value = RemovePunctuations(_Value);
}

} // namespace BaseLib