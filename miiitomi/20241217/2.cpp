// https://atcoder.jp/contests/abc058/tasks/arc071_a
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
    cin >> N;
    vector<ll> cnt(26, INF);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        vector<ll> tmp(26, 0);
        for (char c : S) tmp[c - 'a']++;
        for (int i = 0; i < 26; i++) cnt[i] = min(cnt[i], tmp[i]);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << (char)('a'+i);
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
