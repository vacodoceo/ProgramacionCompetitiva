#include <bits/stdc++.h>
using namespace std;

int main(){
    float n, k;
    scanf("%f %f", &n, &k);
    long long int result = (pow(n, 2) - (n-1)/2)*n - (n-k)*n*(0.5 + n/2);
    cout << result << endl;

    int offset = pow(n, 2) - (n-k+1)*(n) + 1;
    for (int j=0; j<n; j++){
        for (int i=1; i<=n; i++){
            if (i < k) cout << i+(k-1)*j << " ";
            else cout << offset+i-k+(n-k+1)*j << " ";
        }
        puts("");
    }
    return 0;
}