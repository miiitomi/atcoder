#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> A(5);
    for (int i = 0; i < 5; i++) cin >> A[i];
    vector<int> B = A;
    sort(B.begin(), B.end());
    for (int i = 0; i <= 3; i++) {
        swap(A[i], A[i+1]);
        if (A == B) {
            cout << "Yes\n";
            return;
        }
        swap(A[i], A[i+1]);
    }
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
