// https://atcoder.jp/contests/typical90/tasks/typical90_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_good(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt==0;
}

void solve() {
    int N;
    cin >> N;
    for (int t = 0; t < (1 << N); t++) {
        string s = string(N, '(');
        for (int i = 0; i < N; i++) {
            if (t & (1 << i)) {
                s[N-1-i] = ')';
            }
        }
        if (is_good(s)) cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
