// https://atcoder.jp/contests/abc070/tasks/abc070_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using cint = cpp_int;

void solve() {
    ll N;
    cin >> N;
    cint ans = 1;
    while (N--) {
        ll x;
        cin >> x;
        ans = lcm(x, ans);
    }
    string S;
    while (ans > 0) {
        S.push_back((char)('0'+(int)(ans%10)));
        ans /= 10;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
