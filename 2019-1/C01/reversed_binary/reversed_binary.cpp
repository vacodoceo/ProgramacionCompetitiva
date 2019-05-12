#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int N, N2, sum;
    N2 = 0;
    sum = 1;
    vector<int> bin;
    cin >> N;
    while(N){
        bin.insert(bin.begin(), N%2);
        N = N/2;
    }
    for (auto it=bin.begin(); it!=bin.end(); ++it){
        // printf("%i * %lli\n", *it, sum);
        N2 += *it * sum;
        sum *= 2;
    }
    cout << N2 << endl;
    return 0;
}