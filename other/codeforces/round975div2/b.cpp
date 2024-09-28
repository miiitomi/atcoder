#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N), K(Q);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < Q; i++) cin >> K[i];
    map<ll, ll> cnt;
    for (ll i = 0; i < N; i++) {
        ll tmp = (i+1) * (N-i) - 1;
        cnt[tmp]++;
        if (i == N-1) break;
        ll c = X[i+1]-X[i]-1;
        tmp = (i+1) * (N-i-1);
        cnt[tmp] += c;
    }
    for (int q = 0; q < Q; q++) {
        cout << cnt[K[q]];
        if (q == Q-1) cout << "\n";
        else cout << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
