// https://atcoder.jp/contests/abc062/tasks/arc074_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> f(vector<ll> &A) {
    vector<ll> B(A.size(), -INF);
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += A[i];
        Q.push(A[i]);
    }
    B[N-1] = tmp;
    for (int i = N; i < (int)A.size(); i++) {
        ll a = A[i];
        if (a > Q.top()) {
            tmp += a - Q.top();
            Q.pop();
            Q.push(a);
        }
        B[i] = tmp;
    }
    return B;
}

void solve() {
    cin >> N;
    vector<ll> A(3*N);
    for (int i = 0; i < 3*N; i++) cin >> A[i];
    vector<ll> B = f(A);
    reverse(A.begin(), A.end());
    for (int i = 0; i < (int)A.size(); i++) A[i] *= -1;
    vector<ll> C = f(A);
    reverse(C.begin(), C.end());
    ll ans = -INF;
    for (int i = N-1; i < 2*N; i++) ans = max(ans, B[i] + C[i+1]);
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
