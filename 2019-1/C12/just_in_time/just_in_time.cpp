#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N;
    while (scanf("%lli", &N) != EOF){
        bool prime = 0;
        while (!prime) {
            // Trial division
            prime = 1;
            for (long int d=2; d*d <= N; d++){
                if (N % d == 0){
                    N--;
                    prime = 0;
                    break;
                }
            }
        }
        cout << N << endl;
    }
}