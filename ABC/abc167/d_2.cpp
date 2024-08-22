#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void cycle_detection(int u, vector<bool> &reached, vector<int> &cycle, vector<int> &A) {
    if (reached[u]) {
        reverse(cycle.begin(), cycle.end());
        while (cycle.back() != u) cycle.pop_back();
        reverse(cycle.begin(), cycle.end());
        return;
    }
    reached[u] = true;
    cycle.push_back(u);
    cycle_detection(A[u], reached, cycle, A);
}

void solve() {
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<bool> reached(N, false);
    vector<int> cycle;
    cycle_detection(0, reached, cycle, A);

    int u = 0;
    while (u != cycle[0]) {
        u = A[u];
        K--;
        if (K == 0) {
            cout << u+1 << endl;
            return;
        }
    }

    K %= (int)cycle.size();
    u = cycle[K];
    cout << u+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
