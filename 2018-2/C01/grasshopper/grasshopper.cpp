#include<bits/stdc++.h>

using namespace std;

string vowels = "AEIOUY";

bool isVowel(char c){
    for(int i=0; i<vowels.length(); i++){
        if(c == vowels[i]){
            return true;
        }
    }
    return false;
};

int main(){
    string line;
    getline(cin, line);
    int jAbility = 1;
    int c = 1; 
    for(int i=0; i<line.length(); i++){
        if(isVowel(line[i])){
            jAbility = max(jAbility, c); 
            c = 1;
        }
        else c++; 
    };
    jAbility = max(jAbility, c); 
    cout << jAbility << endl;
    return 0;
};