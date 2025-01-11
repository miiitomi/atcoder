// https://atcoder.jp/contests/past19-open/tasks/past19_g
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
    int x = -1, y = -1;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j]--;
            if (A[i][j] < 0) {
                x = i;
                y = j;
            }
        }
    }
    vector<tuple<int,int,int>> V;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                bool b = false;
                if (i == x && j == y) b = true;
                else if (j == x && k == y) b = true;
                else if (A[i][j] == x && k == y) b = true;
                else if (i == x && A[j][k] == y) b = true;
                if (b) V.push_back(make_tuple(i,j,k));
                else {
                    if (A[A[i][j]][k] != A[i][A[j][k]]) {
                        cout << 0 << "\n";
                        return;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int a = 0; a < N; a++) {
        A[x][y] = a;
        bool ok = true;
        for (auto &t : V) {
            auto [i, j, k] = t;
            if (A[A[i][j]][k] != A[i][A[j][k]]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
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
