#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    map<char, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        mp[c].push_back(i);
    }

    while (Q--) {
        char c, d;
        cin >> c >> d;
        if (c == d) continue;
        if ((int)mp[c].size() <= (int)mp[d].size()) {
            while (!mp[c].empty()) {
                mp[d].push_back(mp[c].back());
                mp[c].pop_back();
            }
        } else {
            swap(mp[c], mp[d]);
            while (!mp[c].empty()) {
                mp[d].push_back(mp[c].back());
                mp[c].pop_back();
            }
        }
    }

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        char c = iter->first;
        for (int i : iter->second) {
            S[i] = c;
        }
    }

    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
