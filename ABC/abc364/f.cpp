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
    vector<ll> L(Q), R(Q), C(Q), v(Q);
    for (int i = 0; i < Q; i++) {
        cin >> L[i] >> R[i] >> C[i];
        L[i]--; R[i]--;
        v[i] = i;
    }
    sort(v.begin(), v.end(), [&](int l, int r) {return C[l] < C[r];});
    ll ans = 0;
    set<pair<ll,ll>> S;
    for (int i = 0; i < N; i++) S.insert({i, i});

    for (ll q : v) {
        ll l = L[q], r = R[q], c = C[q];
        ans += c;
        auto iter1 = S.lower_bound({l+1, l});
        iter1--;
        auto iter2 = S.lower_bound({l+1, 0});
        while (iter2 != S.end() && (*iter2).first <= r) {
            ans += c;
            S.insert({(*iter1).first, (*iter2).second});
            iter1 = S.erase(iter1);
            iter2 = S.erase(iter2);
        }
    }

    if ((int)S.size() == 1) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
