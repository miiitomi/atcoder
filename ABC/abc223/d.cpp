#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<int> W;
    vector<set<int>> G(N+1), H(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[b].insert(a);
        H[a].insert(b);
    }
    for (int i = 1; i <= N; i++) {
        if (G[i].size() == 0) W.insert(i);
    }
    vector<int> ans;
    while (!W.empty()) {
        int x = *W.begin();
        W.erase(x);
        ans.push_back(x);
        for (int y : H[x]) {
            G[y].erase(x);
            if (G[y].empty()) W.insert(y);
        }
    }
    if ((int)ans.size() != N) cout << -1 << endl;
    else {
        for (int i = 0; i < N; i++) {
            if (i < N-1) cout << ans[i] << " ";
            else cout << ans[i] << endl;
        }
    }
}
