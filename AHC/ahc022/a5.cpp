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

    vector<double> Q(N, 0.0);

    int T = 10000 / N;
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < T; t++) {
                cout << i << " 0 0" << endl;
                int q;
                cin >> q;
                Q[i] += q;
        }
        Q[i] /= (double)T;
    }

    vector<int> E(N, -1);
    vector<vector<int>> apply(N);
    set<int> R;
    set<int> R_j;
    for (int i = 0; i < N; i++) {
        R.insert(i);
        R_j.insert(i);
    }
    while (R.size() > 0) {
        for (int i : R) {
            if (E[i] != -1) continue;
            double min_dist = 1e+9;
            int min_idx = -1;
            for (int j : R_j) {
                if (abs(Q[i] - P[X[j].first][X[j].second]) < min_dist) {
                    min_idx = j;
                    min_dist = abs(Q[i] - P[X[j].first][X[j].second]);
                }
            }
            apply[min_idx].push_back(i);
        }

        for (int j : R_j) {
            if (apply[j].size() == 0) continue;
            else {
                int min_idx = -1;
                double min_dist = 1e+9;
                for (int i : apply[j]) {
                    if (abs(Q[i] - P[X[j].first][X[j].second]) < min_dist) {
                        min_idx = i;
                        min_dist = abs(Q[i] - P[X[j].first][X[j].second]);
                    }
                }
                E[min_idx] = j;
                R.erase(min_idx);
                apply[j].resize(0);
                R_j.erase(j);
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    for (int e : E) cout << e << endl;
}
