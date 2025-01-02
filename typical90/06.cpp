// https://atcoder.jp/contests/typical90/tasks/typical90_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<deque<int>> D(26);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        D[c-'a'].push_back(i);
    }
    int l = -1;
    for (int i = 0; i < K; i++) {
        for (int k = 0; k < 26; k++) {
            while (!D[k].empty() && D[k].front() <= l) D[k].pop_front();
            if (!D[k].empty() && N-D[k].front() >= K-i) {
                cout << (char)('a' + k);
                l = D[k].front();
                break;
            }
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
