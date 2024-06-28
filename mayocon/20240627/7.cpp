// https://atcoder.jp/contests/abc196/tasks/abc196_f
#include <bits/stdc++.h>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
using ll = long long;

void solve() {
    string S, T;
    cin >> S >> T;
    reverse(T.begin(), T.end());
    vector<ll> s1(S.size(), 0), s2(S.size(), 0), t1(T.size(), 0), t2(T.size(), 0);
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '1') s1[i] = 1;
        else s2[i] = 1;
    }
    for (int i = 0; i < (int)T.size(); i++) {
        if (T[i] == '1') t2[i] = 1;
        else t1[i] = 1;
    }
    vector<ll> c1 = convolution_ll(s1, t1);
    vector<ll> c2 = convolution_ll(s2, t2);
    vector<ll> c(c1.size(), 0);
    for (int i = 0; i < (int)c1.size(); i++) c[i] = c1[i]+c2[i];

    ll ans = 1e+18;
    for (int i = 0; i <= (int)S.size() - (int)T.size(); i++) {
        ans = min(ans, c[(int)T.size()-1+i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
