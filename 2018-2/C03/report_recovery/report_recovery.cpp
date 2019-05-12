// Pendent: sum of sales equal to TP

#include<bits/stdc++.h>
using namespace std;

vector<string> to_print;

int parse_header(string h){
    // cout << h << endl;
    int N = 0;
    for (int i=0; i<h.size(); i++){
        if (h[i] == 'P') N++;
    }
    for (int i=0; i<N; i++){
        cout << "P" << i+1 << " ";
    }
    puts("Totals");
    return N;
}

vector<vector<int>> get_sales(string s, int N, int TP){
    vector<vector<int>> output;
    int len = s.size();
    int c = 0;
    // cout << "LEN: " << len << endl;
    for (int i=1; i<4+TP & i<len; i++){
        if (N > 1){
            for (int j=i+1; j<i+4+TP & j<len; j++){
                if (s[i] == '0' & j-i > 1) continue;
                if (N > 2){
                    for (int k=j+1; k<j+4+TP & k<len; k++){
                        if (s[j] == '0' & k-j > 1) continue;
                        if (N > 3){
                            for (int l=k+1; l<k+4+TP & l<len; l++){
                                if (s[k] == '0' & l-k > 1) continue;
                                if (N > 4){
                                    for (int m=l+1; m<l+4+TP & m<len; m++){
                                        if (s[l] == '0' & m-l > 1) continue;
                                        // printf("i: %i - j: %i - k: %i - l: %i - m: %i - f: %i\n", i, j, k, l, m, len);
                                        if (len-m < 5 + TP){
                                            if(stoi(s.substr(0, i)) + stoi(s.substr(i, j-i)) + stoi(s.substr(j, k-j)) + stoi(s.substr(k, l-k)) + stoi(s.substr(l, m-l)) == stoi(s.substr(m, len-m))){
                                                output.emplace_back();
                                                output[c].push_back(stoi(s.substr(0, i)));
                                                output[c].push_back(stoi(s.substr(i, j-i)));
                                                output[c].push_back(stoi(s.substr(j, k-j)));
                                                output[c].push_back(stoi(s.substr(k, l-k)));
                                                output[c].push_back(stoi(s.substr(l, m-l)));
                                                output[c].push_back(stoi(s.substr(m, len-m)));
                                                c++;
                                            }
                                        }
                                    }
                                }
                                else if (len-l < 4 + TP){
                                    if (stoi(s.substr(0, i)) + stoi(s.substr(i, j-i)) + stoi(s.substr(j, k-j)) + stoi(s.substr(k, l-k)) == stoi(s.substr(l, len-l))){
                                        // cout << s.substr(0, i) << " - " << s.substr(i, j-i) << " - " << s.substr(j, k-j) << " - " << s.substr(k, l-k)  << " - " << s.substr(l, len-l) << endl;
                                        output.emplace_back();
                                        output[c].push_back(stoi(s.substr(0, i)));
                                        output[c].push_back(stoi(s.substr(i, j-i)));
                                        output[c].push_back(stoi(s.substr(j, k-j)));
                                        output[c].push_back(stoi(s.substr(k, l-k)));
                                        output[c].push_back(stoi(s.substr(l, len-l)));
                                        c++;
                                    }
                                }
                            }
                        }
                        else if (len-k < 4 + TP){
                            // printf("i: %i - j: %i - k: %i - f: %i\n", i, j, k, len-k);
                            // cout << s.substr(0, i) << " - " << s.substr(i, j-i) << " - " << s.substr(j, k-j) << " - " << s.substr(k, len-k) << endl;
                            if (stoi(s.substr(0, i)) + stoi(s.substr(i, j-i)) + stoi(s.substr(j, k-j)) == stoi(s.substr(k, len-k))){
                                // cout << s.substr(0, i) << " - " << s.substr(i, j-i) << " - " << s.substr(j, k-j) << " - " << s.substr(k, len-k) << endl;
                                output.emplace_back();
                                output[c].push_back(stoi(s.substr(0, i)));
                                output[c].push_back(stoi(s.substr(i, j-i)));
                                output[c].push_back(stoi(s.substr(j, k-j)));
                                output[c].push_back(stoi(s.substr(k, len-k)));
                                c++;
                            }
                        }
                    }
                }
                else if (len-j < 4 + TP){
                    // printf("i: %i - j: %i - f: %i\n", i, j, len-j);
                    // cout << s.substr(0, i) << " - " << s.substr(i, j-i) << " - " << s.substr(j, len-j) << endl;
                    if (stoi(s.substr(0, i)) + stoi(s.substr(i, j-i)) == stoi(s.substr(j, len-j))){
                        cout << s.substr(0, i) << " - " << s.substr(i, j-i) << " - " << s.substr(j, len-j) << endl;
                        output.emplace_back();
                        output[c].push_back(stoi(s.substr(0, i)));
                        output[c].push_back(stoi(s.substr(i, j-i)));
                        output[c].push_back(stoi(s.substr(j, len-j)));
                        c++;
                    }
                }
            }
        }
        else{
            output.emplace_back();
            output[c].push_back(stoi(s.substr(0, len/2)));
            output[c].push_back(stoi(s.substr(len/2, len/2)));
            c++;
        }
    }
    // for (int i=0; i<c; i++){
    //     for (int j=0; j<5; j++){
    //         cout << output[i][j] << " ";
    //     }
    //     puts("");
    // }
    puts("LAWEAA");

    return output;
}

