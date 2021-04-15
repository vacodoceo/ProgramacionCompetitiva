#include<bits/stdc++.h>

using namespace std;

int main(){
    string s, t; int i;
    while (getline(cin, s)){
        stringstream ss;
        ss << s;
        vector<int> v;
        while(getline(ss, t, ' ')){
            stringstream(t) >> i;
            v.push_back(i);
        };

        int c = 0;
        for(int i=0; i<v.size(); i++){
            int sum = 0;
            for(int j=0; j<v.size(); j++){
                if(i != j){
                    sum += v[j];
                };
            };
            if (sum == v[i]){
                cout << sum << endl;
                i = v.size();
            };
        };
    };
};
