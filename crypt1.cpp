/*
ID: bourahl1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

int getPosition(int number, int pos)
{
    int result = 0;
    while(number > 0 && pos)
    {
        result = number % 10;
        number /= 10;
        pos--;
    }
    return result;
}

bool allIn(int number, int* digits,int N)
{
    while(number > 0)
    {
        int r = number % 10;

        int i = 0;
        for (; i < N; ++i) {
            if(r == digits[i])
                break;
        }
        if(i==N)
            break;
        number/=10;
    }
    return number<=0;
}

int main13()
{
    ifstream fin ;
    ifstream dict;
    fin.open("crypt1.in");
    ofstream fout("crypt1.out");
    if(fin.is_open())
    {

        int N;
        fin >> N;
        int digits[N];
        for (int i = 0; i < N; ++i) {
            fin >> digits[i];
        }
        int count = 0;
        for(int i=111;i<1000;i++)
            if(allIn(i,digits,N))
                for (int j = 11; j < 100; ++j)
                    if(allIn(j,digits,N) && j*i < 10000)

                        if(getPosition(j,1)*i < 1000 && allIn(getPosition(j,1)*i,digits,N) &&
                           getPosition(j,2)*i < 1000 && allIn(getPosition(j,2)*i,digits,N) &&
                           allIn(j*i,digits,N))
                        {
                            count ++;
//                            cout << "found: " << i << " " << j << endl;
//                            cout << "1-" << getPosition(j,1)*i << " 2-" << getPosition(j,2)*i
//                                 << " result: " << j*i << endl;
                        }

        fout << count << endl;
    }
    return 0;
}