// https://atcoder.jp/contests/abc202/tasks/abc202_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) {
        A[i]--;
        B[i]--;
        C[i]--;
    }

    vector<ll> X(N, 0), Y(N, 0);
    for (int a : A) X[a]++;
    for (int c : C) Y[B[c]]++;
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += X[i] * Y[i];
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
