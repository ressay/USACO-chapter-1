/*
ID: bourahl1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

int main11()
{
    ifstream fin ;
    ifstream dict;
    fin.open("milk.in");
    ofstream fout("milk.out");
    if(fin.is_open())
    {

        int N,M;
        fin >> N >> M;
        int prices[M],units[M];
        for (int i = 0; i < M; ++i) {
            fin >> prices[i] >> units[i] ;
        }

        for (int i = 0; i < M; ++i) {
            int min = prices[i];
            int k = i;
            for (int j = i+1; j < M; ++j)
                if(min > prices[j])
                {
                    min = prices[j];
                    k = j;
                }
            prices[k] = prices[i];
            prices[i] = min;
            min = units[k];
            units[k] = units[i];
            units[i] = min;
        }
        int finalPrice = 0;
        for (int i = 0; i < M && N > 0; ++i) {
            if(N > units[i])
            {
                N -= units[i];
                finalPrice += units[i]*prices[i];
            }
            else
            {
                finalPrice += N*prices[i];
                N=0;
            }
        }

        fout << finalPrice << endl;
    }
    return 0;
}