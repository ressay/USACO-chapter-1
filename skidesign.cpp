/*
ID: bourahl1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cmath>
#include "map"

using namespace std;

int calculatePrice(int* hills,int N,int borderMin,int borderMax)
{
    int price = 0;
    for (int i = 0; i < N; ++i)
    {
        if(hills[i] < borderMin)
            price += (borderMin-hills[i])*(borderMin-hills[i]);
        else if(hills[i] > borderMax)
            price += (hills[i] - borderMax)*(hills[i] - borderMax);
    }
    return price;
}

int main20()
{
    ifstream fin ;
    ifstream dict;
    fin.open("skidesign.in");
    ofstream fout("skidesign.out");
    if(fin.is_open())
    {

        int N;
        fin >> N;
        int hills[N];
        for (int i = 0; i < N; ++i) {
            fin >> hills[i];
        }


        int min = hills[0],max = hills[0];

        for (int i = 1; i < N; ++i) {
            if(min > hills[i])
                min = hills[i];

            if(max < hills[i])
                max = hills[i];

        }

        int minPrice = calculatePrice(hills,N,min,min+17);

        for (int i = min+1; i < max - 17; ++i)
        {
            int borderMin = i,borderMax = i+17;
            int pr = calculatePrice(hills,N,borderMin,borderMax);
            if(pr < minPrice)
                minPrice = pr;
        }
        fout << minPrice << endl;
        cout << minPrice << endl;
    }
    return 0;
}