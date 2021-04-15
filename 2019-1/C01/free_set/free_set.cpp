#include<bits/stdc++.h>

using namespace std;

long long int n, k;
set<long long int> data;

int main(){
    cin >> n >> k;
    if (k==1){
        cout << n << endl;
        return 0;
    }
    for (int i=0; i<n; i++){
        long long int buff;
        cin >> buff;
        data.insert(buff);
    }
    for (set<long long int>::iterator it=data.begin(); it!=data.end(); ++it){
        if (data.find(*it*k) != data.end()){ 
            n--;
            data.erase(*it*k);
        }
    }
    cout << n << endl;
    return 0;
}