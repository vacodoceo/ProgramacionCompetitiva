#include<bits/stdc++.h>

using namespace std;

// http://www.cplusplus.com/reference/algorithm/sort/
bool descending (int i,int j) { return (i>j); }

int main(){
    int n; cin >> n; int trees[n];
    for (int i=0; i<n; i++){
        scanf("%i", &trees[i]);
    };
    int min = 0;
    sort(trees, trees + n, descending);
    for (int i=0; i<n; i++){
        min = max(min, i + trees[i] + 2);
    };
    cout << min << endl;
    return 0;
};