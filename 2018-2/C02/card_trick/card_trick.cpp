#include<bits/stdc++.h>
using namespace std;

string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
char suits[4] = {'C', 'D', 'H', 'S'};

string value(string card){
    stringstream ss1;
    string v1;
    ss1 << card[0];
    if (card[1] == '0') ss1 << card[1];
    ss1 >> v1;
    return v1;
};

string first_card(string c1, string c2, int* diff){
    string v1, v2;
    int i1, i2;
    v1 = value(c1);
    v2 = value(c2);

    int found = 0;
    for (int i=0; i<13; i++){
        if (v1 == values[i]) {
            i1 = i;
            found++;
        }
        else if (v2 == values[i]) {
            i2 = i;
            found++;
        }
        if (found == 2){
            break;
        }
    }

    if (i2 < i1){
        swap(i2, i1);
        swap(c1, c2);
    }

    *diff = i2 - i1;
    if (*diff > 6){
        *diff = 13 - (i2 - i1);
        return c1;
    }
    return c2;
}

string get_smallest(vector<string> cards){
    vector<string> less_suit;
    bool match = false;
    for(int i=0; i<13; i++){
        for(int j=0; j<cards.size(); j++){
            if (value(cards[j]) == values[i]){
                match = 1;
                less_suit.push_back(cards[j]);
            }
        }
        if (match) break;
    }

    // cout << "LESS: " << endl;
    // for(int j=0; j<less_suit.size(); j++){
        // cout << less_suit[j] << endl;
    // }
    // cout << "====" << endl;

    for(int i=0; i<4; i++){
        for(int j=0; j<less_suit.size(); j++){
            if (less_suit[j].back() == suits[i]){
                return less_suit[j];
            }
        }
    }
};

int main(){
    int n;
    vector<string> cards;
    string buffer;
    string output[5];
    int c1, c2;
    cin >> n;

    while(n--){
        int diff;
        for (int i=0; i<5; i++){
            cin >> buffer;
            cards.push_back(buffer);
        }
        bool match = 0;
        for (int i=0; i<cards.size()-1; i++){
            for (int j=i+1; j<cards.size(); j++){
                if (cards[i].back() == cards[j].back()){
                    match = 1;
                    c1 = i; c2 = j;
                    break;
                }
            }
            if (match) break;
        }
        // cout << "MATCH SUITS: " << cards[c1] << " - " << cards[c2] << endl;
        output[0] = first_card(cards[c1], cards[c2], &diff);
        output[1] = (cards[c1] == output[0]) ? cards[c2] : cards[c1];
        // cout << "FIST CARD: " << output[0] << endl;
        // cout << "SECOND CARD: " << output[1] << endl;
        cards[c1].erase(); cards[c2].erase();
        // cout << "DIFF: " << diff << endl;

        string smallest = get_smallest(cards);
        // cout << "SMALLEST: " << smallest << endl;

        int pos;
        for (int i=0; i<cards.size(); i++){
            if (cards[i] == smallest){
                pos = (diff - 1) % 3 + 2;
                output[pos] = cards[i];
                cards[i].erase();
                break;
            }
        }
        smallest = get_smallest(cards);
        for (int i=0; i<cards.size(); i++){
            if (cards[i] == smallest){
                cards[i].erase();
                break;
            }
        }
        string greatest = get_smallest(cards);
        // cout << "REMAINING: " << smallest << " - " << greatest << endl;

        // cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << " " << output[4] << endl;


        // cout << "SMALLEST: " << smallest << endl;
        int order = diff / 4; // 1 to min then max, 0 to max then min
        for (int i=2; i<5; i++) {
            if (pos != i){
                output[i] = order ? greatest : smallest;
                int j = (i+1 == pos) ? i+2 : i+1;
                output[j] = order ? smallest : greatest;
                break;
            }
        }

        cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << " " << output[4] << endl;
        for (int i=0; i<5; i++){
            output[i] = "";
        }

        cards.clear();
    }

    return 0;
}