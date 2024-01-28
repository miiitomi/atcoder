// https://atcoder.jp/contests/abc329/tasks/abc329_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    set<int> Q;
    for (int i = 0; i + M <= N; i++) Q.insert(i);
    vector<bool> done(N, false);
    while (!Q.empty()) {
        int i = *Q.begin();
        Q.erase(i);
        bool is_ok = true;
        for (int j = 0; j < M; j++) {
            if (S[i+j] != '.' && S[i+j] != T[j]) is_ok = false;
        }
        if (is_ok) {
            for (int j = 0; j < M; j++) S[i+j] = '.';
            done[i] = true;
            for (int j = max(i-M+1, 0); j <= min(i+M-1, N-M); j++) {
                if (!Q.count(j) && !done[j]) {
                    Q.insert(j);
                }
            }
        }
    }

    if (S == string(N, '.')) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
