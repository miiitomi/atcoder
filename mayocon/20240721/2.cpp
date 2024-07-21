// https://atcoder.jp/contests/abc357/tasks/abc357_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<string> f(ll k) {
    if (k == 0) {
        vector<string> v = {"#"};
        return v;
    }
    vector<string> tmp = f(k-1);
    vector<string> ans(3*tmp.size(), string(3*tmp.size(), '.'));
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i == 1 && j == 1) continue;
            int s = i*tmp.size(), t = j*tmp.size();
            for (int l = 0; l < (int)tmp.size(); l++) {
                for (int r = 0; r < (int)tmp[0].size(); r++) {
                    ans[s+l][t+r] = tmp[l][r];
                }
            }
        }
    }
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<string> S = f(N);
    for (string s :S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
