#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

vector<int> rotation(vector<int> &S, int x, int y) {
    vector<int> T = S;
    for (int i = 0; i < H-1; i++) {
        for (int j = 0; j < W-1; j++) {
            T[to_int(x+H-2-i, y+W-2-j)] = S[to_int(x+i, y+j)];
        }
    }
    return T;
}

void solve() {
    cin >> H >> W;
    vector<set<vector<int>>> S(11), T(11);
    vector<int> x(H*W), y(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int k = to_int(i, j);
            cin >> x[k];
            x[k]--;
            y[k] = k;
        }
    }
    S[0].insert(x);
    T[0].insert(y);

    for (int i = 0; i < 10; i++) {
        for (vector<int> v : S[i]) {
            for (int s = 0; s <= 1; s++) {
                for (int t = 0; t <= 1; t++) {
                    S[i+1].insert(rotation(v, s, t));
                }   
            }
        }
        for (vector<int> v : T[i]) {
            for (int s = 0; s <= 1; s++) {
                for (int t = 0; t <= 1; t++) {
                    T[i+1].insert(rotation(v, s, t));
                }   
            }
        }
    }

    int ans = 1e+9;
    for (int i = 0; i <= 10; i++) {
        for (vector<int> v : S[i]) {
            for (int j = 0; j <= 10; j++) {
                if (T[j].count(v)) ans = min(ans, i+j);
            }
        }
    }
    if (ans == 1e+9) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
