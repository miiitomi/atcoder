#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];
    ll left = 0, right = INF;
    sort(A.begin(), A.end());
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        vector<ll> C = B;
        C.push_back(mid);
        sort(C.begin(), C.end());
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (C[i] < A[i]) {
                ok = false;
                break;
            }
        }
        if (ok) right = mid;
        else left = mid;
    }
    if (right == INF) cout << -1 << endl;
    else cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
