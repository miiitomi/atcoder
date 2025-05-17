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
    vector<ll> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    vector<ll> A, B;
    for (int i = 1; i+1 < N; i++) {
        if (P[i-1] < P[i] && P[i] > P[i+1]) A.push_back(i);
        if (P[i-1] > P[i] && P[i] < P[i+1]) B.push_back(i);
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        while (!A.empty() && A.back() <= i) A.pop_back();
        while (!B.empty() && B.back() <= i) B.pop_back();

        if (A.empty() || B.empty()) break;
        if (P[i] >= P[i+1]) continue;
        ll l = max(A.back(), B.back()) + 1, r = N-1;
        if (A.size() >= 2) r = min(r, A[A.size()-2]);
        if (B.size() >= 2) r = min(r, B[B.size()-2]);

        cnt += r - l + 1;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
