#include "Util.h"
#include <ctime>

using namespace std;

namespace BaseLib
{

void Util::Srand()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
}

int Util::RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char Util::GetRandomCharacter(enCharType CharType)
{
    // Updated this method to accept mixchars
    if (CharType == MixChars)
    {
        // Capital/Small/Digits only
        CharType = (enCharType)RandomNumber(1, 3);
    }

    switch (CharType)
    {
    case enCharType::SamallLetter:
        return char(RandomNumber(97, 122));
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
    case enCharType::Digit:
        return char(RandomNumber(48, 57));
    default:
        return char(RandomNumber(65, 90));
    }
}

string Util::GenerateWord(enCharType CharType, short Length)
{
    string Word;

    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }

    return Word;
}

string Util::GenerateKey(enCharType CharType)
{
    string Key = "";
    Key = GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4) + "-";
    Key = Key + GenerateWord(CharType, 4);

    return Key;
}

void Util::GenerateKeys(short NumberOfKeys, enCharType CharType)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey(CharType) << endl;
    }
}

void Util::FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(From, To);
}

void Util::FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateWord(CharType, Wordlength);
}

void Util::FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey(CharType);
}

void Util::Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Util::Swap(double& A, double& B)
{
    double Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Util::Swap(bool& A, bool& B)
{
    bool Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Util::Swap(char& A, char& B)
{
    char Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Util::Swap(string& A, string& B)
{
    string Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Util::Swap(Date& A, Date& B)
{
    Date::SwapDates(A, B);
}

void Util::ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

void Util::ShuffleArray(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

string Util::Tabs(short NumberOfTabs)
{
    string t = "";

    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
    }

    return t;
}

string Util::EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

string Util::DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

} // namespace BaseLib