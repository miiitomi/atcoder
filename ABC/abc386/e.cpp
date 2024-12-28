#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, K;
vector<ll> A;
vector<ll> ans;

void f(int S, int k, ll a) {
    if (k == K) {
        ans.push_back(a);
    } else {
        for (int i = S; N-1-i >= K-k-1; i++) {
            f(i+1, k+1, a^A[i]);
        }
    }
}


void solve() {
    cin >> N >> K;
    bool reversed = false;
    if (K > N-K) {
        reversed = true;
        K = N-K;
    }
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    f(0, 0, 0);
    if (reversed) {
        ll sum = 0;
        for (ll a : A) sum ^= a;
        ll tmp = -INF;
        for (ll a : ans) tmp = max(tmp, sum^a);
        cout << tmp << "\n";
    } else {
        ll tmp = -INF;
        for (ll a : ans) tmp = max(tmp, a);
        cout << tmp << "\n";
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
