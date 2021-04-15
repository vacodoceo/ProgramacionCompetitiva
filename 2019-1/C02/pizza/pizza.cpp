#include <bits/stdc++.h>

using namespace std;

map<string, long long int> foreign;
map<string, long long int> native;
int t, n, m, n2;

void add_ingredient(string b, map<string, long long int> & m){
    auto it = m.find(b);
    long long int v = (it == m.end()) ? 0 : it->second;
    long long int mask = 1 << n;
    v |= mask;
    m[b] = v;
}

int main(){
    cin >> t;
    while (t--){
        foreign.clear(); native.clear();
        cin >> n;
        n2 = n;
        while (n--){
            string b;
            cin >> b;
            cin >> m;
            while (m--){
                cin >> b;
                add_ingredient(b, foreign);
            }
            cin >> m;
            while (m--){
                cin >> b;
                add_ingredient(b, native);
            }
        }
        for (auto it=foreign.begin(); it!=foreign.end(); ++it){
            // cout << it->first << " | " << it->second << endl;
            for (auto it2=native.begin(); it2!=native.end(); ++it2){
                if (it->second == it2->second) cout << "(" << it->first << ", " << it2->first << ")" << endl;
            }

        }
        if (t) cout << endl;
    }
    return 0;
}