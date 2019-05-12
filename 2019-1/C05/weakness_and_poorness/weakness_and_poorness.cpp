#include <bits/stdc++.h>

using namespace std;

vector<double> seq;
double segment_spike, max_spike, min_spike, x;
long int min_spike_s, max_spike_s;

void getMinMax(){
    double current_max_spike, current_min_spike;
    long int current_max_spike_s, current_min_spike_s;
    current_max_spike = max_spike = -1e28;
    current_min_spike = min_spike = 1e20;
    current_max_spike_s = current_min_spike_s = min_spike_s = max_spike_s = 0;
    for (auto& a: seq){
        if (current_max_spike + a - x > a - x){
            current_max_spike += a - x;
            current_max_spike_s++;
        }
        else {
            current_max_spike = a - x;
            current_max_spike_s = 1;
        }
        if (current_max_spike > max_spike){
            max_spike = current_max_spike;
            max_spike_s = current_max_spike_s;
        }
        if (current_min_spike + a - x < a - x){
            current_min_spike += a - x;
            current_min_spike_s++;
        }
        else {
            current_min_spike = a - x;
            current_min_spike_s = 1;
        }
        if (current_min_spike < min_spike){
            min_spike = current_min_spike;
            min_spike_s = current_min_spike_s;
        }
    }
}

int main(){
    long int n;
    cin >> n;
    int buff;
    for (int i=0; i<n; i++){
        cin >> buff;
        seq.push_back(buff);
    }
    x = 0;
    for (int t=0; t<10; t++){
        getMinMax(); // Calculate max and min spike value and segment size
        double x2 = (double)(max_spike + min_spike) / (max_spike_s + min_spike_s);
        // printf("X2 CALCULATED : %f\n", x2);
        if (!t) x = x2;
        else x += x2;

        // printf("MAX_SPIKE: %f at %li | MIN_SPIKE: %f at %li\n", max_spike, max_spike_s, min_spike, min_spike_s);
        // printf("x: %f\n", x);
        // for (auto& a: seq){
        //     cout << a - x<< " ";
        // }
        // cout << endl;
    }
    printf("%.15f\n", (abs(max_spike) > abs(min_spike) ? abs(max_spike) : abs(min_spike)));
    return 0;
}