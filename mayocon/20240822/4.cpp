// https://atcoder.jp/contests/abc330/tasks/abc330_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    map<ll, ll> cnt;
    set<ll> EX;
    for (int x = 0; x <= N+1; x++) EX.insert(x);
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        cnt[a]++;
        if (EX.count(a)) EX.erase(a);
    }
    while (Q--) {
        ll i, x;
        cin >> i >> x;
        i--;
        ll a = A[i];
        cnt[a]--;
        if (cnt[a] == 0) EX.insert(a);
        cnt[x]++;
        if (EX.count(x)) EX.erase(x);
        A[i] = x;
        ll ans = *EX.begin();
        cout << ans << "\n";
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
