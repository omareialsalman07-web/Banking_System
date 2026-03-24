#pragma once
#include <string>
#include <vector>

namespace BaseLib
{
    class String
    {
    private:
        std::string _Value;

    public:
        String();
        String(std::string Value);

        void SetValue(std::string Value);
        std::string GetValue();

        static short Length(std::string S1);
        short Length();

        static short CountWords(std::string S1);
        short CountWords();

        static std::string UpperFirstLetterOfEachWord(std::string S1);
        void UpperFirstLetterOfEachWord();

        static std::string LowerFirstLetterOfEachWord(std::string S1);
        void LowerFirstLetterOfEachWord();

        static std::string UpperAllString(std::string S1);
        void UpperAllString();

        static std::string LowerAllString(std::string S1);
        void LowerAllString();

        static char InvertLetterCase(char char1);

        static std::string InvertAllLettersCase(std::string S1);
        void InvertAllLettersCase();

        enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

        static short CountLetters(std::string S1, enWhatToCount WhatToCount = enWhatToCount::All);

        static short CountCapitalLetters(std::string S1);
        short CountCapitalLetters();

        static short CountSmallLetters(std::string S1);
        short CountSmallLetters();

        static short CountSpecificLetter(std::string S1, char Letter, bool MatchCase = true);
        short CountSpecificLetter(char Letter, bool MatchCase = true);

        static bool IsVowel(char Ch1);

        static short CountVowels(std::string S1);
        short CountVowels();

        static std::vector<std::string> Split(std::string S1, std::string Delim);
        std::vector<std::string> Split(std::string Delim);

        static std::string TrimLeft(std::string S1);
        void TrimLeft();

        static std::string TrimRight(std::string S1);
        void TrimRight();

        static std::string Trim(std::string S1);
        void Trim();

        static std::string JoinString(std::vector<std::string> vString, std::string Delim);
        static std::string JoinString(std::string arrString[], short Length, std::string Delim);

        static std::string ReverseWordsInString(std::string S1);
        void ReverseWordsInString();

        static std::string ReplaceWord(std::string S1, std::string StringToReplace, std::string sRepalceTo, bool MatchCase = true);
        std::string ReplaceWord(std::string StringToReplace, std::string sRepalceTo);

        static std::string RemovePunctuations(std::string S1);
        void RemovePunctuations();
    };
}