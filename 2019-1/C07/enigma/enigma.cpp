#include<bits/stdc++.h>

using namespace std;

string D, sol;
int N;
bool found;
int memo[1000][1000];

bool solve(int i, int r){
    // printf("%i | %i BEGIN\n", i, r);
    if (i == D.length()) {
        if (r == 0) {
            cout << sol << endl;
            found = 1;
        }
        return r == 0;
    }
    if (!memo[i][r]) return 0;
    if (D[i] == '?'){
        for (int j=(i == 0 ? 1:0); j<10; j++){
            sol[i] = j + 48;
            if (solve(i+1, (r*10+j) % N)) break;
        }
    }
    else {
        int p = (int) D[i] - 48;
        int r2 = (r*10+p) % N;
        solve(i+1, r2);
    }
    // printf("%i | %i END\n", i, r);
    return memo[i][r] = found;
}

int main(){
    while (getline(cin, D, ' ')){
        sol = D;
        cin >> N;
        found = 0;
        memset(memo, -1, sizeof memo);
        if (!solve(0, 0)){
            cout << "*" << endl;
        };
        getchar();
        // for (int i=0; i<D.length(); i++){
        //     for (int j=0; j<N; j++){
        //         printf("[%i][%i]: %i\n", i, j, memo[i][j]);
        //     }
        // }
    }
    return 0;
}