#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    long long int A, B;
    string a;
    for (int t=1; t<=T; t++){
        cin >> A;
        B = 0;
        a = to_string(A);
        for (int i=a.length(); i>=0; --i){
            int e = a.length() - i - 1;
            if (a[i] == '4'){
                A -= pow(10, e);
                B += pow(10, e);
            }
        }
        printf("Case #%i: %lli %lli\n", t, A, B);
    }
    return 0;
}