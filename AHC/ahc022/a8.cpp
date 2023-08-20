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

    vector<vector<int>> Q(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << i << " " << L/2 - X[j].first << " " << L/2 - X[j].second << endl;
            int q;
            cin >> q;
            Q[i][j] += q;
            if (q >= 1000) break;
        }
    }

    priority_queue<pair<int,pair<int,int>>> PQ;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pair<int, pair<int,int>> p;
            p.first = Q[i][j];
            p.second = make_pair(i, j);
            PQ.push(p);
        }
    }

    vector<int> E(N, -1);
    vector<bool> done(N, false);
    while (!PQ.empty()) {
        auto p = PQ.top();
        PQ.pop();
        int i = p.second.first;
        int j = p.second.second;
        if (E[i] != -1 || done[j]) continue;
        E[i] = j;
        done[j] = true;
    }

    cout << "-1 -1 -1" << endl;
    for (auto e : E) cout << e << endl;
}
