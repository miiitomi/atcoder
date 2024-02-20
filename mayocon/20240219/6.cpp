// https://atcoder.jp/contests/abc155/tasks/abc155_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
vector<ll> M, Z, P;

ll f(ll x) {
    if (x == 0) {
        ll ans = (ll)M.size() * (ll)P.size();
        ans += (ll)Z.size() * (N - (ll)Z.size());
        ans += (ll)Z.size() * ((ll)(Z.size()) - 1) / 2;
        return ans;
    }
    if (x < 0) {
        x = -x;
        ll ans = 0;
        for (ll a : P) {
            auto iter = lower_bound(M.begin(), M.end(), (x + a - 1)/a);
            ans += distance(iter, M.end());
        }
        return ans;
    }


    ll ans = (ll)M.size() * (ll)P.size();
    ans += (ll)Z.size() * (N - (ll)Z.size());
    ans += (ll)Z.size() * ((ll)(Z.size()) - 1) / 2;

    for (auto it = M.begin(); it != M.end(); it++) {
        ll a = *it;
        auto iter = lower_bound(M.begin(), M.end(), x/a + 1);
        if (iter <= it) continue;
        ans += distance(it, iter) - 1;
    }

    for (auto it = P.begin(); it != P.end(); it++) {
        ll a = *it;
        auto iter = lower_bound(P.begin(), P.end(), x/a + 1);
        if (iter <= it) continue;
        ans += distance(it, iter) - 1;
    }
    return ans;
}


void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (a > 0) P.push_back(a);
        else if (a < 0) M.push_back(-a);
        else Z.push_back(a);
    }
    sort(P.begin(), P.end());
    sort(M.begin(), M.end());
    sort(Z.begin(), Z.end());

    ll left = -2e+18, right = 2e+18;
    while (right - left > 1) {
        ll x = (right + left) / 2;
        if (f(x) < K) left = x;
        else right = x;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
