#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    deque<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int k = 0; k < K; k++) {
        A.push_front(A.back());
        A.pop_back();
    }
    for (int a: A) cout << a << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
