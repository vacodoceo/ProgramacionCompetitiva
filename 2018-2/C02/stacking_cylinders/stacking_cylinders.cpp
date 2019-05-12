#include<bits/stdc++.h>
using namespace std;

struct Cylinder {
    double x;
    double y;
};

int main(){
    int n;
    cin >> n;
    vector<Cylinder> layer;
    while (n){
        int l = n;
        double x, y;
        while(n--){
            cin >> x;
            Cylinder c;
            c.x = x; c.y = 1.0;
            bool inserted = 0;
            for (int i=0; i<layer.size(); i++){
                if (layer[i].x > c.x){
                    inserted = 1;
                    layer.insert(layer.begin() + i, c);
                    break;
                }
            }
            if (!inserted) layer.push_back(c);
        }
        // for (int i=0; i<layer.size(); i++){
        //     cout << layer[i].x << " ";
        // }
        // cout << endl;
        while (l-- > 1){
            // cout << "LAYER: " << l << endl;
            for (int i=0; i<l; i++){
                Cylinder c;
                double x_offset = (layer[i].x + layer[i+1].x) / 2;
                double y_offset = (layer[i].y + layer[i+1].y) / 2;
                double x_diff = (layer[i].x - layer[i+1].x);
                double y_diff = (layer[i].y - layer[i+1].y);
                double angle = atan(y_diff / x_diff);
                double base = sqrt(pow(x_diff, 2) + pow(y_diff, 2)) / 2;
                double height = sqrt(4 - pow(base, 2));
                double x_disp = -height*sin(angle);
                double y_disp = height*cos(angle);
                c.x = x_offset + x_disp;
                c.y = y_offset + y_disp;
                layer.push_back(c);
            }
            layer.erase(layer.begin(), layer.begin() + l + 1);
            // cout << "LAYER SIZE: " << layer.size() << endl;
        }
        printf("%.4f %.4f\n", layer[0].x, layer[0].y);

        layer.clear();
        cin >> n;
    }

    return 0;
}