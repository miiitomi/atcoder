// https://atcoder.jp/contests/abc282/tasks/abc282_f
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> V;
void f(int l, int r) {
    int m = (l+r)/2;
    for (int k = 1; m+k <= r; k++) {
        V.push_back(make_pair(m, m+k));
    }
    for (int k = -1; l <= m+k; k--) {
        V.push_back(make_pair(m+k, m));
    }
    if (r-l >= 2) {
        f(l, m);
        f(m, r);
    }
}

void solve() {
    int N;
    cin >> N;
    f(0, N);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    cout << V.size() << endl;
    for (auto p : V) cout << p.first+1 << " " << p.second << endl;
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--;
        auto iter = lower_bound(V.begin(), V.end(), make_pair(L, R));
        if (iter != V.end() && *iter == make_pair(L, R)) {
            int i = distance(V.begin(), iter);
            cout << i+1 << " " << i+1 << endl;
            continue;
        }
        int l = 0, r = N, m = N/2;
        while (!(L <= m && m < R)) {
            if (m < L) {
                l = m;
                m = (l+r)/2;
            } else {
                r = m;
                m = (l+r)/2;
            }
        }
        cout << 1+(int)distance(V.begin(), lower_bound(V.begin(), V.end(), make_pair(L, m))) << " " << 1+(int)distance(V.begin(), lower_bound(V.begin(), V.end(), make_pair(m, R))) << endl;
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
