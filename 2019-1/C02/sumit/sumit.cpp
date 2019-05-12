#include<bits/stdc++.h>

using namespace std;

vector<int> sum, l;
vector<vector<int>> printed;
bool found;
int t, n;

void solve(int p, int s){
    if (s == t){
        found = 1;
        for (auto it=printed.begin(); it!=printed.end(); it++){
            if (sum == *it){
                return;
            }
        }
        for (int i = 0; i < sum.size(); i++){
            if (i>0) cout << "+";
            cout << sum[i];
        };
        cout << endl;
        printed.push_back(sum);
        return;
    }
    else if (p == n) return;
    else if (l[p] + s <= t){
        sum.push_back(l[p]);
        solve(p+1, l[p] + s);
        sum.pop_back();
    }
    solve(p+1, s);
}

int main(){
    cin >> t >> n;
    while (t != 0 | n != 0){
        int buff;
        for (int i=0; i<n; i++){
            cin >> buff;
            l.push_back(buff);
        }
        printf("Sums of %i:\n", t);
        found = 0;
        solve(0, 0);
        if (!found) printf("NONE\n");
        cin >> t >> n;
        l.clear();
    }
    return 0;
}