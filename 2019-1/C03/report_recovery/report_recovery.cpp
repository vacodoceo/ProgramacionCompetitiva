#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<pair<string, string>> reports;
vector<vector<string>> m;
int p;

void print_m(){
    for (int n=0; n<N; n++) cout << "P" << n+1 << " ";
    cout << "Totals" << endl;
    int row = 0;
    for (auto& s: m){
        string seller = row <= S ? reports[row].first : "TP";
        cout << seller << " ";
        for (auto r: s){
            cout << r << " ";
        }
        cout << endl;
        row++;
    }
}

bool check_seller(int s){
    // print_m();
    int sum = 0;
    for (auto it=m[s].begin(); it!=m[s].end()-1; ++it){
        sum += stoi(*it);
    }
    return (sum == stoi(m[s].back()));
}

bool check_column(int n){
    int sum = 0;
    for (int s=0; s<S; s++){
        sum += stoi(m[s][n]);
    }
    return (sum == stoi(m[S][n]));
}

bool solve(int s, int n, int p){
    if (n == 0) p = 0;
    // printf("s: %i/%i | n: %i/%i\n", s, S, n, N);
    int l = (int)reports[s].second.length() - p;
    if (n == 0 && s > 0 && !check_seller(s-1)) return 0;
    if (s == S && n > 0 && !check_column(n-1)) return 0;
    if (s == S+1 && n == 0){
        print_m();
        return 1;

    }
    int total = (n == N || s == S) ? 2 : 0;
    int limit = 3 + total < l-N+n ? 3 + total : l-N+n;
    int start = n == N ? l : 1;
    // cout << "start: " << start << endl;
    for (int i=start; i<=limit; i++){
        if (i>1 && reports[s].second[p] == '0') return 0;
        // printf("p: %i | i: %i | start: %i | limit: %i ", p, i, start, limit);
        // cout << reports[s].second << endl;
        m[s][n] = reports[s].second.substr(p, i);
        // cout << m[s][n] << "|" << reports[s].second.substr(p) << endl;
        // print_m();
        if (solve(s + (n+1) / (N+1), ((n+1) % (N+1)), p+i)) return 1;
    }
    return 0;
}

int main(){
    int C;
    cin >> C;
    while (C--){
        reports.clear(); m.clear();
        S = 0;
        string token;
        cin >> token;
        N = count(token.begin(), token.end(), 'P');
        cin >> token;
        while (1){
            int p;
            string name;
            for (int i=0; i<token.length(); i++){
                if (token[i] < 58){
                    name = token.substr(0, i);
                    p = i;
                    break;
                }
            }
            string number_string = token.substr(p);
            reports.emplace_back(name, number_string);
            if (token[1] == 'P') break;
            cin >> token;
            S++;
        }
        for (int i=0; i<S+1; i++){
            vector<string> v(N+1, "");
            m.push_back(v);
        }
        // for (auto& i: reports){
        //     cout << i.first << " " << i.second << endl;
        // }
        solve(0, 0, 0);

    }
    return 0;
}