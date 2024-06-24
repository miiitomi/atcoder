// https://atcoder.jp/contests/abc295/tasks/abc295_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> V((1 << 10));
    int s = 0;
    V[0].push_back(0);
    for (int i = 1; i <= N; i++) {
        int k = S[i-1] - '0';
        s ^= (1 << k);
        V[s].push_back(i);
    }
    ll ans = 0;
    s = 0;
    for (int i = 0; i < N; i++) {
        ans += distance(lower_bound(V[s].begin(), V[s].end(), i+1), V[s].end());
        int k = S[i] - '0';
        s ^= (1 << k);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
