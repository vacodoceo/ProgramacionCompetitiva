#include <bits/stdc++.h>

using namespace std;

string eq, expr1_s, expr2_s;
array<int, 17> expr1, expr2, pol;
int min_b;

array<int, 17> solve_mults(string s){
    array<int, 17> ret = {0};
    size_t pos = s.find('*');
    if (pos != string::npos){
        // Setting the first number
        string n = s.substr(0, pos);
        for (int i=0; i<n.size(); i++){
            int g = n.size()-i-1;
            ret[g] = (int) n[i] - '0';
        }

        // Multiplying
        while (pos != string::npos){
            string n;
            if (s.find('*', pos+1) == string::npos) n = s.substr(pos + 1);
            else n = s.substr(pos + 1, s.find('*', pos+1) - pos - 1);
            array<int, 17> mult_result = {0};
            for (int i=0; i<n.size(); i++){
                int g = n.size()-i-1;
                for (int j=0; j<17-g; j++){
                    mult_result[j+g] += ret[j] * (int) (n[i] - '0');
                }
            }
            ret = mult_result;
            pos = s.find('*', pos+1);
        }
        return ret;
    }
    else {
        // Case where there's no multiplication
        for (int i=0; i<s.size(); i++){
            int g = s.size()-i-1;
            ret[g] = (int) s[i] - '0';
        }
        return ret;
    }
}

array<int, 17> solve_sums(string expr){
    array<int, 17> ret = {0};
    size_t pos = expr.find('+');

    // Setting first number
    string s = expr.substr(0, pos);
    array<int, 17> n = solve_mults(s);
    for (int i=0; i<17; i++){
        ret[i] += n[i];
    }

    // Iterative sum
    while (pos != string::npos){
        string s;
        if (expr.find('+', pos+1) == string::npos) s = expr.substr(pos + 1);
        else s = expr.substr(pos + 1, expr.find('+', pos+1) - pos - 1);
        array<int, 17> n = solve_mults(s);
        for (int i=0; i<17; i++){
            ret[i] += n[i];
        }
        pos = expr.find('+', pos+1);
    }
    
    return ret;
}

// Substract 2 array expresions
array<int, 17> diff_expr(array<int, 17> expr1, array<int, 17> expr2){
    array<int, 17> ret = expr1;
    for (int i=0; i<17; i++){
        ret[i] -= expr2[i];
    }
    return ret;
}

int main(){
    while (getline(cin, eq)){
        if(eq.find('=')){
            // Get min base
            min_b = 1;
            for (auto& c: eq){
                if (c != '=' && c != '*' && c != '+'){
                    min_b = max((int) c - '0', min_b);
                }
            }
            min_b++;

            // Solve equation
            expr1_s = eq.substr(0, eq.find('='));
            expr2_s = eq.substr(eq.find('=')+1);
            expr1 = solve_sums(expr1_s);
            expr2 = solve_sums(expr2_s);
            pol = diff_expr(expr1, expr2);

            // Get bases
            // Shift left array to ignore x=0 solutions
            int c = 0;
            while (pol[0] == 0 && c < 17){
                array<int, 17> new_pol = {0};
                for (int i=0; i<16; i++){
                    new_pol[i] = pol[i+1];
                }
                pol = new_pol;
                c++;
            }

            // Check pol properties
            bool no_base = pol[0] != 0;
            int grade = 0;
            for (int i=1; i<17; i++){
                if (pol[i] != 0){
                    no_base = 0;
                    grade = i;
                }
            }

            //  No base case
            if (no_base) cout << "*" << endl;
            else if (!no_base && !grade) printf("%i+\n", min_b);

            // Get possible solutions
            else {
                vector<int> ps, qs;
                for (int p=1; p<=sqrt(abs(pol[0])); p++){
                    if (abs(pol[0]) % p == 0){
                        if (abs(pol[0])/p == p) ps.push_back(p);
                        else {
                            ps.push_back(p);
                            ps.push_back(abs(pol[0])/p);
                        }
                    }
                    if (abs(pol[grade]) >= p && pol[grade] % p == 0){
                        if (abs(pol[grade])/p == p) qs.push_back(p);
                        else {
                            qs.push_back(p);
                            qs.push_back(abs(pol[grade]/p));
                        }
                    }
                }

                //  Try solutions
                set<int> sols;
                set<int> tried;
                for (auto& p: ps){
                    for (auto& q: qs){
                        if (p % q == 0 && p / q >= min_b && tried.find(p/q) == tried.end()){
                            int base = p / q;
                            long long int sum = 0;
                            for (int i=0; i<17; i++){
                                sum += pol[i]*pow(base, i);
                            }
                            if (!sum) sols.insert(base);
                            tried.insert(base);
                        }
                    }
                }
                if (!sols.size()) cout << "*" << endl;
                else {
                    for (auto& s: sols){
                        cout << s << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}