/*
ID: bourahl1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

int main6()
{
    ifstream fin ;
    fin.open("milk2.in");
    ofstream fout("milk2.out");
    if(fin.is_open())
    {
        int N;
        fin >> N;
        int tab1[N];
        int tab2[N];
        for (int i = 0; i < N; ++i) {
            fin >> tab1[i] >> tab2[i];
        }
        // order tabs
        for (int j = 0; j < N; ++j) {
            int min = tab1[j];
            int l=j;
            for (int k = j+1; k < N; ++k)
                if(tab1[k] < min)
                {
                    l = k;
                    min = tab1[k];
                }
            tab1[l] = tab1[j];
            tab1[j] = min;
            min = tab2[j];
            tab2[j] = tab2[l];
            tab2[l] = min;
        }
        int res1=0,res2=0;

        for (int i = 0; i < N; ++i)
        {
            int j=0;
            int max = tab2[i];
            while(j<N && tab1[j]<=max)
            {
                if(tab2[j] > max)
                    max = tab2[j];
                j++;
            }
            if(res1<max-tab1[i])
                res1 = max-tab1[i];
            if(j != N)
            if(res2<tab1[j]-max)
                res2 = tab1[j]-max;
        }
        fout << res1 << " " << res2 << endl;
    }
    return 0;
}
