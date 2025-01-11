// https://atcoder.jp/contests/past19-open/tasks/past19_b
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
    ll a;
    cin >> a;
    ll in = 0, out = 0;
    for (int i = 0; i < N-1; i++) {
        ll b;
        cin >> b;
        if (a < b) in += b-a;
        else out += a-b;
        a = b;
    }
    cout << in << " " << out << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

