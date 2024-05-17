// https://atcoder.jp/contests/abc319/tasks/abc319_c
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> W{
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

bool is_gakkari(vector<int> &v, vector<int> &c) {
    vector<vector<int>> z((int)W.size());
    for (int i : v) {
        for (int j = 0; j < (int)W.size(); j++) {
            if ((W[j][0] != i && W[j][1] != i && W[j][2] != i) || z[j].size() == 2) continue;
            else if (z[j].size() == 1) {
                if (z[j][0] == c[i]) return true;
                else z[j].push_back(c[i]);
            } else {
                z[j].push_back(c[i]);
            }
        }
    }
    return false;
}

void solve() {
    vector<int> c(9), v(9);
    for (int i = 0; i <= 8; i++) {
        cin >> c[i];
        v[i] = i;
    }

    int cnt = 0, gakkari = 0;
    do {
        cnt++;
        gakkari += is_gakkari(v, c);
    } while (next_permutation(v.begin(), v.end()));

    cout << (1.0 - (gakkari + 0.0)/cnt) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
