// https://atcoder.jp/contests/abc123/tasks/abc123_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    vector<ll> A(5);
    cin >> N;
    for (int i = 0; i < 5; i++) cin >> A[i];
    ll m = *min_element(A.begin(), A.end());
    ll k = (N+m-1)/m;
    cout << k-1+5 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
