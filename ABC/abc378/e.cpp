#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= M;
        S[i+1] = (S[i] + A[i]) % M;
    }
    fenwick_tree<int> fw(M);
    fw.add(0, 1);
    ll sum = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (i+1)*S[i+1] - sum + fw.sum(S[i+1]+1, M)*M;
        sum += S[i+1];
        fw.add(S[i+1], 1);
    }
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
