// https://atcoder.jp/contests/abc080/tasks/abc080_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> w(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> w[i][0] >> w[i][1] >> w[i][2];
        w[i][2]--;
    }
    sort(w.begin(), w.end());
    vector<vector<pair<int, int>>> V(C);
    for (int i = 0; i < N; i++) {
        int c = w[i][2];
        if (V[c].empty() || V[c].back().second != w[i][0]) V[c].push_back(make_pair(w[i][0], w[i][1]));
        else V[c].back().second = w[i][1];
    }
    vector<int> S(1e+5+1, 0);
    for (int c = 0; c < C; c++) {
        for (pair<int, int> p : V[c]) {
            S[p.first-1]++;
            S[p.second]--;
        }
    }
    for (int i = 1; i <= (int)1e+5; i++) {
        S[i] += S[i-1];
    }

    cout << *max_element(S.begin(), S.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
