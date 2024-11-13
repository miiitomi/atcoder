// https://atcoder.jp/contests/abc298/tasks/abc298_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> pow_ten(1e+6, 1);

void solve() {
    for (int i = 1; i < 1e+6; i++) pow_ten[i] = pow_ten[i-1]*10;
    ll Q;
    cin >> Q;
    deque<int> S;
    S.push_back(1);
    mint tmp = 1;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            tmp = 10*tmp + x;
            S.push_back(x);
        } else if (k == 2) {
            int x = S.front();
            S.pop_front();
            tmp -= pow_ten[S.size()] * x;
        } else {
            cout << tmp.val() << "\n";
        }
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
