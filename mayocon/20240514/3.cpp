// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
using namespace std;

template<typename T> void f(vector<T> &V, int i) {
    for (int j = i; j < (int)V.size()-1; j++) {
        V[j] = V[j+1];
    }
    V.pop_back();
}

void solve() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    bool update = true;
    while (update) {
        H = (int)a.size();
        W = (int)a[0].size();
        update = false;
        for (int i = 0; i < H; i++) {
            bool can_delete = true;
            for (int j = 0; j < W; j++) if (a[i][j] == '#') can_delete = false;
            if (can_delete) {
                f(a, i);
                update = true;
                break;
            }
        }

        if (update) continue;

        for (int j = 0; j < W; j++) {
            bool can_delete = true;
            for (int i = 0; i < H; i++) if (a[i][j] == '#') can_delete = false;
            if (can_delete) {
                for (int i = 0; i < H; i++) f(a[i], j);
                update = true;
                break;
            }
        }
    }

    H = (int)a.size();
    W = (int)a[0].size();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cout << a[i][j];
        cout << "\n";
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
