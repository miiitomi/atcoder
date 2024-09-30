// https://atcoder.jp/contests/abc327/tasks/abc327_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N-1; i++) {
        if ((S[i]=='a'&&S[i+1]=='b') || (S[i]=='b' && S[i+1]=='a')) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
