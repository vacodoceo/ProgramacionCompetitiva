#include <bits/stdc++.h>

using namespace std;

set<long long int> dif;

int main(){
    int n, min_p;
    long long int k, max_d, buff;
    cin >> n >> k;
    while(n--){
        cin >> buff;
        dif.insert(buff);
    }
    min_p = 0;
    max_d = k;
    for (auto& d: dif){
        if (d > max_d){
            while(d > 2*max_d){
                min_p++;
                max_d = 2*max_d;
            }
            max_d = d;
        }
    }
    cout << min_p << endl;
    return 0;
}