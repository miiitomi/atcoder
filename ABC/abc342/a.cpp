#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    map<char,vector<int>> mp;
    for (int i = 0; i < (int)S.size(); i++) {
        char c = S[i];
        mp[c].push_back(i+1);
    }

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second.size() == 1) {
            cout << *(iter->second.begin()) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
