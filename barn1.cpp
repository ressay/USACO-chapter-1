/*
ID: bourahl1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

int main12()
{
    ifstream fin ;
    ifstream dict;
    fin.open("barn1.in");
    ofstream fout("barn1.out");
    if(fin.is_open())
    {

        int M,S,C;
        fin >> M >> S >> C;
        int stalls[C];
        bool exists[S+1];
        for (int i = 0; i < S+1; ++i) {
            exists[i] = false;
        }

        for (int i = 0; i < C; ++i) {
            fin >> stalls[i];
            exists[stalls[i]] = true;
        }
        int r=1;
        while(!exists[r])r++;
        int start = r;
        int num = r-1;
        r=S;
        while(!exists[r])r--;
        int end = r;
        num += S-r;

        int sequences[S];
        for (int i = 0; i < S; ++i) {
            sequences[i] = 0;
        }
        int count=0;
        int cp = 0;
        for (int i = start+1; i < end+1; ++i) {
            cout << i << " is " << exists[i] << endl;
            if(!exists[i])
            {
                cp++;
            }
            else if(cp > 0)
            {
                cout << "sequence " << count << ": " << cp << endl;
                sequences[count] = cp;
                count++;
                cp = 0;
            }
        }

        for (int i = 0; i < count; ++i) {
            int min = sequences[i];
            int k = i;
            for (int j = i+1; j < count; ++j)
                if(min < sequences[j])
                {
                    min = sequences[j];
                    k = j;
                }
            sequences[k] = sequences[i];
            sequences[i] = min;
        }

        for (int i = 0; i < M-1 && i < count; ++i) {
            num += sequences[i];
            cout << sequences[i] << endl;
        }
        fout << S - num << endl;
    }
    return 0;
}