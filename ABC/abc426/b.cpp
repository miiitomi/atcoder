#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<char, int> mp;
    for (int i = 0; i < (int)S.size(); i++) {
        char c = S[i];
        mp[c]++;
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second == 1) {
            cout << iter->first << "\n";
        }
    }
}
