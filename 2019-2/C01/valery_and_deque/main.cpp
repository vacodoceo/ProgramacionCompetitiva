#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<long long int> d;
    long long int n, q, a[100000], M[100000], max_a, max_n, m;
    cin >> n >> q;
    max_a = 0;
    for (long int i=0; i<n; i++){
        cin >> a[i];
        d.push_back(a[i]);
        if (a[i] > max_a){
            max_a = a[i];
            max_n = i;
        } 
    }
    for (long int i=0; i<n; i++){
        M[i] = d[0];
        if (d[0] == max_a) break;
        else if (d[0] > d[1]){
            d.push_back(d[1]);
            d.erase(d.begin()+1);
        } else {
            d.push_back(d[0]);
            d.pop_front();
        }
    }
    for (long int i=0; i<q; i++){
        cin >> m;
        m--;
        if (m >= max_n){
            m -= max_n;
            m %= n-1;
            cout << max_a << " " << d[1 + m] << endl;
        } else {
            cout << M[m] << " " << a[m+1] << endl;
        }
    }
    return 0;
}