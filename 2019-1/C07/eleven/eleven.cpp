#include<bits/stdc++.h>

using namespace std;

string N;
int max_s;
array<int, 10> digits;
bool open[100][11][50][50];
vector<array<int, 10>> memo[100][21][50][50];
vector<array<int, 10>> combs;

vector<array<int, 10>> solve(int n, int rest, int pos, int neg){
    if (n == N.length()){
        vector<array<int, 10>> r;
        if (rest == 10) {
            array<int, 10> a = {0};
            r.push_back(a);
            return r;
        }
        return r;
    }
    // printf("%i %i %i %i\n", n, rest, pos, neg);
    if (open[rest][n][pos][neg]) return memo[rest][n][pos][neg];
    open[rest][n][pos][neg] = 1;
    int i = N[n] - 48;
    vector<array<int, 10>> v1, v2, v3;
    if (pos < max_s){
        v1 = solve(n+1, (rest - 10 + i) % 11 + 10, pos+1, neg);
        v3.insert(v3.begin(), v1.begin(), v1.end());
        for (auto& a: v3){
            a[i]++;
        }
    }
    if (neg < max_s){
        v2 = solve(n+1, (rest - 10 - i) % 11 + 10, pos, neg+1);
        v3.insert(v3.begin(), v2.begin(), v2.end());
    }
    // printf("%i %i %i %i\n", n, rest, pos, neg);
    memo[n][rest][pos][neg] = v3;
    // for (auto& a: memo[n][rest][pos][neg]){
    //     for (auto& i: a){
    //         cout << i;
    //     }
    //     cout << endl;
    // }
    return v3;
}

int main(){
    while(getline(cin, N)){
        memset(open, 0, sizeof open);
        digits.fill(0);
        max_s = N.length() / 2 + N.length() % 2;
        solve(0, 10, 0, 0);
        for (auto& a: memo[0][10][0][0]){
            for (auto& i: a){
                cout << i;
            }
            cout << endl;
        }
    }
    return 0;
}