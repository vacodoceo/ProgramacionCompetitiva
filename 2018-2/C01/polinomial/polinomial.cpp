#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    for (int i=0; i<t; i++){
        int d1, d2; cin >> d1;
        int p1[d1 + 1]; 
        for (int j=0; j<=d1; j++){
            scanf("%i", &p1[j]);
        };
        cin >> d2;
        int p2[d2 + 1]; 
        for (int j=0; j<=d2; j++){
            scanf("%i", &p2[j]);
        };
        int ans[d1 + d2 + 1] = {};
        for (int j=0; j<=d1; j++){
            for (int k=0; k<=d2; k++){
                ans[k+j] += p1[j]*p2[k];
            };
        };
        cout << d1 + d2 << endl;
        for (int j=0; j<=d1+d2; j++){
            printf("%i ", ans[j]);
        };
        cout << endl;
    };
    return 0;
};
