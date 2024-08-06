// https://atcoder.jp/contests/abc357/tasks/abc357_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    int s = 0, l = 0;
    for (char c : S) {
        if ('a' <= c && c <= 'z') s++;
        else l++;
    }
    if (l > s) {
        for (char &c : S) {
            if ('a' <= c && c <= 'z') {
                c = 'A' + (c - 'a');
            }
        }
    } else {
        for (char &c : S) {
            if ('A' <= c && c <= 'Z') {
                c = 'a' + (c - 'A');
            }
        }
    }
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
