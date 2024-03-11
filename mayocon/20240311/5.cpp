// https://atcoder.jp/contests/abc196/tasks/abc196_d
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    int A, B;
    cin >> H >> W >> A >> B;
    int N = H*W;
    vector<int> v(N, 0);
    for (int i = 0; i < B; i++) v[N-1-i] = 1;
    int ans = 0;
    do {
        vector<int> w;
        for (int i = 0; i < N; i++) if (v[i] == 0) w.push_back(i);

        for (int k = 0; k <= N-B; k += 2) {
            vector<int> z((int)w.size(), 0);
            for (int j = 0; j < k; j++) z[(int)z.size()-1-j] = 1;
            do {
                set<int> S, T;
                for (int k = 0; k < (int)w.size(); k++) {
                    if (z[k]) S.insert(w[k]);
                    else T.insert(w[k]);
                }
                if ((int)S.size() % 2 == 1 || (int)T.size() % 2 == 1) continue;
                bool is_ok = true;
                for (auto iter = S.begin(); iter != S.end(); ) {
                    if (to_xy(*iter).second == W-1 || !S.count(*iter+1)) {
                        is_ok = false;
                        break;
                    }
                    S.erase(*iter+1);
                    iter = S.erase(iter);
                }
                if (!is_ok) continue;
                for (auto iter = T.begin(); iter != T.end(); ) {
                    if (to_xy(*iter).first == H-1 || !T.count(*iter + W)) {
                        is_ok = false;
                        break;
                    }
                    T.erase(*iter + W);
                    iter = T.erase(iter);
                }
                if (is_ok) ans++;
            } while (next_permutation(z.begin(), z.end()));
        }
    } while (next_permutation(v.begin(), v.end()));

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
