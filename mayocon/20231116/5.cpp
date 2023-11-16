// https://atcoder.jp/contests/abc138/tasks/abc138_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S, T;
    cin >> S >> T;

    vector<vector<int>> idxs(26);
    for (int i = 0; i < (int)S.size(); i++) {
        char c = S[i];
        idxs[c-'a'].push_back(i);
    }
    for (int c : T) {
        if (idxs[c-'a'].empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll K = 0, i = 0;
    for (char c : T) {
        int x = c - 'a';
        auto iter = lower_bound(idxs[x].begin(), idxs[x].end(), i);
        if (iter == idxs[x].end()) {
            K++;
            i = idxs[x][0] + 1;
        } else {
            i = *iter + 1;
        }
    }

    if (i == S.size()) {
        i = 0;
        K++;
    }

    K *= (ll)S.size();
    cout << K + i << endl;
}
