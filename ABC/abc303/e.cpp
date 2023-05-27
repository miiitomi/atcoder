#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> T(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    vector<int> L;
    int n = N;
    for (int i = 0; i < N; i++) {
        if ((int)T[i].size() >= 3) {
            L.push_back((int)T[i].size());
            n -= 1 + (int)T[i].size();
        }
    }
    while (n > 0) {
        L.push_back(2);
        n -= 3;
    }
    sort(L.begin(), L.end());

    for (int i = 0; i < (int)L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
}
