/*
ID: bourahl1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

string* rotate90(string* tab,int N)
{
    string* rotated = new string[N];
    for (int k = 0; k < N; ++k) {
        rotated[k] = string(tab[k]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[j][N-1-i] = tab[i][j];
        }
    }

    return rotated;
}

string* rotate180(string* tab,int N)
{
    string* rotated = new string[N];
    for (int k = 0; k < N; ++k) {
        rotated[k] = string(tab[k]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[N-1-i][N-1-j] = tab[i][j];
        }
    }

    return rotated;
}


string* rotate270(string* tab,int N)
{
    string* rotated = new string[N];
    for (int k = 0; k < N; ++k) {
        rotated[k] = string(tab[k]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[N-1-j][i] = tab[i][j];
        }
    }

    return rotated;
}

string* reflection(string* tab,int N)
{
    string* rotated = new string[N];
    for (int k = 0; k < N; ++k) {
        rotated[k] = string(tab[k]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[i][N-1-j] = tab[i][j];
        }
    }

    return rotated;
}

string* applyTransformation(string* tab,int N,int transNum)
{
    switch (transNum)
    {
        case 1:
            return rotate90(tab,N);
        case 2:
            return rotate180(tab,N);
        case 3:
            return rotate270(tab,N);
        case 4:
            return reflection(tab,N);
    }

    return NULL;
}

bool cmp(string* s1,string* s2,int N)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(s1[i][j] != s2[i][j])
                return false;
        }
    }
    return true;
}

void show(string* s,int N)
{
    for (int i = 0; i < N; ++i) {
        cout << s[i] << endl;
    }
}

int main7()
{
    ifstream fin ;
    fin.open("transform.in");
    ofstream fout("transform.out");
    if(fin.is_open())
    {
        int N;
        fin >> N;
        string tab1[N],tab2[N];
        for (int i = 0; i < N; ++i)
            fin >> tab1[i];
        for (int i = 0; i < N; ++i)
            fin >> tab2[i];



        for (int j = 1; j < 5; ++j) {
            string* res = applyTransformation(tab1,N,j);
            show(res,N);
            if(cmp(res,tab2,N))
            {
                fout << j << endl;
                return 0;
            }
        }

        for (int j = 1; j < 4; ++j) {
            string* res = applyTransformation(tab1,N,j);
            res = applyTransformation(res,N,4);
            if(cmp(res,tab2,N))
            {
                fout << 5 << endl;
                return 0;
            }
        }

        for (int j = 1; j < 4; ++j) {
            string* res = applyTransformation(tab1,N,4);
            res = applyTransformation(res,N,j);
            if(cmp(res,tab2,N))
            {
                fout << 5 << endl;
                return 0;
            }
        }

        if(cmp(tab1,tab2,N))
        {
            fout << 6 << endl;
            return 0;
        }

        fout << 7 << endl;
    }
    return 0;
}
