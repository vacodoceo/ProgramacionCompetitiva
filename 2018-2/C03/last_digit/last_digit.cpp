#include<bits/stdc++.h>
using namespace std;

int main(){
    string buffer;
    while (getline(cin, buffer)){
        unordered_map<char, int> d;
        for (int i=0; i<buffer.size(); i++){
            if (d.find(buffer[i]) == d.end()){
                d.emplace(buffer[i], 1);
            }
            else {
                d[buffer[i]] += 1;
            }
        }

        char max = ' ';
        for (auto i=d.begin(); i!=d.end(); i++){
            if (i->second > max) {
                max = i->first;
            };
        }
    }
};