#include <bits/stdc++.h>

using namespace std;

vector<int> l, g;
int k;

void solve(int p, int r){
    if (!r){
        for (int i=0; i<6; i++){
            if (i>0) cout << " ";
            cout << g[i];
        }
        cout << endl;
        return;
    }
    for (int i=p; i<=k-r; i++){
        g.push_back(l[i]);
        solve(i+1, r-1);
        g.pop_back();
    }
}

int main(){
    bool first = 1;
    cin >> k;
    while (k != 0){
        if (!first) cout << endl;
        int buff;
        for (int i=0; i<k; i++){
            cin >> buff;
            l.push_back(buff);
        }
        solve(0, 6);
        cin >> k;
        l.clear();
        first = 0;
    }
    return 0;
}