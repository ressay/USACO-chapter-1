/*
ID: bourahl1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main1()
{
    ifstream fin ;
    fin.open("ride.in");
    ofstream fout("ride.out");
    string a, b;
    if(fin.is_open())
    {
        fin >> a >> b;
        int p1 = 1,p2 = 1, res;
        for(int i=0;i<a.size();i++)
            p1 *= (a[i]-'A'+1);
        for(int i=0;i<b.size();i++)
            p2 *= (b[i]-'A'+1);
        cout << p1 << endl << p2 << endl;
        if(p1<p2) res = p2-p1;
        else res = p1-p2;
        if(res%47)
            fout << "STAY" << endl;
        else
            fout << "GO" << endl;
    }
    return 0;
}