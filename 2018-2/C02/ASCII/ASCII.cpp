#include<bits/stdc++.h>

using namespace std;

// Orden de posiciones a comparar para determinar que dígito es.
// ..1..
// 2...3
// .....
// ..4..
// 5...6
// .....
// ..7..

string ASCII[10] = {"xxxxx\nx...x\nx...x\nx...x\nx...x\nx...x\nxxxxx", "....x\n....x\n....x\n....x\n....x\n....x\n....x", 
"xxxxx\n....x\n....x\nxxxxx\nx....\nx....\nxxxxx", "xxxxx\n....x\n....x\nxxxxx\n....x\n....x\nxxxxx",
"x...x\nx...x\nx...x\nxxxxx\n....x\n....x\n....x", "xxxxx\nx....\nx....\nxxxxx\n....x\n....x\nxxxxx", 
"xxxxx\nx....\nx....\nxxxxx\nx...x\nx...x\nxxxxx", "xxxxx\n....x\n....x\n....x\n....x\n....x\n....x",
"xxxxx\nx...x\nx...x\nxxxxx\nx...x\nx...x\nxxxxx", "xxxxx\nx...x\nx...x\nxxxxx\n....x\n....x\nxxxxx"};


// char one[7] = {'.', '.', 'x' ,'.', '.', 'x', '.'}, two[7] = {'x', '.', 'x' ,'x', 'x', '.', 'x'}, three[7] = {'x', '.', 'x' ,'x', '.', 'x', 'x'};
// char four[7] = {'.', 'x', 'x' ,'x', '.', 'x', '.'}, five[7] = {'x', 'x', '.' ,'x', '.', 'x', 'x'}, six[7] = {'x', 'x', '.' ,'x', 'x', 'x', 'x'};
// char seven[7] = {'x', '.', 'x' ,'.', '.', 'x', '.'}, eight[7] = {'x', 'x', 'x' ,'x', 'x', 'x', 'x'}, nine[7] = {'x', 'x', 'x' ,'x', '.', 'x', '.'};
// char zero[7] = {'x', 'x', 'x' ,'.', 'x', 'x', 'x'};
char digits[10][7] = {{'x', 'x', 'x' ,'.', 'x', 'x', 'x'}, {'.', '.', 'x' ,'.', '.', 'x', '.'}, {'x', '.', 'x' ,'x', 'x', '.', 'x'},
                      {'x', '.', 'x' ,'x', '.', 'x', 'x'}, {'.', 'x', 'x' ,'x', '.', 'x', '.'}, {'x', 'x', '.' ,'x', '.', 'x', 'x'},
                      {'x', 'x', '.' ,'x', 'x', 'x', 'x'}, {'x', '.', 'x' ,'.', '.', 'x', '.'}, {'x', 'x', 'x' ,'x', 'x', 'x', 'x'},
                      {'x', 'x', 'x' ,'x', '.', 'x', 'x'}};

bool arrayEqual(char a1[7], char a2[7]){
        for (int j=0; j<10; j++){
            for (int k=0; k<7; k++){
                if (a1[k] != a2[k]){
                    return false; 
                }
            }
        }
    return true;
}

string a[7];

int main(){
    for(int i=0; i<7; i++){
        getline(cin, a[i]);
    }

    int l = (a[0].length() + 1) / 6; 
    stringstream output[7];
    stringstream n1, n2;
    bool sum = 0;
    int k = 0;

    for (int i=0; i<l; i++, k++){
        char digits_bar[7] = {a[0][i*6 + 2], a[1][i*6], a[1][i*6 + 4], a[3][i*6 + 2], a[4][i*6], a[4][i*6 + 4], a[6][i*6 + 2]};
        bool found = 0;
        for (int j=0; j<10; j++){
            if (arrayEqual(digits_bar, digits[j])){
                if (!sum) {n1 << j;}
                else {n2 << j;}
                found = 1;
            }
        } 
        if (!found) {sum = 1; k = 0;}
    }
    long int n1_int, n2_int, ans;
    n1 >> n1_int; n2 >> n2_int;
    ans = n1_int + n2_int;
    string ans_string = to_string(ans);
    for(int i=0; i<ans_string.length(); i++){
        for(int j=0; j<7; j++){
            for(int k=0; k<5; k++){
                output[j] << ASCII[ans_string[i] - '0'][6*j + k];
            }
            if (i < ans_string.length() - 1){
                output[j] << ".";
            }
        }
    }
    for(int i=0; i<7; i++){
        cout << output[i].str() << endl;
    }
    return 0;
};