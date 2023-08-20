#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<pair<int,int>> X(N);
    for (int i = 0; i < N; i++) cin >> X[i].first >> X[i].second;

    vector<vector<int>> P(L, vector<int>(L, 0));
    P[L/2][L/2] = 1000;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) cout << P[i][j] << " ";
        cout << endl;
    }

    vector<vector<pair<int,int>>> Q(N, vector<pair<int, int>>(N, make_pair(0, 0)));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) Q[i][j].second = j;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << i << " " << L/2 - X[j].first << " " << L/2 - X[j].second << endl;
            int q;
            cin >> q;
            Q[i][j].first += q;
        }
    }
    for (int i = 0; i < N; i++) sort(Q[i].begin(), Q[i].end());

    vector<int> E(N, -1);
    vector<bool> done(N, false);
    for (int k = N-1; k >= 0; k--) {
        for (int i = 0; i < N; i++) {
            if (E[i] != -1 || done[Q[i][k].second]) continue;
            done[Q[i][k].second] = true;
            E[i] = Q[i][k].second;
        }
    }

    cout << "-1 -1 -1" << endl;
    for (auto e : E) cout << e << endl;
}
