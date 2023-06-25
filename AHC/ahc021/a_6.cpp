#include <bits/stdc++.h>
using namespace std;
const int N = 30;
const int M = 465;

int main() {
    vector<vector<int>> b(N, vector<int>(N, -1));
    vector<pair<int, int>> P(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> b[i][j];
            P[b[i][j]] = make_pair(i, j);
        }
    }

    vector<pair<int, int>> V;

    bool update = true;
    while (update) {
        update = false;
        for (int x = 0; x < M-1; x++) {
            int i = P[x].first;
            int j = P[x].second;

            while (i > 0) {
                int p = i-1;
                int q0 = max(j-1, 0);
                int q1 = min(j, p);
                if (x > max(b[p][q0], b[p][q1])) break;
                if (b[p][q0] < b[p][q1]) swap(q0, q1);
                V.push_back(make_pair(i, j));
                V.push_back(make_pair(p, q0));
                swap(P[x], P[b[p][q0]]);
                swap(b[i][j], b[p][q0]);
                i = p;
                j = q0;
                update = true;
            }
        }
    }

    cout << (int)V.size() / 2 << endl;
    for (int i = 0; i < (int)V.size(); i++) {
        if (i % 2 == 0) cout << V[i].first << " " << V[i].second << " ";
        else cout << V[i].first << " " << V[i].second << endl;
    }
}
