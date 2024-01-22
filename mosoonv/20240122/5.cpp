// https://atcoder.jp/contests/abc256/tasks/abc256_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int N;
vector<int> X, C;

void solve() {
    cin >> N;
    X.resize(N);
    C.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        X[i]--;
    }
    for (int i = 0; i < N; i++) cin >> C[i];

    ll ans = 0;
    vector<bool> reached(N, false);
    for (int i = 0; i < N; i++) {
        if (reached[i]) continue;
        vector<int> path, c;
        set<int> S;
        int tmp = i;
        while (!reached[tmp]) {
            reached[tmp] = true;
            path.push_back(tmp);
            c.push_back(C[tmp]);
            S.insert(tmp);
            tmp = X[tmp];
        }

        if (S.count(tmp)) {
            reverse(path.begin(), path.end());
            reverse(c.begin(), c.end());
            while (path.back() != tmp) {
                path.pop_back();
                c.pop_back();
            }
            sort(c.begin(), c.end());
            ans += c[0];
        }
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
