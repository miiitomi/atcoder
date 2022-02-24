#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    vector<int> v;
    for (int i = 1; i < N; i++) v.push_back(i);

    int ans = 0;
    do {
        bool b = true;
        int now = 0;
        for (int i = 0; i < N-1; i++) {
            if (!G[now].count(v[i])) {
                b = false;
                break;
            }
            now = v[i];
        }
        if (b) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
