#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<pair<int, int>>> &G, int s, int g) {
    vector<int> d(G.size(), 1e+9);
    d[s] = 0;
    deque<int> Q;
    Q.push_back(s);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();
        if (v == g) return d[v];

        for (auto p : G[v]) {
            if (d[v] + p.second >= d[p.first]) continue;

            d[p.first] = d[v] + p.second;
            if (p.second == 0) Q.push_front(p.first);
            else Q.push_back(p.first); 
        }
    }
    return d[g];
}

int main() {
    int H, W;
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<pair<int, int>>> G(2*H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            G[W*i + j].push_back(make_pair(H*W + W*i + j, 1));
            G[H*W + W*i + j].push_back(make_pair(W*i + j, 1));

            if (i < H-1 && S[i+1][j] == '.') {
                G[W*i + j].push_back(make_pair(W*(i+1) + j, 0));
                G[W*(i+1) + j].push_back(make_pair(W*i + j, 0));
            }

            if (j < W-1 && S[i][j+1] == '.') {
                G[H*W + W*i + j].push_back(make_pair(H*W + W*i + j+1, 0));
                G[H*W + W*i + j+1].push_back(make_pair(H*W + W*i + j, 0));
            }
        }
    }

    vector<int> ans;
    ans.push_back(bfs(G, W*rs+cs, W*rt+ct));
    ans.push_back(bfs(G, W*rs+cs, H*W + W*rt+ct));
    ans.push_back(bfs(G, H*W + W*rs+cs, W*rt+ct));
    ans.push_back(bfs(G, H*W +W*rs+cs, H*W + W*rt+ct));

    cout << *min_element(ans.begin(), ans.end()) << endl;;
}
