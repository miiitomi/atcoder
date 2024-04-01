// https://atcoder.jp/contests/abc155/tasks/abc155_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<string, int> mp;
    while (N--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int mv = -1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        mv = max(mv, iter->second);
    }

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second == mv) {
            cout << iter->first << "\n";
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
