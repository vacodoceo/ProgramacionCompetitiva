#include<bits/stdc++.h>

using namespace std;

#define mp(a, b) make_pair(a, b)

pair<int, int> directions[4] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};

struct Cell{
    bool type;
    int open;
    vector<Cell> * component;
};

Cell labyrinth[1000][1000];
vector<Cell> ca[1000000];

int n, m;

void DFS(int pos_i, int pos_j, vector<Cell> * v){
    Cell& c = labyrinth[pos_i][pos_j];
    c.open = 1;
    // printf("WE ARE IN (%i, %i)\n", pos_i, pos_j);
    c.component = v;
    v->push_back(c);
    for (auto& d: directions){
        int new_i = pos_i + d.first;
        int new_j = pos_j + d.second;
        if (new_i >= 0 && new_i < n){
            if (new_j >= 0 && new_j < m){
                // printf("(%i+%i, %i+%i): %i\n", pos_i, d.first, pos_j, d.second, labyrinth[new_i][new_j].open);
                if (!labyrinth[new_i][new_j].open && !labyrinth[new_i][new_j].type) DFS(new_i, new_j, v);
            }
        }
    }
    // printf("(%i, %i): %lu\n", pos_i, pos_j, v->size());
}

long int getCompSize(int i, int j){
    vector<vector<Cell> *> comps;
    long long int size = 1;
    for (auto& d: directions){
        int new_i = i + d.first;
        int new_j = j + d.second;
        if (new_i >= 0 && new_i < n){
            if (new_j >= 0 && new_j < m){
                if (!labyrinth[new_i][new_j].type){
                    vector<Cell> * component = labyrinth[new_i][new_j].component;
                    bool open = 0;
                    for (auto& c: comps){
                        if (c == component) open = 1;
                    }
                    if (!open){
                        comps.push_back(component);
                        size += component->size();
                    }
                }
            }
        }
    }
    return size;
}

int main(){
    cin >> n >> m;

    // Build labyrinth
    char buff;
    for (int i=0; i<n; i++){
        getchar();
        for (int j=0; j<m; j++){
            buff = getchar();
            labyrinth[i][j].type = (buff == '*') ? 1 : 0;
            labyrinth[i][j].open = 0;
        }
    }

    // Build clusters
    long int count = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!labyrinth[i][j].open && !labyrinth[i][j].type){
                DFS(i, j, &ca[count++]);
            }
        }
    }

    // Build output
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!labyrinth[i][j].type) printf(".");
            else printf("%li", getCompSize(i, j) % 10);
        }
        cout << endl;
    }
    return 0;
}