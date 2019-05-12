#include <bits/stdc++.h>

using namespace std;

set<pair<double, long int>> collider;
set<double> sim;

set<double> get_positions(double t){
    set <double> s;
    for (auto& p: collider){
        s.insert(p.first + t*p.second);
    }
    return s;
}

int main(){
    long int n;
    cin >> n;
    double x;
    long int v;
    for (long int i=0; i<n; i++){
        cin >> x >> v;
        collider.insert(make_pair(x, v));
    }
    pair<double, long int> left, right;
    for (auto& p : collider){
        if (p.second > 0) {
            left = p;
            break;
        }
    }
    for (auto rit=collider.rbegin(); rit!=collider.rend(); ++rit){
        if (rit->second < 0){
            right = *rit;
            break;
        }
    }
    double t = (right.first - left.first) / (left.second - right.second);
    cout << left.first << " " << left.second << endl;
    cout << right.first << " " << right.second << endl;
    cout << t << endl;
    cout << "===============" << endl;

    sim = get_positions(t);

    for (auto& p: sim){
        printf("%.5f ", p);
    }
    cout << endl;

    return 0;
}