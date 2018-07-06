/*
ID: bourahl1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

bool palind1(string s)
{
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != s[s.size()-1-i])
            return false;
    }
    return true;
}

string transform1(int num,int B,char* tab)
{
    string res = "";
    int s=num;
    while(num > 0)
    {
        int r = num % B;
        num/=B;
        res += tab[r];
    }
    string r;
    for (int i = 0; i < res.size(); ++i) {
        r += res[res.size()-1-i];
    }
    return r;
}

int main9()
{
    ifstream fin ;
    ifstream dict;
    fin.open("palsquare.in");
    ofstream fout("palsquare.out");
    if(fin.is_open())
    {

        int B;
        fin >> B;

        char tab[21];
        for (int j = 0; j < 10; ++j) {
            tab[j] = '0' + j;
        }
        for (int i = 10; i < 21; ++i) {
            tab[i] = 'A' + i -10;
        }

        for (int i = 1; i < 301; ++i) {
            string numB = transform1(i*i,B,tab);
            if(palind1(numB))
            {
                fout << transform1(i,B,tab) << " " << numB << endl;
            }
        }
    }
    return 0;
}