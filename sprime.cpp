/*
ID: bourahl1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>

using namespace std;


ofstream fout1;

bool prime2(int N)
{
    int sqr = (int)sqrt(N);
    if(!(N%2)) return false;
    for (int i = 3; i <= sqr; i+=2) {
        if(!(N%i))
        {
            return false;
        }
    }
    return true;
}

void genPrimes(int N,int* primes,int size)
{
    if(primes == NULL)
    {
        int p[4] = {2,3,5,7};
        primes = p;
        genPrimes(--N,primes,4);
    }
    else if(N>0)
    {
        int p[5*size];
        int newSize = 0;
        for (int i = 0; i < size; ++i) {
            int num = primes[i]*10;
            for (int j = 1; j < 10; j+=2) {
                if(prime2(num+j))
                    p[newSize++] = num+j;
            }
        }
        primes = p;
        genPrimes(--N,primes,newSize);
    }
    else
    {
        for (int i = 0; i < size; ++i) {
            fout1 << primes[i]<< endl;
        }
    }
}

int main25()
{
    ifstream fin;
    fin.open("sprime.in");
    fout1.open("sprime.out");
    if(fin.is_open())
    {
        int N;
        fin >> N;
        genPrimes(N,NULL,0);
    }
    return 0;
}