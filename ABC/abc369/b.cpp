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
    vector<int> A(N);
    vector<char> S(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> S[i];

    ll ans = INF;
    for (int ls = 0; ls <= 100; ls++) {
        for (int rs = 0; rs <= 100; rs++) {
            int l = ls, r = rs;
            ll tmp = 0;
            for (int i = 0; i < N; i++) {
                if (S[i] == 'L') {
                    tmp += abs(l - A[i]);
                    l = A[i];
                } else {
                    tmp += abs(r - A[i]);
                    r = A[i];
                }
            }
            ans = min(ans, tmp);
        }
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
