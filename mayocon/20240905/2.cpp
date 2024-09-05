// https://atcoder.jp/contests/abc310/tasks/abc310_c
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
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        string T = S[i];
        reverse(T.begin(), T.end());
        if (T < S[i]) swap(T, S[i]);
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
