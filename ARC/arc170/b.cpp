#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> V;

void solve() {
    for (int k = -4; k <= 4; k++) {
        if (k == 0) continue;
        for (int x = 0; x <= 9; x++) {
            int y = x + k, z = x+2*k;
            if (0 <= y && y <= 9 && 0 <= z && z <= 9) {
                vector<int> v{x, y, z};
                V.push_back(v);
            }
        }
    }

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<set<int>> cnt(10);
    int r = -1;
    ll ans = 0;

    for (int l = 0; l < N; l++) {
        bool ok = false;
        for (int x = 0; x <= 9; x++) if (cnt[x].size() >= 3) ok = true;
        if (!ok) {
            for (vector<int> &v : V) {
                if (!cnt[v[0]].empty() && !cnt[v[1]].empty() && !cnt[v[2]].empty()) {
                    int i = *cnt[v[0]].begin();
                    int k = *cnt[v[2]].rbegin();
                    auto iter = cnt[v[1]].lower_bound(i);
                    if (iter != cnt[v[1]].end() && *iter < k) {
                        ok = true;
                        break;
                    }
                }
            }
        }

        while (!ok && r+1 <= N-1) {
            r++;
            cnt[A[r]].insert(r);
            for (int x = 0; x <= 9; x++) if (cnt[x].size() >= 3) ok = true;
            if (!ok) {
                for (vector<int> &v : V) {
                    if (!cnt[v[0]].empty() && !cnt[v[1]].empty() && !cnt[v[2]].empty()) {
                        int i = *cnt[v[0]].begin();
                        int k = *cnt[v[2]].rbegin();
                        auto iter = cnt[v[1]].lower_bound(i);
                        if (iter != cnt[v[1]].end() && *iter < k) {
                            ok = true;
                            break;
                        }
                    }
                }
            }
        }

        if (ok) {
            ans += (N-1) - r + 1;
        }

        cnt[A[l]].erase(l);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
