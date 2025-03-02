#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> A(3);
    for (int &a : A) cin >> a;
    sort(A.begin(), A.end());
    do {
        if (A[0]*A[1] == A[2]) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(A.begin(), A.end()));
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
