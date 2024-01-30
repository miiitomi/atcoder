#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> A;
bool done = false;
vector<vector<int>> ng;
vector<vector<vector<bool>>> V(8889);

void rec(int i, vector<bool> v, int sum) {
    if (i == N) {
        V[sum].push_back(v);
        if (V[sum].size() == 2) done = true;
        return;
    }
    rec(i+1, v, sum);
    if (done) return;
    for (int y : ng[i]) if (v[y]) return;
    v[i] = true;
    rec(i+1, v, sum + A[i]);
}

void solve() {
    cin >> N >> Q;
    A.resize(N);
    ng.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < Q; j++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ng[x].push_back(y);
        ng[y].push_back(x);
    }
    vector<bool> v(N, false);
    rec(0, v, 0);
    for (int x = 0; x <= 8888; x++) {
        if (V[x].size() != 2) continue;
        for (int j = 0; j < 2; j++) {
            int cnt = 0;
            for (int k = 0; k < N; k++) if (V[x][j][k]) cnt++;
            cout << cnt << "\n";
            for (int k = 0; k < N; k++) if (V[x][j][k]) cout << k+1 << " ";
            cout << "\n";
        }
        return;
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
