#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, M;

bool is_ok(vector<int> &A) {
    vector<bool> is_in(M, false);
    for (int a: A) is_in[a] = true;
    return is_in != vector<bool>(M, true);
}

void solve() {
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    int ans = 0;
    while (!is_ok(A)) {
        A.pop_back();
        ans++;
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
