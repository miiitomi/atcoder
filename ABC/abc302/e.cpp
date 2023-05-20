#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<unordered_set<int>> neighbors(N);
    unordered_set<int> unconnected;
    for (int i = 0; i < N; i++) unconnected.insert(i);

    for (int q = 0; q < Q; q++) {
        int k;
        cin >> k;

        if (k == 1) {
            int a, b;
            cin >> a >> b;
            neighbors[a-1].insert(b-1);
            neighbors[b-1].insert(a-1);
            unconnected.erase(a-1);
            unconnected.erase(b-1);

            cout << (int)unconnected.size() << endl;
        } else {
            int a;
            cin >> a;
            a--;
            while (neighbors[a].size() > 0) {
                int b = *neighbors[a].begin();
                neighbors[a].erase(b);
                neighbors[b].erase(a);
                if (neighbors[b].size() == 0) {
                    unconnected.insert(b);
                }
            }
            unconnected.insert(a);
            cout << (int)unconnected.size() << endl;
        }
    }
}
