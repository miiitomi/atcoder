// https://atcoder.jp/contests/abc291/tasks/abc291_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> is_smaller_than(N), is_larger_than(N);
    while (M--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        is_smaller_than[x].insert(y);
        is_larger_than[y].insert(x);
    }
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        if (is_larger_than[i].empty()) Q.push(i);
    }
    vector<int> A(N);
    for (int k = 0; k < N; k++) {
        if (Q.empty() || (int)Q.size() >= 2) {
            cout << "No\n";
            return;
        }
        int x = Q.front();
        Q.pop();
        A[x] = k;
        for (int y : is_smaller_than[x]) {
            is_larger_than[y].erase(x);
            if (is_larger_than[y].empty()) Q.push(y);
        }
    }
    cout << "Yes\n";
    for (int a : A) cout << a+1 << " ";
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
