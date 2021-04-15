#include <bits/stdc++.h>

using namespace std;

pair<long int, long int> periodic_wind;
vector<pair<int, int>> wind;
map<char, pair<int, int>> directions = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'R', {1, 0}},
    {'L', {-1, 0}},
};

int main(){
    pair<long long int, long long int> ship, dest, fdest;
    long int n;
    cin >> ship.first >> ship.second >> dest.first >> dest.second >> n;
    char c = getchar();
    while ((c = getchar()) != EOF){
        pair<int, int> d = directions[c];
        wind.push_back(d);
        periodic_wind.first += d.first;
        periodic_wind.second += d.second;
    }
    dest.first -= ship.first;
    dest.second -= ship.second;
    ship.first = ship.second = 0;

    long long int l, r;
    l = 0;
    r = 2e9*n;
    long long int days, periods;
    for(int i = 0; i < 60; i++){
        fdest = dest;
        days = (l + r)/2;
        periods = days / n;
        fdest.first -= periodic_wind.first * periods;
        fdest.second -= periodic_wind.second * periods;
        for (long int d = 0; d < days % n; d++){
            fdest.first -= wind[d].first;
            fdest.second -= wind[d].second;

        }
        if (abs(fdest.first) + abs(fdest.second) <= days) r = days;
        else if (l == days) l++;
        else l = days;
    }
    if (days == 2e9*n) cout << -1 << endl;
    else cout << days << endl;
    return 0;
}