#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    vector<ll> A(N), S(2*N+1, 0), cnt(M, 0);
    for (int i = 0; i < 2*N; i++) {
        if (i <= N-1) {
            cin >> A[i];
            ans += cnt[S[i]%M];
            cnt[S[i]%M]++;
            S[i+1] = S[i] + A[i];
        } else {
            cnt[S[i-N]%M]--;
            ans += cnt[S[i]%M];
            S[i+1] = S[i] + A[i-N];
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
