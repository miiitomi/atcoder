#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    string S;
    while (N--) {
        char c;
        ll l;
        cin >> c >> l;
        if (l > 100) {
            cout << "Too Long\n";
            return;
        }
        while (l--) S.push_back(c);
        if ((ll)S.size() > 100) {
            cout << "Too Long\n";
            return;
        }
    }
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
