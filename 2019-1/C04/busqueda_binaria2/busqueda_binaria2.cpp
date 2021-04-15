#include <bits/stdc++.h>

using namespace std;

map<long long int, long int> numbers;

int main(){
    long long int N, Q;
    cin >> N >> Q;
    long long int last = -1;
    long long int current;
    for (long int n=0; n<N; n++){
        cin >> current;
        auto it = numbers.find(current);
        if (it == numbers.end()) numbers.emplace(current, n);
        else numbers[current] = n;
        last = current;
    }
    while (Q--){
        cin >> current;
        auto it = numbers.find(current);
        if (it == numbers.end()) cout << -1 << endl;
        else cout << it->second << endl;
    }
    return 0;
}