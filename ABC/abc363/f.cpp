#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

string f(ll N) {
    string n = to_string(N);
    bool is_kaibun = true, contain_zero = false;
    for (int i = 0; i < (int)n.size(); i++) {
        if (n[i] == '0') contain_zero = true;
        if (n[i] != n[(int)n.size()-1-i]) is_kaibun = false;
    }

    if (is_kaibun && !contain_zero) return n;

    for (ll x = 2; x*x <= N; x++) {
        if (N%x != 0) continue;
        string X = to_string(x);
        bool X_contain_zero = false;
        for (int i = 0; i < (int)X.size(); i++) if (X[i] == '0') X_contain_zero = true;
        if (X_contain_zero) continue;
        reverse(X.begin(), X.end());
        string Y = X;
        reverse(X.begin(), X.end());
        ll y = stoll(Y);
        if (N % (x*y) == 0) {
            string res = f(N/(x*y));
            if (res != "") {
                string ans = X;
                ans.push_back('*');
                ans += res;
                ans.push_back('*');
                ans += Y;
                return ans;
            }
        }
    }
    return "";
}

void solve() {
    ll N;
    cin >> N;
    string ans = f(N);
    if (ans == "") cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
