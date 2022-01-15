#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    map<int, vector<int>> M;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (M.count(a)) {
            M[a].push_back(i);
        } else {
            M[a] = vector<int>(0);
            M[a].push_back(i);
        }
    }

    vector<int> x(Q), k(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x[i] >> k[i];
    }

    for (int i = 0; i < Q; i++) {
        if (M.count(x[i])) {
            if (M[x[i]].size() >= k[i]) {
                cout << 1 + M[x[i]][k[i]-1] << endl;
                continue;
            }
        }
        cout << -1 << endl;
    }
}
