// https://atcoder.jp/contests/abc146/tasks/abc146_f
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
    string S;
    cin >> S;
    ll cnt = 0, tmp = 0;
    vector<ll> v;
    for (int i = 0; i <= N; i++) {
        char c = S[i];
        if (c == '1') tmp++;
        else {
            cnt = max(cnt, tmp);
            tmp = 0;
            v.push_back(i);
        }
    }
    cnt = max(cnt, tmp);
    if (cnt >= M) {
        cout << -1 << endl;
        return;
    }

    vector<ll> ans;
    ll x = N;
    while (x != 0) {
        auto iter = lower_bound(v.begin(), v.end(), x-M);
        ll y = *iter;
        ans.push_back(x-y);
        x = y;
    }
    reverse(ans.begin(), ans.end());
    for (ll a : ans) cout << a << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
