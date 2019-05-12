#include<bits/stdc++.h>

using namespace std;

struct Cell{
    bool s;
    bool f[2];
    int v[1];
    int a[10];
    // Cell * square[5];
};

Cell board[6][6];

void set_value(int i, int j, int v, int s){
    for (int k=0; k<6; k++){
        board[k][j].a[v]+= s;
        board[i][k].a[v]+= s;
    }
    // printf("%i %i: ", i, j);
    for (int k=0; k<3; k++){
        board[i + ((i+1)%2)*2 - 1][j - j%3 + k].a[v]+= s;
        // printf("[%i][%i] ", i + ((i+1)%2)*2 - 1, j - j%3 + k);
    }
    // cout << endl;
    board[i][j].a[v]-= s;
    board[i + ((i+1)%2)*2 - 1][j].a[v]-= s;
};

void print_board(){
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (board[i][j].s) printf("%i/%i ", board[i][j].v[0], board[i][j].v[1]);
            else printf("%i ", board[i][j].v[0]);
        }
        cout << endl;
    }
    // for (int i=0; i<6; i++){
    //     for (int j=0; j<6; j++){
    //         printf("[%i][%i]:", i, j);
    //         for (int k=1; k<10; k++){
    //             if (!board[i][j].a[k]) printf(" %i", k);
    //         }
    //         cout << endl;
    //     }
    // }
}

bool solve(int i, int j, int d){
    // print_board();
    // cout << "===================" << endl;
    if (i == 6 && j == 0){
        print_board();
        return 1;
    }
    if (!board[i][j].f[d]){
        int l = 1;
        int u = 10;
        if (d) l = board[i][j].v[0] + 1;
        if (!d && board[i][j].s && board[i][j].f[1]) u = board[i][j].v[1];
        for (int k=l; k<u; k++){
            // printf("[%i][%i]: %i\n", i, j, k);
            if (!board[i][j].a[k]){
                set_value(i, j, k, 1);
                board[i][j].v[d] = k;
                if (!d && board[i][j].s){
                     if (solve(i, j, 1)) return 1;
                }
                else if (solve(i + (j+1)/6, (j+1)%6, 0)) return 1;
                board[i][j].v[d] = 0;
                set_value(i, j, k, -1);
            }
        }
    }
    else{
        if (!d && board[i][j].s){
            if (solve(i, j, 1)) return 1;
        }
        else if (solve(i + (j+1)/6, (j+1)%6, 0)) return 1;
    }
    return 0;
}

int main(){
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            string b;
            cin >> b;
            for (int k=0; k<10; k++) board[i][j].a[k] = 0;
            if (b.find('/') != -1){
                board[i][j].s = 1;
                if (b[0] == '-') {
                    board[i][j].v[0] = 0;
                    board[i][j].f[0] = 0;
                }
                else {
                    board[i][j].v[0] = b[0] - '0';
                    board[i][j].f[0] = 1;
                }
                if (b[2] == '-') {
                    board[i][j].v[1] = 0;
                    board[i][j].f[1] = 0;
                }
                else {
                    board[i][j].v[1] = b[2] - '0';
                    board[i][j].f[1] = 1;
                }
            }
            else {
                if (b[0] == '-') {
                    board[i][j].v[0] = 0;
                    board[i][j].f[0] = 0;
                }
                else {
                    board[i][j].v[0] = b[0] - '0';
                    board[i][j].f[0] = 1;
                }
            }
        }
    }
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (board[i][j].f[0]) set_value(i, j, board[i][j].v[0], 1);
            if (board[i][j].s && board[i][j].f[1]) set_value(i, j, board[i][j].v[1], 1);
        }
    }

    // print_board();

    // for (int i=0; i<6; i++){
    //     for (int j=0; j<6; j++){
    //         printf("[%i][%i]:", i, j);
    //         for (int k=1; k<10; k++){
    //             if (!board[i][j].a[k]) printf(" %i", k);
    //         }
    //         cout << endl;
    //     }
    // }
    solve(0, 0, 0);
    return 0;
}