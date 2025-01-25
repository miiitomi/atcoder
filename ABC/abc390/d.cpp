#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
vector<ll> v;

void f(ll i, vector<ll> &B) {
    if (i == N) {
        ll x = 0;
        for (ll b : B) x ^= b;
        v.push_back(x);
        return;
    }

    for (ll j = 0; j < (int)B.size(); j++) {
        B[j] += A[i];
        f(i+1, B);
        B[j] -= A[i];
    }

    B.push_back(A[i]);
    f(i+1, B);
    B.pop_back();
}

void solve() {
    cin >> N;
    A.resize(N);
    for (ll &a : A) cin >> a;
    vector<ll> B;
    f(0, B);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
