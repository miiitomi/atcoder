// https://atcoder.jp/contests/abc136/tasks/abc136_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll S = 0;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }
    vector<ll> v;
    for (ll x = 1; x*x <= S; x++) {
        if (S%x == 0) {
            v.push_back(x);
            v.push_back(S/x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());
    for (ll x : v) {
        if (x == 1) {
            cout << 1 << endl;
            return;
        }
        deque<ll> D;
        for (ll a : A) {
            if (a % x != 0) D.push_back(a%x);
        }
        sort(D.begin(), D.end());
        ll tmp = 0;
        while (!D.empty()) {
            ll s = D.front();
            D.pop_front();
            ll l = D.back();
            D.pop_back();
            if (s+l < x) {
                tmp += s;
                D.push_back(s+l);
            } else if (s+l > x) {
                tmp += x-l;
                s = (s+l)%x;
                D.push_front(s);
            } else if (s+l == x) {
                tmp += s;
            }
        }
        if (tmp <= K) {
            cout << x << endl;
            return;
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
