// https://atcoder.jp/contests/abc329/tasks/abc329_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> V(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        V[i].insert(c);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (V[a].size() < V[b].size()) {
            for (int c : V[a]) V[b].insert(c);
            V[a] = {};
        } else {
            for (int c : V[b]) V[a].insert(c);
            V[b] = {};
            swap(V[a], V[b]);
        }
        cout << V[b].size() << endl;
    }
}
