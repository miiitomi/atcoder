#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<ll> L(M+1, 0), R(M+1, 0);
    for (int i = 1; i <= M; i++) {
        cin >> L[i] >> R[i];
        if (R[i] - L[i] + 1 >= B) {
            cout << "No\n";
            return;
        }
    }
    M++;

    if (A == B) {
        bool ok = ((N % A) == (1 % A));
        for (int i = 1; i < M && ok; i++) {
            for (ll j = L[i]; j <= R[i] && ok; j++) {
                if ((j % A) == (1 % A)) ok = false;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    L.push_back(N+1);
    R.push_back(N+1);
    vector<ll> v(1, 1);

    vector<bool> dp(A*A + 1, false);
    dp[0] = true;
    for (int x = 0; x < A*A; x++) {
        if (!dp[x]) continue;
        for (int y = x + A; y <= min(x + B, A*A); y++) {
            dp[y] = true;
        }
    }

    for (int i = 0; i < M; i++) {
        for (ll x = max(R[i]+1, v.back()+1); x <= min(R[i]+B, L[i+1]-1); x++) {
            bool ok = false;
            for (int j = v.size()-1; j >= 0 && !ok; j--) {
                if (x - v[j] > B) break;
                if (x - v[j] < A) continue;
                ok = true;
            }
            if (ok) v.push_back(x);
        }

        for (ll x = max(v.back()+1, L[i+1]-B); x <= L[i+1]-1; x++) {
            bool ok = false;
            for (int j = v.size()-1; j >= 0 && !ok; j--) {
                ll y = v[j];
                if (y <= R[i]) break;
                if (x-y > A*A || dp[x-y]) ok = true;
            }
            if (ok) v.push_back(x);
        }
    }

    if (v.back() == N) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
