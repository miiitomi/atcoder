// https://atcoder.jp/contests/abc171/tasks/abc171_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S;
    ll N;
    cin >> N;
    N--;

    while (true) {
        S.push_back('a' + (N % 26));
        if (N <= 25) break;
        N /= 26;
        N--;
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
