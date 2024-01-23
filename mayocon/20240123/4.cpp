// https://atcoder.jp/contests/abc273/tasks/abc273_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, x, y, N;
    cin >> H >> W >> x >> y >> N;
    map<int, vector<int>> R, C;
    while (N--) {
        int r, c;
        cin >> r >> c;
        R[r].push_back(c);
        C[c].push_back(r);
    }
    for (auto iter = R.begin(); iter != R.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }
    for (auto iter = C.begin(); iter != C.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    int Q;
    cin >> Q;
    while (Q--) {
        char d;
        int l;
        cin >> d >> l;
        if (d == 'R') {
            if (!R.count(x)) y = min(y+l, W);
            else {
                auto iter = lower_bound(R[x].begin(), R[x].end(), y);
                if (iter == R[x].end()) y = min(y+l, W);
                else y = min(y+l, *iter-1);
            }
        }
        if (d == 'L') {
            if (!R.count(x)) y = max(y-l, 1);
            else {
                auto iter = lower_bound(R[x].begin(), R[x].end(), y);
                if (iter == R[x].begin()) y = max(y-l, 1);
                else {
                    iter--;
                    y = max(y-l, *iter+1);
                }
            }
        }
        if (d == 'D') {
            if (!C.count(y)) x = min(x+l, H);
            else {
                auto iter = lower_bound(C[y].begin(), C[y].end(), x);
                if (iter == C[y].end()) x = min(x+l, H);
                else x = min(x+l, *iter-1);
            }
        }
        if (d == 'U') {
            if (!C.count(y)) x = max(x-l, 1);
            else {
                auto iter = lower_bound(C[y].begin(), C[y].end(), x);
                if (iter == C[y].begin()) x = max(x-l, 1);
                else {
                    iter--;
                    x = max(x-l, *iter+1);
                }
            }
        }
        cout << x << " " << y << "\n";
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
