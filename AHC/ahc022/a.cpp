#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<pair<int,int>> X(N);
    for (int i = 0; i < N; i++) cin >> X[i].first >> X[i].second;

    vector<vector<int>> P(L, vector<int>(L, 500));
    for (int i = 0; i < N; i++) {
        P[X[i].first][X[i].second] = (1000/N)*i;
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) cout << P[i][j] << " ";
        cout << endl;
    }

    vector<pair<int, int>> Q(N);
    for (int i = 0; i < N; i++) Q[i] = make_pair(0, i);

    int T = 10000 / N;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < N; i++) {
            cout << i << " 0 0" << endl;
            int q;
            cin >> q;
            Q[i].first += q;
        }
    }
    sort(Q.begin(), Q.end());
    vector<int> E(N);
    for (int i = 0; i < N; i++) E[Q[i].second] = i;

    cout << "-1 -1 -1" << endl;
    for (int e : E) cout << e << endl;
}
