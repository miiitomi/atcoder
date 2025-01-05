#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_good(ll x) {
    string S = to_string(x);
    ll y = 0;
    for (char c : S) y += c-'0';
    return x%y == 0;
}

void solve() {
    string S;
    cin >> S;
    ll K = S.size();
    if (K <= 5) {
        ll N = stoll(S);
        for (ll a = N; a <= 2*N-1; a++) {
            if (is_good(a) && is_good(a+1)) {
                cout << a << "\n";
                return;
            }
        }
        cout << -1 << "\n";
        return;
    }
    string T = string(K, '0');
    ll x = 10*(S[0]-'0')+(S[1]-'0'), y;
    if (x < 17) y = 17;
    else if (x < 26) y = 26;
    else if (x < 35) y = 35;
    else if (x < 44) y = 44;
    else if (x < 53) y = 53;
    else if (x < 62) y = 62;
    else if (x < 71) y = 71;
    else if (x < 80) y = 80;
    else y = 107;

    if (y < 100) {
        T[0] = (char)(y/10 + '0');
        T[1] = (char)(y%10 + '0');
    } else {
        T.push_back('0');
        T[0] = '1';
        T[2] = '7';
    }

    cout << T << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
