#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> A(3, vector<ll>(3, 0));
vector<vector<pair<int,int>>> v{
    {{0,0}, {0,1}, {0,2}},
    {{1,0}, {1,1}, {1,2}},
    {{2,0}, {2,1}, {2,2}},
    {{0,0}, {1,0}, {2,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,2}, {1,2}, {2,2}},
    {{0,0}, {1,1}, {2,2}},
    {{0,2}, {1,1}, {2,0}}
};

bool takahashi_win(vector<vector<int>> c) {
    for (vector<pair<int,int>> &w : v) {
        if (c[w[0].first][w[0].second] == c[w[1].first][w[1].second] && c[w[0].first][w[0].second] == c[w[2].first][w[2].second]) {
            if (c[w[0].first][w[0].second] == 1) return true;
            else if (c[w[0].first][w[0].second] == 2) return false;
        }
    }
    ll cnt = 0, takahashi = 0, aoki = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c[i][j] == 1) {
                cnt++;
                takahashi += A[i][j];
            } else if (c[i][j] == 2) {
                cnt++;
                aoki += A[i][j];
            }
        }
    }

    if (cnt == 9) {
        return takahashi > aoki;
    }

    bool can_win = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c[i][j] != 0) continue;
            if ((cnt % 2) == 0) {
                c[i][j] = 1;
                bool tmp = takahashi_win(c);
                if (tmp) can_win = true;
                c[i][j] = 0;
            } else {
                c[i][j] = 2;
                bool tmp = takahashi_win(c);
                if (!tmp) can_win = true;
                c[i][j] = 0;
            }
        }
    }

    if ((cnt % 2) == 0) {
        if (can_win) return true;
        else return false;
    } else {
        if (can_win) return false;
        else return true;
    }
}

void solve() {
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> A[i][j];
    vector<vector<int>> c(3, vector<int>(3, 0));
    bool is_takahashi_win = takahashi_win(c);
    if (is_takahashi_win) cout << "Takahashi\n";
    else cout << "Aoki\n";  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
