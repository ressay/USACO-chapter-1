/*
ID: bourahl1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>

using namespace std;

bool prime(int N)
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

int reverse(int number)
{
    int result = 0;
    while(number >0)
    {
        int r = number%10;
        number /= 10;
        result*=10;
        result+=r;
    }
    return result;
}

int length(int number)
{
    int length = 0;
    for (; number > 0; number/=10,length++);
    return length;
}
int main24()
{
    ifstream fin ;
    ofstream fout;
    fin.open("pprime.in");
    fout.open("pprime.out");
    if(fin.is_open())
    {

        int a,b;
        fin >> a >> b;
        int primes[1000000];
        int iP = 0;
        primes[iP++] = 5;
        primes[iP++] = 7;
        int minSize = length(a);
        int maxSize = length(b);
        if(minSize < 2) minSize = 2;
        // max length of the integer is 8 digits
        for (int i = minSize; i < maxSize+1; ++i) {
            // we generate palindrome numbers
            int max = 1;
            for (int j = 0; j < i/2; ++j) {
                max*=10;
            }
            for (int k = 1; k < max; ++k)
            {
                if(k%10 == 0) continue;
                int reversed = reverse(k);

                int fixSize = length(max) - length(reversed)-1;
                for (int l = 0; l < fixSize; ++l,reversed*=10);

                if(i%2)
                {
                    int number = reversed*max*10 + k;
                    for (int j = 0; j < 10; ++j) {
                        number += j*max;
                        if(prime(number))
                            primes[iP++] = number;
                        number -= j*max;
                    }
                }
                else
                {
                    int number = reversed*max + k;
                    if(prime(number))
                        primes[iP++] = number;
                }
            }
        }
        // sorting primes array
        for (int i = 0; i < iP; ++i) {
            int min = primes[i];
            int k = i;
            for (int j = i+1; j < iP; ++j) {
                if(min > primes[j])
                {
                    min = primes[j];
                    k = j;
                }
            }
            primes[k] = primes[i];
            primes[i] = min;
        }

        for (int i = 0; i < iP; ++i)
        if(primes[i] >= a && primes[i] <= b)
            fout << primes[i] << endl;
    }
    return 0;
}