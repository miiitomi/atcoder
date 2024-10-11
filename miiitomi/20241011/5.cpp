// https://atcoder.jp/contests/abc166/tasks/abc166_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    vector<int> v(3);
    cin >> N >> v[0] >> v[1] >> v[2];
    vector<vector<int>> S(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "AB") S[i] = {0, 1};
        else if (s == "BC") S[i] = {1, 2};
        else S[i] = {2, 0};
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        if (v[S[i][0]] + v[S[i][1]] == 0) {
            cout << "No\n";
            return;
        }
        if (v[S[i][0]] == 0 || (v[S[i][1]] != 0 && (i+1 < N && S[i] != S[i+1] && S[i][0] == S[i+1][1]))) {
            ans[i] = S[i][0];
            v[S[i][0]]++;
            v[S[i][1]]--;
        } else {
            ans[i] = S[i][1];
            v[S[i][1]]++;
            v[S[i][0]]--;
        }
    }

    cout << "Yes\n";
    for (int i : ans) cout << (char)('A' + i) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
