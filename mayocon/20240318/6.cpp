// https://atcoder.jp/contests/abc211/tasks/abc211_e
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    int N, K;
    cin >> N >> K;
    H = N;
    W = N;
    ull S = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '.') continue;
            S += (1LL << (to_int(i, j)));
        }
    }
    unordered_set<ull> used;
    int ans = 0;

    function<void(ull, int)> dfs = [&](ull T, int cnt) -> void {
        used.insert(T);
        if (cnt == K) {
            ans++;
            return;
        }

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                int z = to_int(x, y);
                if (T & (1LL << z) || S & (1LL << z) || used.count(T + (1LL << z))) continue;
                bool ok = (cnt == 0);
                for (int k = 0; k < 4; k++) {
                    int a = x + dx[k], b = y + dy[k];
                    if (is_in(a, b) && (T & (1LL << to_int(a, b)))) ok = true;
                }
                if (ok) {
                    used.insert(T + (1LL << z));
                    dfs(T + (1LL << z), cnt+1);
                }
            }
        }
    };

    dfs(0LL, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
