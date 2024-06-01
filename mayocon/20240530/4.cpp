// https://atcoder.jp/contests/abc301/tasks/abc301_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S;
    ll N;
    cin >> S >> N;
    ll K = S.size();

    ll tmp = 0;
    for (ll i = 0; i < K; i++) {
        if (S[K-1-i] == '1') tmp += (1LL << i);
    }

    if (tmp > N) {
        cout << -1 << "\n";
        return;
    }

    for (ll i = 0; i < K; i++) {
        if (S[i] != '?') continue;
        if (tmp + (1LL << (K-1-i)) <= N) tmp += (1LL << (K-1-i));
    }
    cout << tmp << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
