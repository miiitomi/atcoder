// https://atcoder.jp/contests/abc312/tasks/abc312_c
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
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll left = -1, right = INF;
    while (right - left > 1) {
        ll p = (right + left)/2;
        auto iter1 = lower_bound(A.begin(), A.end(), p+1);
        ll seller = distance(A.begin(), iter1);
        auto iter2 = lower_bound(B.begin(), B.end(), p);
        ll buyer = distance(iter2, B.end());
        if (seller >= buyer) right = p;
        else left = p;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
