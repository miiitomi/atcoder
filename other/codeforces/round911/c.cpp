#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int p=-1, l=-1, r=-1;
};

int dfs(int v, vector<Vertex> &V, string &S) {
    if (V[v].l == -1 && V[v].r == -1) return 0;
    int tmp_l = 1e+9, tmp_r = 1e+9;
    if (V[v].l != -1) {
        tmp_l = dfs(V[v].l, V, S);
        if (S[v] != 'L') tmp_l++;
    }
    if (V[v].r != -1) {
        tmp_r = dfs(V[v].r, V, S);
        if (S[v] != 'R') tmp_r++;
    }
    return min(tmp_l, tmp_r);
}

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<Vertex> V(N);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        V[i].l = l;
        V[i].r = r;
        V[l].p = i;
        V[r].p = i;
    }

    cout << dfs(0, V, S) << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
