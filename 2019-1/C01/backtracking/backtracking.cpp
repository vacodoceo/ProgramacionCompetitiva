#include<bits/stdc++.h>

using namespace std;

vector<long int> seq;
long int K;

bool occupied(int i, vector<int> sol){
    for (int j=0; j<10; j++){
        if (sol[j] == i) {
            // printf("%i occupied in %i\n", i, j);
            return 1;
        }
    }
    // printf("%i not occupied\n", i);
    return 0;
}

bool solve(vector<int> sol, int p, int s){
    // for (int i=0; i<10; i++){
    //     cout << sol[i] << " ";
    // }
    // printf("  |  P = %i  |  S = %i\n", p, s);
    if (p == 10){
        for (int i=0; i<10; i++){
                cout << sol[i] << " ";
            }
            cout << endl;
        return 1;
    }

    for (int i=0; i<10; i++){
        if (s+seq[p]*i > K) break;
        if (!occupied(i, sol)){
            sol[p] = i;
            if (solve(sol, p+1, s+seq[p]*i)) return 1;
            sol[p] = -1;
        }
    }
    return 0;
};

int main() {
    int N;
    cin >> N;
    for (int n=0; n<N; n++){
        long int buff;

        seq.clear();
        for (int i=0; i<10; i++){
            cin >> buff;
            seq.push_back(buff);
        }
        cin >> K;

        vector<int> sol (10, -1);
        if (!solve(sol, 0, 0)){
            cout << "-1" << endl;
        }
    }
}