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
    string S;
    cin >> N >> S;
    ll tmp = 0;
    ll ans = 0;
    string T = "";
    for (int i = 0; i < N; i++) {
        tmp += (i+1LL) * (ll)(S[i] - '0');
    }
    for (int i = N-1; i >= 0; i--) {
        ans += tmp;
        T.push_back('0' + (ans % 10));
        ans /= 10;
        tmp -= (i+1LL)*(ll)(S[i] - '0');
    }
    while (ans > 0) {
        T.push_back('0' + (ans % 10));
        ans /= 10;
    }
    reverse(T.begin(), T.end());
    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
