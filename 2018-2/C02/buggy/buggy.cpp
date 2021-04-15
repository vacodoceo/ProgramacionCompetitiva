#include<bits/stdc++.h>
using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

string s;
bool s_vowels[100000] = {0};
long int s_vowels_count[100000];

// d = 0 means left to right direction
bool allCons(int l, int r, int d){
    return s_vowels_count[l] == s_vowels_count[r+1];
}
bool frontVowel(int l, int r, int d){
    return 1 == s_vowels[l*abs(d-1) + r*d];
}

bool endVowel(int l, int r, int d){
    return 1 == s_vowels[l*d + r*abs(d-1)];
}

int getType(int l, int r, int d){
    if (l == r || allCons(l, r, d)){
        // cout << "Returning 1\n";
        return 1;
    }
    if (!frontVowel(l, r, d)){
        // cout << "Returning 0\n";
        return 0;
    }  
    if (endVowel(l, r, d)){
        // printf("Returning %i, %i, %i \n", l + abs(d-1), r - d, abs(d-1));
        return getType(l + abs(d-1), r - d, abs(d-1));
    } 
    // printf("Returning %i, %i, %i + %i, %i, %i\n", l + abs(d-1), r - d, abs(d-1), l + d, r - abs(d-1), d);

    return getType(l + abs(d-1), r - d, abs(d-1)) + getType(l + d, r - abs(d-1), d);
}

int main(){
    s_vowels_count[0] = 0;
    while (getline(cin, s)){
        int c = 0;
        for (int i=0; i<s.length(); i++){
            bool vowel = 0;
            for (int j=0; j<5; j++){
                if (vowels[j] == s[i]){
                    vowel = 1;
                    c++;
                    break;
                }
            }
            s_vowels_count[i+1] = c; s_vowels[i] = vowel;
        }
        cout << getType(0, s.length() - 1, 0) << endl;
    }
    return 0;
}