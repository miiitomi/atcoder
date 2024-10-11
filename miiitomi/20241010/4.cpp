// https://atcoder.jp/contests/abc096/tasks/abc096_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_prime(int x) {
    for (int y = 2; y*y <= x; y++) {
        if (x % y == 0) return false;
    }
    return true;
}

void solve() {
    int N;
    cin >> N;
    vector<int> v;
    for (int x = 10; x <= 55555; x += 10) {
        if (!is_prime(x+1)) continue;
        v.push_back(x+1);
        if ((int)v.size() == N) break;
    }
    for (int i = 0; i < N; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
