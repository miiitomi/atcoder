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
    int X, Y;
    cin >> H >> W >> X >> Y;
    X--; Y--;
    vector<string> S(H);
    for (string &s : S) cin >> s;
    string T;
    cin >> T;
    int ans = 0;
    for (char c : T) {
        int a = X, b = Y;
        if (c == 'U') a--;
        else if (c == 'D') a++;
        else if (c == 'L') b--;
        else b++;
        if (is_in(a, b) && S[a][b] != '#') {
            X = a;
            Y = b;
            if (S[a][b] == '@') {
                ans++;
                S[a][b] = '.';
            }
        }
    }
    cout << X+1 << " " << Y+1 << " " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
