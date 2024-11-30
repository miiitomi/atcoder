#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, M;
vector<vector<int>> V;

void f(vector<int> &a) {
    if ((int)a.size() == N) {
        V.push_back(a);
        return;
    }
    int left = 1;
    if (!a.empty()) left = a.back() + 10;
    for (int x = left; x + 10*(N-1-(int)a.size())<= M; x++) {
        a.push_back(x);
        f(a);
        a.pop_back();
    }
}

void solve() {
    cin >> N >> M;
    vector<int> a;
    f(a);
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for (auto &v : V) {
        for (int i = 0; i < N; i++) {
            cout << v[i];
            if (i == N-1) cout << "\n";
            else cout << " ";
        }
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
