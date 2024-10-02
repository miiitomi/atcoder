// https://atcoder.jp/contests/abc242/tasks/abc242_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

string ABC = "ABC";

void solve() {
    string S;
    ll Q;
    cin >> S >> Q;
    while (Q--) {
        ll t, k;
        cin >> t >> k;
        k--;
        ll ans = 0;
        while (t > 0 && k > 0) {
            if (k & 1) {
                k--;
                ans++;
            }
            if (k == 0) break;
            k /= 2;
            t--;
            ans++;
        }
        if (t == 0) {
            ans = ((S[k]-'A')+ans)%3;
            cout << ABC[ans] << "\n";
            continue;
        }
        ans = ((S[0]-'A') + t + ans)%3;
        cout << ABC[ans] << "\n";
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
