/*
ID: bourahl1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;


int main2()
{
    ifstream fin ;
    fin.open("gift1.in");
    ofstream fout("gift1.out");
    if(fin.is_open())
    {
        int NP;
        fin >> NP;
        string members[NP];
        map<string,int> mems;
        for(int i=0;i<NP;i++) {
            fin >> members[i];
            mems.insert(std::pair<string,int>(members[i],0));
        }

        for(int i=0;i<NP;i++)
        {
            string name;
            fin >> name;
            int initial,numP;
            fin >> initial >> numP;
            if(numP > 0)
            {
                int due = initial / numP;
                mems[name] += initial % numP - initial;
                for (int j = 0; j < numP; j++) {
                    string receiver;
                    fin >> receiver;
                    mems[receiver] += due;
                }
            } else
                mems[name] += initial;
        }

        for (int k = 0; k < NP; k++) {
            fout << members[k] << " " << mems[members[k]] << endl;
        }
    }
    return 0;
}