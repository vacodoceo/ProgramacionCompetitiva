#include<bits/stdc++.h>
using namespace std;

string s1;
string s2;
string virus;
string longest = "";
vector<int> longest_indexes;

// Backtracking: Todas las posibles palabras teniendo en cuenta

int main(){
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, virus);

    vector<int> indexes[s1.length()];

    for (int i=0; i<s1.length(); i++){
        for (int j=0; j<s2.length(); j++){
            if  (s1[i] == s2[j]){
                indexes[i].push_back(j);
            }
        }
    }

    // for (int i=0; i<s1.length(); i++){
    //     vector<int> buffer = {};
    //     for (int j=i; j<s1.length(); j++){
    //         for (int k=0; k<indexes[j].size(); k++){
    //             if (buffer.size() == 0 || buffer.back() < indexes[j][k]) {
    //                 buffer.push_back(indexes[j][k]);
    //                 break;
    //             }
    //         }
    //     }
    //     if (longest_indexes.size() < buffer.size()) longest_indexes = buffer;
    // }



    for (int i=0; i<longest_indexes.size(); i++) longest += s2[longest_indexes[i]];

    cout << longest << endl;
    return 0;
}