#include <bits/stdc++.h>
using namespace std;

vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<pair<int,int>> X(N);
    for (int i = 0; i < N; i++) cin >> X[i].first >> X[i].second;

    vector<vector<int>> P(L, vector<int>(L, 500));

    if (S > 15*15) {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) cout << P[i][j] << " ";
            cout << endl;
        }
        cout << "-1 -1 -1" << endl;
        for (int i = 0; i < N; i++) cout << i << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        P[X[i].first][X[i].second] = i*1000/(N-1);
    }

    for (int t = 0; t < 1000; t++) {
        vector<vector<int>> P_new(L, vector<int>(L, 0));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                for (int k = 0; k < 4; k++) P_new[i][j] += P[(i+dx[k]+L)%L][(j+dy[k]+L)%L];
                P_new[i][j] /= 4;
            }
        }
        for (int k = 0; k < N; k++) P_new[X[k].first][X[k].second] = P[X[k].first][X[k].second];
        P = P_new;
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
