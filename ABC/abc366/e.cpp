#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, D;

vector<ll> f(vector<ll> &v) {
    sort(v.begin(), v.end());
    ll x = v[0];
    ll tmp = 0;
    for (ll i = 0; i < N; i++) tmp += (v[i] - x);
    while (tmp < D) {
        x--;
        tmp += N;
    }
    ll left = 0, right = N;
    ll nxt = 0;
    vector<ll> ans;
    while (true) {
        if (tmp <= D) ans.push_back(tmp);
        else if (nxt == N) break;
        while (nxt < N && x == v[nxt]) {
            nxt++;
            right--;
            left++;
        }
        x++;
        tmp += left - right;
    }
    return ans;
}

void solve() {
    cin >> N >> D;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<ll> A = f(x), B = f(y);
    sort(B.begin(), B.end());
    ll ans = 0;
    for (ll a : A) {
        auto iter = lower_bound(B.begin(), B.end(), D-a+1);
        ans += distance(B.begin(), iter);
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
