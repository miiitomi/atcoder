// https://atcoder.jp/contests/abc177/tasks/abc177_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_pairwise_coprime(vector<ll> &A) {
    vector<bool> seen((ll)1e+6 + 1, false);
    for (ll a : A) {
        for (ll x = 1; x*x <= a; x++) {
            if (a%x == 0) {
                ll s = x, t = a/x;
                if (s != 1) {
                    if (seen[s]) return false;
                    seen[s] = true;
                }
                if (s != t && t != 1) {
                    if (seen[t]) return false;
                    seen[t] = true;
                }
            }
        }
    }
    return true;
}

bool is_setwise_coprimt(vector<ll> &A) {
    ll x = A[0];
    for (ll a : A) x = gcd(x, a);
    return (x == 1);
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (is_pairwise_coprime(A)) {
        cout << "pairwise coprime\n";
    } else if (is_setwise_coprimt(A)) {
        cout << "setwise coprime\n";
    } else {
        cout << "not coprime\n";
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
