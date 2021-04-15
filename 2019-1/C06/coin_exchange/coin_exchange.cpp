#include<bits/stdc++.h>

using namespace std;

int n, m;
long long int memo[251] = {0};
set<int> coins;

void getCoins(int n){
    for (auto& coin: coins){
        for (int i=0; i<=n; i++){
            if (coin == i) memo[i]++;
            if (i > coin) memo[i] += memo[i-coin];
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    int coin;
    while(m--){
        cin >> coin;
        coins.insert(coin);
    }

    getCoins(n);
    cout << memo[n] << endl;
}