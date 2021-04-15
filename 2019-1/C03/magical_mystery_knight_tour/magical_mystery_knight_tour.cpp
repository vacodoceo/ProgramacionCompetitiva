
#include <bits/stdc++.h>

using namespace std;

struct cell {
    int v;
    vector<cell*> p;
};

cell board[8][8];
int d[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

void build_board(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            for (int k=0; k<8; k++){
                if (i+d[k][0] < 9 && i+d[k][0] > -1 && j+d[k][1] < 9 && j+d[k][1] > -1){
                    board[i][j].p.push_back(&board[i+d[k][0]][j+d[k][1]]);
                }
            }
        }
    }
}

void print_board(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            cout << board[i][j].v << " ";
        }
        cout << endl;
    }
}

bool solve(int r, int c){
    
    return 0;
}

int main(){
    int P, K;
    cin >> P;
    while (P--){
        cin >> K;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                cin >> board[i][j].v;
            }
        }
        int r, c;
        tie(r, c) = find_1();
        build_board();
        solve(0, 0);
        cout << K << endl;
        print_board();
    }
    return 0;

}