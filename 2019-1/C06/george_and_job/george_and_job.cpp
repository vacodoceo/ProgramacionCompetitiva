#include<bits/stdc++.h>

using namespace std;

int n, m, k;
long long int memo[5001][5001];

int main(){
    for (auto& m1: memo) for (auto& m2: m1) m2 = 0;
    cin >> n >> m >> k;
    int p[n];
    for (int i=0; i<n; i++) cin >> p[i];
    long long int sum;
    for (int l=0; l<k; l++){
        sum = 0;
        for (int i=n-(m*(l+1)); i<n-(m*l); i++) {
            sum += p[i];
        }
        for (int i=n-(m*(l+1)); i>=0; i--){
            if (i != n-(m*(l+1))) {
                sum += p[i] - p[i+m];
                memo[i][l] = max(sum + memo[i+m][l-1], memo[i+1][l]);
            }
            else {
                // printf("%i %i: %lli\n", i, l, sum);
                memo[i][l] = sum;
                if (l) memo[i][l] += memo[i+m][l-1];
            }
            printf("[%i][%i]: %lli | %lli\n", i, l, sum, memo[i][l]);
        }
    }
    cout << memo[0][k-1] << endl;
    return 0;
}