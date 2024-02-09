// https://atcoder.jp/contests/abc265/tasks/abc265_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }
    for (int x = 0; x + 3 <= N; x++) {
        int y = distance(S.begin(), lower_bound(S.begin(), S.end(), S[x] + P));
        if (y == N+1 || S[y] != S[x] + P) continue;
        int z = distance(S.begin(), lower_bound(S.begin(), S.end(), S[y] + Q));
        if (z == N+1 || S[z] != S[y] + Q) continue;
        int w = distance(S.begin(), lower_bound(S.begin(), S.end(), S[z] + R));
        if (w == N+1 || S[w] != S[z] + R) continue;
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
