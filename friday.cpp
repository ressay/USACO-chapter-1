/*
ID: bourahl1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;


bool isLeap(int year)
{
    year += 1900;
    return (!(year%100) && !(year%400)) || (year%100 && !(year%4));
}

int main3()
{
    ifstream fin ;
    fin.open("friday.in");
    ofstream fout("friday.out");
    if(fin.is_open())
    {
        //35 34 34 35 33 35 34
        int N;
        fin >> N;
        int days[7] = {1,0,0,0,0,0,0};
        int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int current = 0; // 13/01/1900 is saturday
        for(int i=0;i<N;i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if(j == 1 && isLeap(i)) {
                    current += months[j] + 1;
                }
                else
                    current += months[j];


                current = current % 7;
//                cout << "adding to " << current << endl;
                days[current] += 1;
            }
            if(i == N-1)
                break;
            current += months[11];
            current = current % 7;
//            cout << "adding to " << current << endl;
            days[current] += 1;

        }
        fout << days[0];
        for (int k = 1; k < 7; k++) {
            fout << " " << days[k] ;
        }
        fout << endl;
    }
    return 0;
}