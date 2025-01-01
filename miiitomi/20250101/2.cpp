// https://atcoder.jp/contests/abc213/tasks/abc213_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<int> v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    v = B;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &b : B) b = distance(v.begin(), lower_bound(v.begin(), v.end(), b));
    for (int i = 0; i < N; i++) {
        cout << A[i]+1 << " " << B[i]+1 << "\n";
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
