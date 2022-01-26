#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs1(int v, vector<vector<int>> &G, vector<int> &I, vector<bool> &used){
    if (used[v]) return;
    used[v] = true;
    for (int w : G[v]) {
        dfs1(w, G, I, used);
    }
    I.push_back(v);
}

void dfs2(int v, vector<vector<int>> &H, vector<bool> &used, ll &cnt) {
    if (used[v]) return;
    used[v] = true;
    for (int w : H[v]) {
        dfs2(w, H, used, cnt);
    }
    cnt++;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), H(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }

    vector<bool> used(N, false);
    vector<int> I;
    for (int i = 0; i < N; i++) {
        dfs1(i, G, I, used);
    }

    used.assign(N, false);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll cnt = 0;
        int v = I[N - 1 - i];
        dfs2(v, H, used, cnt);
        ans += (cnt * (cnt - 1)) / 2LL;
    }
    cout << ans << endl;
}
