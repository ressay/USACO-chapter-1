/*
ID: bourahl1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

bool within(int number,int range,int N)
{
    int diff = (number>range)?(number-range):range-number;
    return diff < 3 || diff > N-3;
}

int main14()
{
    ifstream fin ;
    ifstream dict;
    fin.open("combo.in");
    ofstream fout("combo.out");
    if(fin.is_open())
    {

        int N;
        fin >> N;
        int farmer[3], master[3], diff[3];
        int count = 0;
        for (int j = 0; j < 3; ++j) {
            fin >> farmer[j];
        }

        for (int j = 0; j < 3; ++j) {
            fin >> master[j];
        }
        if(N > 5) {

            count = 250;
            for (int i = 0; i < 3; ++i)
                diff[i] = (master[i] > farmer[i]) ? (master[i] - farmer[i]) : (farmer[i] - master[i]);
            for (int i = 0; i < 3; ++i) {
                if (diff[i] > N - 5)
                    diff[i] = N - diff[i];
                diff[i] = 5 - diff[i];
            }
            int minus = 1;
            for (int i = 0; i < 3; ++i) {
                minus *= diff[i];
            }
            if (minus > 0)
                count -= minus;
        }
        else
        {
            int done[N][N][N];
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int k = 0; k < N; ++k) {
                        done[i][j][k] = false;
                    }
                }
            }
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int k = 0; k < N; ++k) {
                        if((within(i,farmer[0],N) && within(j,farmer[1],N) && within(k,farmer[2],N)) ||
                           ((within(i,master[0],N) && within(j,master[1],N) && within(k,master[2],N))))
                            if(!done[i][j][k])
                            {
                                count++;
                                done[i][j][k] = true;
                            }
                    }
                }
            }
        }

        fout << count << endl;
    }
    return 0;
}