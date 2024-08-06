// https://atcoder.jp/contests/abc272/tasks/abc272_e
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> V(M+1);

    for (int i = 0; i < N; i++) {
        if (A[i] + (i+1) > N) continue;
        ll l = 1;
        if (A[i] + (i+1) < 0) {
            ll r = M+1;
            while (r - l > 1) {
                ll m = (l + r)/2;
                if (A[i] + m*(i+1) < 0) l = m;
                else r = m;
            }
            l = r;
        }
        while (l <= M && A[i]+l*(i+1) <= N) {
            V[l].push_back(A[i]+l*(i+1));
            l++;
        }
    }

    for (int i = 1; i <= M; i++) {
        sort(V[i].begin(), V[i].end());
        V[i].erase(unique(V[i].begin(), V[i].end()), V[i].end());
        for (int x = 0; x <= N; x++) {
            if ((int)V[i].size() <= x || V[i][x] != x) {
                cout << x << "\n";
                break;
            }
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
