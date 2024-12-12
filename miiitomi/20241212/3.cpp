// https://atcoder.jp/contests/abc182/tasks/abc182_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll N, M;
    cin >> H >> W >> N >> M;
    vector<string> S(H, string(W, '.'));
    vector<int> A(N), B(N), C(M), D(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        S[A[i]][B[i]] = 'a';
    }
    for (int i = 0; i < M; i++) {
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
        S[C[i]][D[i]] = 'x';
    }
    for (int i = 0; i < N; i++) {
        int x = A[i], y = B[i];
        for (int k = 0; k < 4; k++) {
            int a = x + dx[k], b = y + dy[k];
            while (is_in(a, b) && (S[a][b] == '.' || S[a][b] == 'o')) {
                S[a][b] = 'o';
                a += dx[k];
                b += dy[k];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'o' || S[i][j] == 'a') ans++;
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
