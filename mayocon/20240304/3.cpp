// https://atcoder.jp/contests/abc117/tasks/abc117_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> X(M), Y(M-1);
    for (int i = 0; i < M; i++) cin >> X[i];
    sort(X.begin(), X.end());
    for (int i = 0; i < M-1; i++) Y[i] = X[i+1] - X[i];
    sort(Y.begin(), Y.end());

    if (N >= M) cout << 0 << endl;
    else {
        N--;
        while (N--) Y.pop_back();
        ll ans = 0;
        for (ll y : Y) ans += y;
        cout << ans << endl;
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
