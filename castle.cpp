/*
ID: bourahl1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

class Vertex
{
public:
    int i,j;
    int value;
    bool edges[4];

    Vertex(int i, int j, int value) : i(i), j(j), value(value) {}
    Vertex(){};
};

void getAllConnections(int value,bool* edges)
{
    edges[0] = !(value & 1);
    edges[1] = !(value & 2);
    edges[2] = !(value & 4);
    edges[3] = !(value & 8);
}

int** generateComponents(Vertex** mat,int N,int M,int* numComponents)
{
    int** components = new int*[N];
    for (int i = 0; i < N; ++i) {
        components[i] = new int[M];
        for (int j = 0; j < M; ++j) {
            components[i][j] = 0;
        }
    }
    int numComp = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            if(!components[i][j])
            {
                vector<Vertex> queue;
                queue.push_back(mat[i][j]);
                components[i][j] = numComp;
                while(queue.size())
                {
                    Vertex element = queue[queue.size()-1];
                    queue.pop_back();
                    int i1 = element.i,j1 = element.j;
                    for (int k = 0; k < 4; ++k)
                        if(element.edges[k] && !components[i1-(k==1)+(k==3)][j1-(k==0)+(k==2)])
                        {
                            queue.push_back(mat[i1-(k==1)+(k==3)][j1-(k==0)+(k==2)]);
                            components[i1-(k==1)+(k==3)][j1-(k==0)+(k==2)] = numComp;
                        }
                }
                numComp++;
            }
    }
    *numComponents = numComp-1;
    return components;
}

int destroyWall(int* sizeRooms,Vertex** mat,int** comp,int N,int M,ofstream* out)
{
    int max = 0;
    vector<int> is;
    vector<int> js;
    vector<char> dir;
    char tab[4] = {'W','N','E','S'};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            bool* walls = mat[i][j].edges;
            for (int k = 0; k < 4; ++k)
            if(!walls[k])
            {
                int i1 = i-(k==1)+(k==3),j1 = j-(k==0)+(k==2);
                if(i1 > -1 && i1 < N && j1 > -1 && j1 < M && comp[i1][j1] != comp[i][j])
                    if(sizeRooms[comp[i][j]-1]+sizeRooms[comp[i1][j1]-1] > max)
                    {
                        max = sizeRooms[comp[i][j]-1]+sizeRooms[comp[i1][j1]-1];
                        is.clear(); is.push_back(i);
                        js.clear(); js.push_back(j);
                        dir.clear(); dir.push_back(tab[k]);
                    }
                    else if(sizeRooms[comp[i][j]-1]+sizeRooms[comp[i1][j1]-1] == max)
                    {
                        is.push_back(i);
                        js.push_back(j);
                        dir.push_back(tab[k]);
                    }
            }
        }
    }
    int min1 = N;
    for (int l = 0; l < is.size(); ++l)
        if(js[l] < min1){
            min1 = js[l];
        }
    int max1 = -1;
    char c = 0;
    for (int l = 0; l < is.size(); ++l)
        if(js[l] == min1 && is[l] > max1){
            max1 = is[l];
            c= dir[l];
        }
        else if(js[l] == min1 && is[l] == max1) c = 'N';

//    cout << max << endl;
//    cout << max1+1 << " " << min1 +1<< " " << c << endl;
    *out << max << endl;
    *out << max1+1 << " " << min1 +1<< " " << c << endl;
    return max;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("castle.in");
    fout.open("castle.out");
    if(fin.is_open())
    {
        int N,M;
        fin >> M >> N;
        Vertex** mat = new Vertex*[N];
        for (int i = 0; i < N; ++i) {
            mat[i] = new Vertex[M];
            for (int j = 0; j < M; ++j) {
                int value;
                fin >> value;
                mat[i][j] = Vertex(i,j,value);
                getAllConnections(value,mat[i][j].edges);
            }
        }
        int numComp;
        int** components = generateComponents(mat,N,M,&numComp);
        int roomSizes[numComp];

        for (int i = 0; i < numComp; ++i) {
            roomSizes[i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
//                cout << components[i][j] << " ";
                roomSizes[components[i][j]-1]++;
            }
//            cout << endl;
        }
        int max = 0;
        for (int i = 0; i < numComp; ++i)
        if(max < roomSizes[i])
        {
            max = roomSizes[i];
        }
//        cout << numComp << endl;
//        cout << max << endl;
        fout << numComp << endl;
        fout << max << endl;

        destroyWall(roomSizes,mat,components,N,M,&fout);

    }
    return 0;
}