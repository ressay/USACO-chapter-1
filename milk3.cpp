/*
ID: bourahl1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

ifstream fin ;
ifstream dict;
ofstream fout;
bool*** done;
vector<int> found;

void bTob(int* b1,int* b2)
{
    if(b1[1] == 0) return; // bucket1 contains nothing
    if(b2[0] == b2[1]) return; // bucket2 is full
    if(b1[1] > b2[0] - b2[1]) // bucket1 contains more than what's left empty in bucket2
    {
        int transfered = b2[0] - b2[1];
        b1[1] -= transfered;
        b2[1] = b2[0];
    }
    else
    {
        b2[1] += b1[1];
        b1[1] = 0;
    }
}
void recursive(int* A,int* B, int* C)
{
//    cout << A[1] << " " << B[1] << " " << C[1] << endl;
    if(done[A[1]][B[1]][C[1]])
        return;
    done[A[1]][B[1]][C[1]] = true;
    if(!A[1])
    {
        int size = found.size();
        int i = 0;
        for (; i < size && found[i] < C[1]; ++i);
        found.insert(found.begin()+i,C[1]);
    }
    if(A[1] > 0) // A contains milk
    {
        int A2[2] = {A[0],A[1]};
        int B2[2] = {B[0],B[1]};
        int C2[2] = {C[0],C[1]};
        bTob(A2,B2);
        recursive(A2,B2,C2);
        int A3[2] = {A[0],A[1]};
        int B3[2] = {B[0],B[1]};
        int C3[2] = {C[0],C[1]};
        bTob(A3,C3);
        recursive(A3,B3,C3);
    }
    if(B[1] > 0) // B contains milk
    {
        int A2[2] = {A[0],A[1]};
        int B2[2] = {B[0],B[1]};
        int C2[2] = {C[0],C[1]};
        bTob(B2,A2);
        recursive(A2,B2,C2);
        int A3[2] = {A[0],A[1]};
        int B3[2] = {B[0],B[1]};
        int C3[2] = {C[0],C[1]};
        bTob(B3,C3);
        recursive(A3,B3,C3);
    }
    if(C[1] > 0) // C contains milk
    {
        int A2[2] = {A[0],A[1]};
        int B2[2] = {B[0],B[1]};
        int C2[2] = {C[0],C[1]};
        bTob(C2,B2);
        recursive(A2,B2,C2);
        int A3[2] = {A[0],A[1]};
        int B3[2] = {B[0],B[1]};
        int C3[2] = {C[0],C[1]};
        bTob(C3,A3);
        recursive(A3,B3,C3);
    }

}

int main22()
{

    fin.open("milk3.in");
    fout.open("milk3.out");
    if(fin.is_open())
    {

        int A,B,C;
        fin >> A >> B >> C;
        done = new bool**[A+1];
        for (int i = 0; i < A+1; ++i) {
            done[i] = new bool*[B+1];
            for (int j = 0; j < B+1; ++j) {
                done[i][j] = new bool[C+1];
                for (int k = 0; k < C+1; ++k) {
                    done[i][j][k] = false;
                }
            }
        }

        int A1[2] = {A,0};
        int B1[2] = {B,0};
        int C1[2] = {C,C};
        recursive(A1,B1,C1);
        int size = found.size();

        fout << found[0];
        for (int l = 1; l < size; ++l) {
            fout << " " << found[l];
        }
        fout << endl;

    }
    return 0;
}