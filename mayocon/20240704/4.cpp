// https://atcoder.jp/contests/abc332/tasks/abc332_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> B[i][j];

    if (A == B) {
        cout << 0 << endl;
        return;
    }

    map<vector<vector<int>>, int> d;
    queue<vector<vector<int>>> Q;
    d[A] = 0;
    Q.push(A);

    while (!Q.empty()) {
        vector<vector<int>> X = Q.front();
        Q.pop();
        int tmp = d[X];

        for (int i = 0; i < H-1; i++) {
            swap(X[i], X[i+1]);
            if (X == B) {
                cout << tmp+1 << endl;
                return;
            } else if (!d.count(X)) {
                d[X] = tmp+1;
                Q.push(X);
            }
            swap(X[i], X[i+1]);
        }
        for (int j = 0; j < W-1; j++) {
            for (int i = 0; i < H; i++) swap(X[i][j], X[i][j+1]);
            if (X == B) {
                cout << tmp+1 << endl;
                return;
            } else if (!d.count(X)) {
                d[X] = tmp+1;
                Q.push(X);
            }
            for (int i = 0; i < H; i++) swap(X[i][j], X[i][j+1]);
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
