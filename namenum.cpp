/*
ID: bourahl1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

bool acceptable(string name,string N,char ** tab)
{


    if(name.size()!=N.size()) return false;

    for (int k = 0; k < name.size(); ++k) {
        bool found = false;
        for (int i = 0; i < 3; ++i) {
            if(name[k] == tab[N[k]-'2'][i]) {
                found = true;
                break;
            }
        }
        if(!found)
            return false;
    }
    return true;
}

int main8()
{
    ifstream fin ;
    ifstream dict;
    dict.open("dict.txt");
    fin.open("namenum.in");
    ofstream fout("namenum.out");
    if(fin.is_open())
    {

        string N;
        fin >> N;
        string name;

        char** tab= new char*[8];
        for (int i = 0; i < 8; ++i) {
            tab[i] = new char[3];
            for (int j = 0; j < 3; ++j) {
                if('A' + i*3+j < 'Q') {
                    tab[i][j] = 'A' + i * 3 + j;

                }
                else{
                    tab[i][j] = 'A' + i*3+j+1;
                }
            }
        }

        int one = 0;

        while(dict >> name)
        {
            if(acceptable(name,N,tab)) {
                one = 1;
                fout << name << endl;
            }
        }

        if(!one)
            fout << "NONE" << endl;
    }
    return 0;
}