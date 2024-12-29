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
    string s = "RGB";
    vector<vector<int>> A(3, vector<int>(N, 0)), B(3, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        A[s.find(c)][i] = 1;
    }
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        B[s.find(c)][i] = 1;
    }
    for (int i = 0; i < 3; i++) reverse(B[i].begin(), B[i].end());
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        int j = (i+1)%3, k = (i+2)%3;
        vector<vector<int>> C(3);
        C[0] = convolution(A[i], B[i]);
        C[1] = convolution(A[j], B[k]);
        C[2] = convolution(A[k], B[j]);
        for (int x = 0; x <= 2*N-2; x++) {
            ll t = N - abs(x - (N-1));
            if ((C[0][x]+C[1][x]+C[2][x]) == t) ans++;
        }
    }
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
