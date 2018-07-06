/*
ID: bourahl1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "map"

using namespace std;

class position
{

public:
    int indice=0;
    static int i;
    int x,y;
    position(int x,int y)
    {
        indice = ++i;
        this->x = x;
        this->y = y;
    }
};
int position::i = 0;

bool simulateLoop(position** positions, int N)
{
    for (int i = 0; i < N; i++)
    {
        position* pos = positions[i];
        int min = 2000000000;
        position* next = NULL;
        for (int j = 0; j < N; ++j) {
            if(i != j && positions[j]->y == pos->y && positions[j]->x > pos->x && positions[j]->x < min) {
                if (j % 2)
                    next = positions[j - 1];
                else
                    next = positions[j + 1];
                min = positions[j]->x;
            }
        }
        while(next != NULL && next != pos)
        {
//            cout << "in " << next->indice << endl;
            position* prev = next;
            next = NULL;
            min = 2000000000;
            for (int j = 0; j < N; ++j) {
                if (positions[j]->y == prev->y && positions[j]->x > prev->x && positions[j]->x < min) {
                    if (j % 2)
                        next = positions[j - 1];
                    else
                        next = positions[j + 1];
                    min = positions[j]->x;
                }
            }
        }
        if(next == pos) {
//            cout << "found one!" << endl;
//            for (int j = 0; j < N-1; j+=2) {
//                cout << "pos " << positions[j]->indice << " with " << positions[j+1]->indice << endl;
//            }
            return true;
        }
    }
    return false;
}

void getNumberOfLoops(position** positions,position** left, int Nleft,int N,int* count)
{
    position* pos = left[0];
    position* mem[Nleft];
    for (int i = 0; i < Nleft; ++i) {
        mem[i] = left[i];
    }
    for (int i = 1; i < Nleft; ++i) {
        position* p = left[i];
        left[i] = left[1];
        left[1] = p;
        if(Nleft == 2) {
//            cout << "simulation!" << endl;
            if (simulateLoop(positions, N))
                *count = *count + 1;
            for (int i = 0; i < Nleft; ++i) {
                left[i] = mem[i];
            }
            return;
        }
        getNumberOfLoops(positions,left+2,Nleft-2,N,count);
    }
    for (int i = 0; i < Nleft; ++i) {
        left[i] = mem[i];
    }
}
int main15()
{
    ifstream fin ;
    ifstream dict;
    fin.open("wormhole.in");
    ofstream fout("wormhole.out");
    if(fin.is_open())
    {

        int N;
        fin >> N;
        position* positions[N];
        for (int i = 0; i < N; ++i) {
            int x,y;
            fin >> x >> y;
            positions[i] = new position(x,y);
        }
        int count = 0;
        getNumberOfLoops(positions,positions,N,N,&count);
        fout << count << endl;
    }
    return 0;
}