#include<bits/stdc++.h>

using namespace std;

#define mp(a, b) make_pair(a, b)

long long int n;
map<pair<long long int, int>, pair<long long int, long long int>> memo;

pair<long long int, long long int> solve(long long int x, int m){
    long long int s, r;
    s = r = 0;
    long long int d = 1;
    while (x/10 >= d) d*=10;
    if (d == 1 && m) {
        m = m > x ? m : x;
        return mp(m, 1);
    }
    auto it = memo.find(mp(x, m));
    if (it != memo.end()) return it->second;
    while (x > 0){
        int b = x / d;
        pair<long long int, long long int> p = solve(x - b*d, b > m ? b : m);
        x -= p.first;
        r += p.first;
        s += p.second;
    }
    memo.emplace(mp(x+r, m), mp(r, s));
    return mp(r, s);

}

int main(){
    cin >> n;
    pair<long long int, long long int> p = solve(n, 0);
    cout << p.second << endl;
    return 0;
}