#include <bits/stdc++.h>

using namespace std;

struct Node {
    set<char> parents;
    set<char> childrens;
};

int main(){
    int T;
    cin >> T;
    for (int x = 0; x < T; x++){
        unordered_map<char, Node *> bricks;
        int R, C;
        cin >> R >> C;
        vector<vector<char>> wall(R, vector<char>(6, ' '));

        for (int r=0; r<R; r++){
            for (int c=0; c<C; c++){
                char buff;
                cin >> buff;
                if (bricks.find(buff) == bricks.end()) bricks[buff] = new Node;
                wall[R-r-1][c] = buff;
            }
        }        

        for (int c=0; c<C; c++){
            for (int r=0; r<R-1; r++){
                char b = wall[r][c];
                char t = wall[r+1][c];
                if (b != t){
                    bricks[b]->parents.insert(t);
                    bricks[t]->childrens.insert(b);
                }
            }
        }

        string s;
        int pos = 0;

        while(bricks.size() > 0){
            char b = bricks.begin()->first;
            bricks.erase(bricks.begin());
        }

        // printf("Case #%i: %li\n", x + 1, c);
    }

    return 0;
}