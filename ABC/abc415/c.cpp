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
    string S;
    cin >> S;

    if (S.back() == '1') {
        cout << "No\n";
        return;
    }

    vector<bool> dp(1LL << N, false);
    dp[0] = true;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int s = Q.front();
        Q.pop();
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) continue;
            int t = s ^ (1 << i);
            if (S[t-1] == '0' && !dp[t]) {
                dp[t] = true;
                Q.push(t);
                if (t == ((1LL << N)-1)) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
