#include<bits/stdc++.h>

using namespace std;

multiset<int> nn, a, b, both;
int n;

int main(){
    cin >> n;
    while(n--){
        string pref;
        int inf;
        cin >> pref >> inf;
        if (pref == "00") nn.insert(inf);
        else if (pref == "10") a.insert(inf);
        else if (pref == "01") b.insert(inf);
        else both.insert(inf);
    }
    a.insert(0); b.insert(0); nn.insert(0);
    long long int sum = 0;
    int e, ac, bc, nc;
    e = ac = bc = nc = 0;
    for (auto& i: both){
        e++;
        sum += i;
    }
    int max_z = e;


    auto a_end = prev(a.end());
    auto b_end = prev(b.end());
    int max_i = a.size() < b.size() ? a.size() - 1 : b.size() - 1;
    for (int i=0; i<max_i; i++){
        sum += *a_end;
        sum += *b_end;
        a_end = prev(a_end);
        b_end = prev(b_end);
        e += 2; ac++; bc++;
    }

    auto m_end = max_i + 1 == a.size() ? b_end : a_end;
    auto n_end = prev(nn.end());
    int max_inf;
    while (max_z--){
        max_inf = 0;
        if (*n_end > max_inf) max_inf = *n_end;
        if (*m_end > max_inf) {
            max_inf = *m_end;
            m_end = prev(m_end);
        }
        else if (*n_end > 0) n_end = prev(n_end);
        sum += max_inf;
    }
    cout << sum << endl;
    return 0;
}