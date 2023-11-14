#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

int main() {
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> G(4*H*W + 2);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            int a = 4*to_int(i, j);
            for (int k = 0; k < 4; k++) {
                int x=i+dx[k], y=j+dy[k];
                if (!is_in(x, y) || S[x][y] == '#') continue;
                int b = 4*to_int(x, y);
                G[a+k].push_back(b+k);
            }
            for (int p = 0; p < 4; p++) {
                for (int q = p+1; q < 4; q++) {
                    G[a+p].push_back(a+q);
                    G[a+q].push_back(a+p);
                }
            }
        }
    }
    int s = 4*H*W, t = 4*H*W+1;
    int a = 4*to_int(rs, cs), b = 4*to_int(rt, ct);
    for (int l = 0; l < 4; l++) {
        G[s].push_back(a + l);
        G[b + l].push_back(t);
    }
    vector<int> d(4*H*W+2, 1e+9);
    d[s] = 0;
    deque<int> Q;
    Q.push_back(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();
        for (int w : G[v]) {
            int dist = d[v] + (int)(v/4 == w/4);
            if (d[w] <= dist) continue;
            d[w] = dist;
            if (v/4 == w/4) Q.push_back(w);
            else Q.push_front(w);
        }
    }
    cout << d[t] << endl;
}
