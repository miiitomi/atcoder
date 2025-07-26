#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll A, N;

bool is_perindrome(string &S) {
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

bool is_good(ll x) {
    if (x > N) return false;
    string S = "";
    while (x > 0) {
        S.push_back('0' + (x % A));
        x /= A;
    }
    return is_perindrome(S);
}

void solve() {
    cin >> A >> N;
    ll ans = 0;

    for (ll x = 1; x <= 9; x++) {
        if (is_good(x)) {
            ans += x;
        }
    }

    for (ll x = 1; x <= (ll)1e+6; x++) {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());

        string S = s + t;
        ll y = stoll(S);
        if (is_good(y)) ans += y;

        s.push_back('0');
        for (char z = '0'; z <= '9'; z++) {
            s.back() = z;
            S = s + t;
            ll y = stoll(S);
            if (y > N) break;
            if (is_good(y)) ans += y;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
