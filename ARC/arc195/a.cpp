#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<int> x(M), y(M);
    int j = 0;
    for (int i = 0; i < N && j < M; i++) {
        if (A[i] == B[j]) {
            x[j] = i;
            j++;
        }
    }
    if (j != M) {
        cout << "No\n";
        return;
    }
    j = M-1;
    for (int i = N-1; i >= 0 && j >= 0; i--) {
        if (A[i] == B[j]) {
            y[j] = i;
            j--;
        }
    }
    if (j != -1 || x == y) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
