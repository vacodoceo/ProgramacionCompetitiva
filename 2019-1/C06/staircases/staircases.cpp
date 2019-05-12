#include<bits/stdc++.h>

using namespace std;

int N;
long long int Q;
long long int memo[500][500];

long long int get_staircase(int max, int rest){
    if (rest == 0) return 1;
    if (memo[max][rest] != -1) return memo[max][rest];
    long long int q = 0;
    for (int n=1; n<max & n<=rest; n++){
        q += get_staircase(n, rest - n);
    }
    memo[max][rest] = q;
    return q;
}

int main(){
    for (auto& m: memo){
        for (auto& i: m){
            i = -1;
        }
    }
    cin >> N;
    for (int n=3; n<N; n++){
        Q += get_staircase(n, N-n);
    }
    cout << Q << endl;
    return 0;
}