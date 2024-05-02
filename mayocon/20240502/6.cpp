// https://atcoder.jp/contests/abc231/tasks/abc231_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, X;
vector<ll> A;
map<pair<ll, ll>, ll> mp;

ll f(ll Y, ll i) {
    if (mp.count(make_pair(Y, i))) return mp[make_pair(Y, i)];
    if (Y % A[i] == 0) return mp[make_pair(Y, i)] = Y/A[i];
    ll tmp = Y / A[i];
    return mp[make_pair(Y, i)] = min(tmp + f(Y - tmp*A[i], i-1), tmp+1+f((tmp+1)*A[i]-Y, i-1));
}

void solve() {
    cin >> N >> X;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << f(X, N-1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
