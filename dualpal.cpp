/*
ID: bourahl1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

bool palind(string s)
{
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != s[s.size()-1-i])
            return false;
    }
    return true;
}

string transform(int num,int B,char* tab)
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

int main10()
{
    ifstream fin ;
    ifstream dict;
    fin.open("dualpal.in");
    ofstream fout("dualpal.out");
    if(fin.is_open())
    {

        int N,S;
        fin >> N >> S;

        char tab[21];
        for (int j = 0; j < 10; ++j) {
            tab[j] = '0' + j;
        }
        for (int i = 10; i < 21; ++i) {
            tab[i] = 'A' + i -10;
        }
        S++;
        int all = 0;
        while(N)
        {
            int found=0;
            for (int i = 2; i < 11 && found <2; ++i) {
                string num = transform(S,i,tab);
                if(palind(num))
                {
                    found++;
                }
            }
            if(found >=2) {
                fout << S << endl;
                N--;
            }
            S++;
        }
    }
    return 0;
}