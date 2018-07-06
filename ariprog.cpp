/*
ID: bourahl1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cmath>
#include "map"

using namespace std;

int* sort(int** tab,int M,int* size)
{
    int* sorted = new int[(M*(M+1))/2];
    int index[M];


    for (int i = 0; i < M; ++i) {
        index[i] = 0;
    }
    int iSorted = 0;
    for(;;)
    {
        bool out = true;
        for (int i = 0; i < M; ++i)
        {
            if(index[i] < i+1)
                out = false;
        }

        if(out) break;
        int k=0;
        while(index[k] >= k+1)k++;
        int min = tab[k][index[k]];
        int temp = k;
        for (int i = 1; i < M; ++i) {
            if(index[i] < i+1)
                if(tab[i][index[i]] < min)
                {
                    min = tab[i][index[i]];
                    temp = i;
                }
        }

        for (int i = 0; i < M; ++i) {
            if(index[i] < i+1 && i!=temp)
                if(tab[i][index[i]] == min)
                {
                    index[i]++;
                }
        }

//        cout << "found min = " << min << endl;
        index[temp]++;
        sorted[iSorted] = min;
        iSorted++;

    }
    *size = iSorted;
    return sorted;
}

int main21()
{
    ifstream fin ;
    ifstream dict;
    fin.open("ariprog.in");
    ofstream fout("ariprog.out");
    if(fin.is_open())
    {

        int N,M;
        fin >> N;
        fin >> M;
        int** tab = new int*[M+1];
        for (int i = 0; i < M+1; ++i) {
            tab[i] = new int[M+1];
        }

        // calculating all bisquares
        for (int i = 0; i < M+1; ++i) {
            for (int j = 0; j < i+1; ++j) {
                tab[i][j] = i*i+j*j;
//                cout << tab[i][j] << " ";
            }
//            cout << endl;
        }
        int size;
        // sorting all bisquares
        int* qxp = sort(tab,M+1,&size);
        int diff[size];
        for (int i = 0; i < size; ++i) {
//            cout << qxp[i] << " ";
            if(i<size-1)
                diff[i] = qxp[i+1] - qxp[i];
        }
//        cout << endl;
        int maxDifference = qxp[size-1] - qxp[0];
        int max = qxp[size-1];
        bool exist[max+1];
        // exist will help to know if a number l is a bisquare or not
        for (int l = 0; l < max+1; ++l) {
            exist[l] = false;
        }
        // we put all bisquares to true in exist array
        for (int l = 0; l < size; ++l) {
            exist[qxp[l]] = true;
        }
        bool found = false;
        maxDifference /= (N-1);
        maxDifference ++;
        // each iteration will calculate all sequences with the difference between two consecutive elements equal to i
        for (int i = 1; i < maxDifference; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                // we look for sequences of difference i starting from element j of q*q+p*p
                int start = qxp[j];
                int sequenceSize = 1;
                // next element's value
                int next = start + i;
                while (next <= max && exist[next])
                {
                    sequenceSize++;
                    next += i;
                    if(sequenceSize==N)
                        break;
                }

                if(sequenceSize == N) {
                    found = true;
                    fout << start << " " << i << endl;
                }
            }
        }
        if(!found)
            fout << "NONE" << endl;

        cout << endl;
    }
    return 0;
}