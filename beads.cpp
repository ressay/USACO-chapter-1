/*
ID: bourahl1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

int main4()
{
    ifstream fin ;
    fin.open("beads.in");
    ofstream fout("beads.out");
    if(fin.is_open())
    {
        int N;
        fin >> N;
        string s;
        fin >> s;
        int size = 0;
        int i = 0;
        while(i < N &&  s[i] == 'w')i++;
        if(i==N)
        {
            fout << N << endl;
            return 0;
        }
        int start = i;
        char current = s[i++]; // current different of white
        while(i != start && (s[i] == current || s[i] == 'w'))i=(i+1)%N;

        if(i==start)
        {
            fout << N << endl;
            return 0;
        }
        start = i;
        i = (i-1)%N;
        while(i != start && s[i] == 'w')i = (i-1)%N;
        i = (i+1)%N;
        start = i;
        int max = 0;

        int sum=0;
//        cout << "start is: " << start << endl;
        do
        {
            sum = 0;
            cout << "starting from: " << i << endl;
            int start1 = i;
            while(s[i] == 'w')
            {
                sum++;
                i=(i+1)%N;
            }
            current = s[i];
            i++;
            i%=N;
            sum++;

            while(i != start && (s[i] == current || s[i] == 'w'))
            {
                i++;
                i%=N;
                sum++;
            }

            int j = i;
            while(j!=start1 && s[j] == 'w')
            {
                sum++;
                j=(j+1)%N;
            }
            current = s[j];
            cout << "second part from: " << j << endl;
            while(j!=start1 && (s[j] == current || s[j] == 'w'))
            {
                j++;
                j%=N;
                sum++;
            }
            cout << "sum is: " << sum << endl;
            if(sum > max)
                max = sum;

            if(i==start)
                break;
            i = (i-1)%N;
            while(i != start && s[i] == 'w')i = (i-1)%N;
            i = (i+1)%N;
        }while(i!=start);

        fout << max << endl;
    }
    return 0;
}
