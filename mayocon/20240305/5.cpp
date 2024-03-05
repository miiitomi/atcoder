// https://atcoder.jp/contests/abc305/tasks/abc305_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<bool> reached(N, false);
    reached[0] = true;
    function<bool(int, int)> f = [&](int u, int p) -> bool {
        if (u == N-1) {
            string S;
            cin >> S;
            return true;
        }
        int K;
        cin >> K;
        vector<int> v(K);
        for (int i = 0; i < K; i++) {
            cin >> v[i];
            v[i]--;
        }
        for (int w : v) {
            if (!reached[w]) {
                reached[w] = true;
                cout << w+1 << endl;
                bool res = f(w, u);
                if (res) return true;
                cin >> K;
                for (int k = 0; k < K; k++) {
                    int x;
                    cin >> x;
                }
            }
        }
        cout << p+1 << endl;
        return false;
    };
    f(0, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
