#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
pair<int,int> transpose(pair<int,int> p) {
    return make_pair(p.second, N-1-p.first);
}

void solve() {
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<string> B = A;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int k = min(min(x+1, N-x), min(y+1, N-y)) % 4;
            pair<int,int> p = {x, y};
            for (int l = 0; l < k; l++) p = transpose(p);
            B[p.first][p.second] = A[x][y];
        }
    }
    for (auto &s : B) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
