#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c = n*n;
    int i = 1;
    int primes[n*n];
    while (c--){
        while (i++){
            bool prime = 1;
            for (int j=2; j<i; j++){
                if (i%j == 0){
                    prime = 0;
                    break;
                }
                else if (j%i > i) break;
            }
            if (prime) {
                primes[c] = i;
                break;
            }
        }
    }
    int output[n][n];
    int r = n-1;
    int b = n-1;
    int l = 0;
    int t = 1;
    int x = 1;
    int y = 0;
    i = 0;
    int j = 0;
    for (int k = n*n-1; k>=0; k--){
        // cout << "ASSIGNING " << primes[k] << " TO (" << i << "," << j << ")" << endl;
        output[i][j] = primes[k];
        if (x == 1 & i == r) {
            x = 0;
            y = -1;
            r--;
        }
        else if (y == -1 & j == b) {
            x = -1;
            y = 0;
            b--;
        }
        else if (x == -1 & i == l) {
            x = 0;
            y = 1;
            l++;
        }
        else if (y == 1 & j == t) {
            x = 1;
            y = 0;
            t++;
        }
        i += x;
        j -= y;
    }
    // cout << "N: " << n << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << output[j][i];
            if (j<n-1) cout << " ";
            // continue;
        }
        puts("");
    }
    return 0;
}