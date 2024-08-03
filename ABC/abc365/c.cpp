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
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum <= M) {
        cout << "infinite" << endl;
        return;
    }

    ll left = 0, right = 2e+9;
    while (right - left > 1) {
        ll m = (left + right)/2;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += min(m, A[i]);
        }
        if (tmp <= M) left = m;
        else right = m;
    }

    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
