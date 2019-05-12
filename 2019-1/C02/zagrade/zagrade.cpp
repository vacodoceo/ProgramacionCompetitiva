#include <bits/stdc++.h>

using namespace std;

vector<pair<unsigned int, unsigned int>> pairs;
set<string> printed;
string e;
int n;

void solve(string s, int i){
    if (i==n){
        for (auto it=printed.begin(); it!=printed.end(); ++it){
            if (!s.compare(*it)) return;
        }
        printed.insert(s);
        return;
    }
    solve(s, i+1);
    // cout << s << " | " << i << endl;
    // printf("first: %u | second: %u\n", pairs[i].first, pairs[i].second);
    s.erase(s.begin() + pairs[i].second);
    s.erase(s.begin() + pairs[i].first);
    for (int j=i+1; j<pairs.size(); j++){
        pairs[j].first--;
        pairs[j].second--;
        if (pairs[j].first > pairs[i].second){
            pairs[j].first--;
            pairs[j].second--;
        }
    }
    solve(s, i+1);
    for (int j=i+1; j<pairs.size(); j++){
        pairs[j].first++;
        pairs[j].second++;
        if (pairs[j].first > pairs[i].second){
            pairs[j].first++;
            pairs[j].second++;
        }
    }
}

int main(){
    cin >> e;
    printed.insert(e);
    n = count(e.begin(), e.end(), '(');
    size_t last = 0;
    for (int i=0; i<n; i++){
        size_t b = e.find('(', last);
        pairs.emplace_back(b, 0);
        int c = 1;
        for (size_t j=b+1; j<e.length(); j++){
            // printf("j: %i | c: %i\n", j, c);
            if (e[j] == '(') c++;
            else if (e[j] == ')'){
                c--;
                if (!c) {
                    pairs[i].second = j;
                    break;
                }
            }
        }
        last = pairs[i].first + 1;
        // printf("%u %u\n", pairs[i].first, pairs[i].second);
    }
    solve(e, 0);
    for (auto it=printed.begin(); it!=printed.end(); ++it){
        if (e.compare(*it)) cout << *it << endl;
    }
    return 0;
}