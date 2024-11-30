// https://atcoder.jp/contests/abc279/tasks/abc279_e
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
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> b(N);
    iota(b.begin(), b.end(), 0);
    for (int a : A) swap(b[a], b[a+1]);
    vector<int> pos(N);
    for (int i = 0; i < N; i++) pos[b[i]] = i;
    iota(b.begin(), b.end(), 0);
    for (int a : A) {
        if (b[a] == 0) cout << 1+pos[b[a+1]] << "\n";
        else if (b[a+1] == 0) cout << 1+pos[b[a]] << "\n";
        else cout << 1+pos[0] << "\n";
        swap(b[a], b[a+1]);
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
