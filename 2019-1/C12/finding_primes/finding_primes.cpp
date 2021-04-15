#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(1e7 + 1, 1);
int a[10000001] = {0};

int main(){
    long long int n, T;
    for (int d=2; d <= sqrt(1e7); d++){
        if (prime[d]){
            for (long long int i = d*d; i <= 1e7; i += d) {
                prime[i] = 0;
            }
        }
        a[d] = a[d-1] + prime[d];
    }
    for (long long int d = sqrt(1e7)+1; d<=1e7; d++) a[d] = a[d-1] + prime[d];

    // for (int i=2; i<=10; i++){
    //     cout << a[i] << " ";
    // }

    cin >> T;
    while (T--){
        cin >> n;
        cout << a[n] - a[n/2] << endl;
    }
    return 0;
}