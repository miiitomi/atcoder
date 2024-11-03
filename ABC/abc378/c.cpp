#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<int> B(N+1);
    map<int,int> mp;
    for (int i = 1; i <= N; i++) {
        if (mp.contains(A[i])) {
            cout << mp[A[i]];
        } else {
            cout << -1;
        }
        mp[A[i]] = i;
        if (i < N) cout << " ";
        else cout << endl;
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