string get_report(string r, int N, vector<vector<int>> * reports, string * seller){
    int s = 0;
    bool f = 0;
    for (int i=0; i<r.size(); i++){
        if (isdigit(r[i])){
            s = i;
            f = 1;
            break;
        }
        if (f) break;
    }
    *seller = r.substr(0, s);
    int TP = 0;
    if (*seller == "TP") TP = 1;
    *reports = get_sales(r.substr(s, r.size() - s), N, TP);
    return *seller;
}



bool check_combination(int * sum, int s, int S, vector<vector<int>> * reports, string * sellers, int N){
    bool valid;
    for (int j=0; j<reports[s].size(); j++){
        if (s == S-1){
            valid = 1;
            for (int n=0; n<N+1; n++){
                // printf("COMPARING %i with %i\n", sum[n], reports[s][j][n]);
                if (sum[n] != reports[s][j][n]) {
                    valid = 0;
                    break;
                };
            }
            if (valid) {
                string row = sellers[s] + " ";
                for (int n=0; n<N+1; n++){
                    row += to_string(reports[s][j][n]) + " ";
                }
                to_print.insert(to_print.begin(), row);
                return 1;
            }
        }
        else {
            int * check_sum;
            check_sum = new int [N+1];
            for (int n=0; n<N+1; n++){
                check_sum[n] = sum[n];
            }
            for (int n=0; n<N+1; n++){
                check_sum[n] += reports[s][j][n];
            }
            if (check_combination(check_sum, s+1, S, reports, sellers, N)) {
                string row = sellers[s] + " ";
                for (int n=0; n<N+1; n++){
                    row += to_string(reports[s][j][n]) + " ";
                }
                to_print.insert(to_print.begin(), row);
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int C;
    scanf("%i\n", &C);
    for (int i=0; i<C; i++){
        string h;
        getline(cin, h);
        int N = parse_header(h); // return N and print header
        string r;
        string * sellers;
        sellers = new string [5];
        vector<vector<int>> * reports;
        reports = new vector<vector<int>> [5];
        int s = 0;
        while(++s){
            getline(cin, r);
            if (get_report(r, N, &reports[s-1], &sellers[s-1]) == "TP") break;
        }

        int * sum;
        sum = new int [N+1];
        for (int n=0; n<N+1; n++){
            sum[n] = 0;
        }

        check_combination(sum, 0, s, reports, sellers, N);
        for (int j=0; j<s; j++){
            cout << to_print[j] << endl;
        }
        to_print.clear();
    }
    return 0;
}