// https://atcoder.jp/contests/abc165/tasks/abc165_e
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
    vector<ll> odd, even;
    for (int i = M; i >= 1; i--) {
        if (i%2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    int l = 1;
    for (int o : odd) {
        cout << l << " " << l+o << "\n";
        l++;
    }
    l = 2*odd.size() + 1;
    for (int e : even) {
        cout << l << " " << l+e << "\n";;
        l++;
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
