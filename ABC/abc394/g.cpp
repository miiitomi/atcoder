#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int Q;
vector<int> A, B, Y, C, D, Z, h;

int H, W;
vector<vector<int>> F;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    F.assign(H, vector<int>(W));
    vector<vector<pair<int,int>>> P(1e+6 + 1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> F[i][j];
            P[F[i][j]].push_back({i, j});
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, y, c, d, z;
        cin >> a >> b >> y >> c >> d >> z;
        a--; b--; c--; d--;
        A.push_back(a); B.push_back(b); Y.push_back(y); C.push_back(c); D.push_back(d); Z.push_back(z);
    }

    vector<int> v(Q);
    iota(v.begin(), v.end(), 0);
    vector<pair<pair<int,int>,vector<int>>> V;
    V.push_back(make_pair(make_pair(1, (int)1e+6 + 1), v));
    h.assign(Q, 0);

    while (!V.empty()) {
        sort(V.begin(), V.end(), [](const auto &l, const auto &r) {return l.first.first > r.first.first;});
        vector<pair<pair<int,int>, vector<int>>> NV;
        dsu U(H*W);
        int f = 1e+6;
        for (auto &[p, w]: V) {
            auto &[l, r] = p;
            if (l+1 == r) {
                for (const int &i : w) {
                    h[i] = l;
                } 
                continue;
            }
            pair<pair<int,int>, vector<int>> p1, p2;
            int m = (l + r) / 2;
            p1.first = {l, m};
            p2.first = {m, r};

            for (;f >= m; f--) {
                for (auto &[i,j]: P[f]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (!is_in(x, y) || F[x][y] < m) continue;
                        U.merge(to_int(i,j), to_int(x,y));
                    }
                }
            }

            for (const int &i: w) {
                if ((Y[i] < m || Z[i] < m) || !U.same(to_int(A[i],B[i]), to_int(C[i],D[i]))) p1.second.push_back(i);
                else p2.second.push_back(i);
            }

            if (!p1.second.empty()) NV.push_back(p1);
            if (!p2.second.empty()) NV.push_back(p2);
        }
        swap(V, NV);
    }

    for (int i = 0; i < Q; i++) {
        cout << Y[i]-h[i] + Z[i]-h[i] << "\n";
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
