#include<bits/stdc++.h>

using namespace std;

int main(){
    string buffer;
    string d = " ";
    unordered_map<string, int> memory;
    while (getline(cin, buffer)){
        string op = buffer.substr(0, buffer.find(d));
        buffer.erase(0, buffer.find(d) + 1);
        if (!op.compare("def")){
            string var_name = buffer.substr(0, buffer.find(d));
            buffer.erase(0, buffer.find(d) + 1);
            int value = stoi(buffer);
            if (memory.find(var_name) == memory.end()) memory.emplace(var_name, value);
            else memory[var_name] = value;
        }
        else if (!op.compare("calc")){
            int sum = 0;
            char sign = '+';
            bool printed = 0;
            cout << buffer << " ";
            while(sign != '='){
                int p = buffer.find(d);
                string add_str = buffer.substr(0, p);
                // cout << "add_str: " << add_str << endl;
                if (memory.find(add_str) == memory.end()){
                    cout << "unknown" << endl;
                    printed = 1;
                    break;
                }
                int add = memory[add_str];
                if (sign == '-') add *= -1;
                sum += add;
                sign = buffer[p + 1];
                buffer.erase(0, p + 3);
            }
            if (printed) continue;
            for (auto it = memory.begin(); it != memory.end(); ++it){
                if (it->second == sum){
                    cout << it->first << endl;
                    printed = 1;
                    break;
                }
            }
            if (!printed) {
                cout << "unknown" << endl;
            }
        }
        else if (!op.compare("clear")){
            memory.clear();
        }
    }

    return 0;
}