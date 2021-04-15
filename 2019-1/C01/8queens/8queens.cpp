#include<bits/stdc++.h>

using namespace std;

int N, R, C, S;
int board[8];

bool valid(int r, int c){
    for (int i=0; i<8; i++){
        if (board[i] == r) return 0;
        else if (board[i] && abs(board[i] - r) == abs(c - 1 - i)) return 0;
    }
    return 1;
}

void solve(int c){
    if (c == C) solve(c+1);
    else if (c==9) {
        if (S < 10) printf(" %i     ", S++);
        else printf("%i     ", S++);
        for (int i=0; i<8; i++){
            cout << " " << board[i];
        }
        cout << endl;
        return;
    }
    else {
        // for (int i=0; i<8; i++){
        //     cout << board[i] << " ";
        // }
        // cout << endl << "===============" << endl;
        for (int i=1; i<=8; i++){
            // printf("Checking validness of (%i, %i)\n", i, c);
            if (valid(i, c)) {
                // cout << "VALID!" << endl;
                board[c-1] = i;
                solve(c+1);
                board[c-1] = 0;
            }
        }
    }
}

int main(){
    cin >> N;
    while(N--){
        for (int i=0; i<8; i++) board[i] = 0;
        S = 1;
        scanf("%i %i", &R, &C);
        board[C-1] = R;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        solve(1);
        if (N) printf("\n");
    }
    return 0;
}