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
    vector<int> S(N);
    vector<int> a((int)1e+6 +1, 0);
    for (int &s : S) {
        cin >> s;
        a[s]++;
    }

    auto c = atcoder::convolution(a, a);
    ll ans = 0;
    for (int s : S) {
        ans += c[2*s] - 1;
    }
    cout << ans/2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
