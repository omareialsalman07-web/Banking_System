#pragma once
#include <iostream>
#include <string>
#include "Date_Time/Date.h"

using namespace std;

namespace BaseLib
{

class Util
{
public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void Srand();
    static int RandomNumber(int From, int To);
    static char GetRandomCharacter(enCharType CharType);
    static string GenerateWord(enCharType CharType, short Length);
    static string GenerateKey(enCharType CharType = CapitalLetter);
    static void GenerateKeys(short NumberOfKeys, enCharType CharType);
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To);
    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength);
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType);
    
    static void Swap(int& A, int& B);
    static void Swap(double& A, double& B);
    static void Swap(bool& A, bool& B);
    static void Swap(char& A, char& B);
    static void Swap(string& A, string& B);
    static void Swap(Date& A, Date& B);
    
    static void ShuffleArray(int arr[100], int arrLength);
    static void ShuffleArray(string arr[100], int arrLength);
    static string Tabs(short NumberOfTabs);
    
    static string EncryptText(string Text, short EncryptionKey);
    static string DecryptText(string Text, short EncryptionKey);
};

} // namespace BaseLib