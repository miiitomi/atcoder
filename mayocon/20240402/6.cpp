// https://atcoder.jp/contests/abc258/tasks/abc258_g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<bitset<3000>> A(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '1') A[i][j] = 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (!A[i][j]) continue;
            ans += (A[i] & A[j]).count();
        }
    }
    ans /= 3;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
