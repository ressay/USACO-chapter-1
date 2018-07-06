/*
ID: bourahl1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;




int main23()
{

    ifstream fin ;
    ofstream fout;
    fin.open("numtri.in");
    fout.open("numtri.out");
    if(fin.is_open())
    {

        int R;
        fin >> R;
        int** rows = new int*[R];
        int** sums = new int*[R];
        for (int i = 0; i < R; ++i) {
            rows[i] = new int[i+1];
            sums[i] = new int[i+1];
            for (int j = 0; j < i+1; ++j) {
                fin >> rows[i][j];
                sums[i][j] = 0;
            }
        }
        sums[0][0] = rows[0][0];
        for (int i = 1; i < R; ++i) {
            sums[i][0] = rows[i][0] + sums[i-1][0];
            sums[i][i] = rows[i][i] + sums[i-1][i-1];
//            cout << sums[i][0] << " " ;
            for (int j = 1; j < i; ++j) {
                sums[i][j] = (sums[i-1][j-1]>sums[i-1][j]) ? (rows[i][j] + sums[i-1][j-1]) : (rows[i][j] + sums[i-1][j]);
//                cout << sums[i][j] << " ";
            }
//            cout << sums[i][i] << endl;
        }
        int max = sums[R-1][0];
        for (int i = 1; i < R; ++i) {
            if(sums[R-1][i] > max)
                max = sums[R-1][i];
        }

        fout << max << endl;
//        cout << max << endl;

    }
    return 0;
}