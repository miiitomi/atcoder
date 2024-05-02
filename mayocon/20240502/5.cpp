// https://atcoder.jp/contests/abc138/tasks/abc138_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S, T;
    cin >> S >> T;
    vector<vector<int>> V(26);
    for (int i = 0; i < (int)S.size(); i++) V[S[i]-'a'].push_back(i);
    ll x = 0, y = -1;
    for (char c : T) {
        int t = c - 'a';
        if (V[t].empty()) {
            cout << -1 << "\n";
            return;
        }
        auto iter = lower_bound(V[t].begin(), V[t].end(), y+1);
        if (iter == V[t].end()) {
            x++;
            y = V[t][0];
        } else {
            y = *iter;
        }
    }
    cout << (ll)S.size() * x + y + 1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
