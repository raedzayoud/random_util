#pragma once

#include <iostream>
#include<random>
#include <ctime>
using namespace std;

class clsutil
{

public:

    enum enchoix {
        CapitalLetter = 1, SamallLetter = 2, Digit = 3, SpecialCharacter
        = 4, mixchar = 5
    };

    static void srand() {
        ::srand(static_cast<unsigned int>(time(NULL)));
    }

    static int RandNumber(int from, int to) {
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static void swap1(int& x, int& y) {
        int aux = x;
        x = y;
        y = aux;
    }

    static char GetRandomCharacter(enchoix CharType) {

        if (CharType == enchoix::mixchar) {
            CharType = (enchoix)RandNumber(1, 3);
        }

        switch (CharType)
        {

        case enchoix::SamallLetter:
        {
            return char(RandNumber(97, 122));
            break;
        }
        case enchoix::CapitalLetter:
        {
            return char(RandNumber(65, 90));
            break;
        }
        case enchoix::SpecialCharacter:
        {
            return char(RandNumber(33, 47));
            break;
        }
        case enchoix::Digit:
        {
            return char(RandNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandNumber(65, 90));
            break;
        }

        // Gérer d'autres cas si nécessaire
        return '\0'; // Caractère nul par défaut, vous pouvez le changer selon votre logique
        }
    }

    static string GenerateWord(enchoix c, int length) {
        string s;
        for (int i = 0; i < length; i++) {
            s += clsutil::GetRandomCharacter(c);
        }
        return s;
    }

    static string chaineRandom(enchoix c1) {
        string s = "";
        for (int i = 0; i < 4; i++) {
            char c = GetRandomCharacter(c1);
            s += c;
        }
        return s;
    }

    static char c() {
        return '-';
    }

    static string GenerateKey(enchoix s) {
        string chaine = "";
        for (int i = 0; i < 4; i++) {
            chaine += chaineRandom(s) + c();
        }
        return chaine;

    }

    static string GenerateKeys(int x, enchoix c) {
        string s1;
        string s;
        for (int i = 0; i < x; i++) {
            s = GenerateKey(c);
            for (int i = 0; i < s.size() - 2; i++) {
                s1 += s[i];
            }
            cout << "the Key" << "[" << i << "]" << " " << s1 << endl;
            s1 = "";
            s = "";

        }
    }

    static void swap1(double& x, double& y) {
        double aux = x;
        x = y;
        y = aux;


    }

    static void swap1(string& x, string& y) {
        string aux = x;
        x = y;
        y = aux;
    }

    static void filarraywithrandomnumber(int arr[100], int lenght, int x, int y) {
        for (int i = 0; i < lenght; i++) {
            arr[i] = RandNumber(x, y);
        }

    }

    static void filarraywithrandomword(string arr[100], int lenght, enchoix c, int y) {
        for (int i = 0; i < lenght; i++) {
            arr[i] = GenerateWord(c, y);
        }

    }

    static string Tabs(int x) {
        string t;
        for (int i = 0; i < x; i++) {
            t += "\t";
        }
        return t;
    }

    static int shuffletab(int arr[100], int length) {
        for (int i = 0; i < length; i++) {
            swap(arr[RandNumber(1, length) - 1], arr[RandNumber(1, length) - 1]);
        }
    }



};