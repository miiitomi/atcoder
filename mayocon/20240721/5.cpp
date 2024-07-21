// https://atcoder.jp/contests/abc312/tasks/abc312_f
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
    priority_queue<ll> O, C, opener;
    for (int i = 0; i < N; i++) {
        ll t, x;
        cin >> t >> x;
        if (t == 0) O.push(x);
        if (t == 1) C.push(x);
        if (t == 2) opener.push(x);
    }

    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    ll tmp = 0;
    while (!O.empty() && (ll)PQ.size() < M) {
        ll x = O.top();
        O.pop();
        PQ.push(x);
        tmp += x;
    }

    ll ans = tmp;
    ll L = opener.size();
    for (ll k = 1; k <= min(L, M-1); k++) {
        ll l = opener.top();
        opener.pop();
        for (int t = 0; (t<l) && !C.empty(); t++) {
            ll x = C.top();
            C.pop();
            O.push(x);
        }

        while ((int)PQ.size() + k > M) {
            ll y = PQ.top();
            PQ.pop();
            tmp -= y;
        }

        while (!O.empty() && (ll)PQ.size()+k < M) {
            ll y = O.top();
            O.pop();
            PQ.push(y);
            tmp += y;
        }

        while (!O.empty() && !PQ.empty() && PQ.top() < O.top()) {
            tmp += O.top() - PQ.top();
            PQ.pop();
            PQ.push(O.top());
            O.pop();
        }

        ans = max(ans, tmp);
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
