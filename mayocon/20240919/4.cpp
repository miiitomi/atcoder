// https://atcoder.jp/contests/abc064/tasks/abc064_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

pair<ll,ll> f(string S) {
    pair<ll,ll> ans = {0, 0};
    ll tmp = 0;
    for (char c : S) {
        if (c == '(') tmp++;
        else tmp--;
        ans.first = min(ans.first, tmp);
    }
    ans.second = tmp;
    return ans;
}

void solve() {
    int N;
    string S;
    cin >> N >> S;

    pair<ll,ll> res = f(S);
    if (res.first < 0) {
        S = string(-res.first, '(')+S;
        res = f(S);
    }
    S += string(res.second, ')');
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
