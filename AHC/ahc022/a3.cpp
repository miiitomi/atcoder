#include <bits/stdc++.h>
using namespace std;

vector<int> DX{-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> DY{-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<pair<int,int>> X(N);
    set<pair<int,int>> Y;
    for (int i = 0; i < N; i++) {
        cin >> X[i].first >> X[i].second;
        Y.insert(X[i]);
    }

    vector<vector<int>> P(L, vector<int>(L, 500));
    for (int i = 0; i < N; i++) P[X[i].first][X[i].second] = -1;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x = X[i].first;
        int y = X[i].second;
        bool can = true;
        for (int k = 0; k < 8; k++) {
            if (P[(x+DX[k]+L)%L][(y+DY[k]+L)%L] != 500) {
                can = false;
                break;
            }
        }
        if (!can) continue;
        count++;
        P[x][y] = 0;
        for (int k = 0; k < 8; k++) {
            if (i & (1 << k)) {
                P[(x+DX[k]+L)%L][(y+DY[k]+L)%L] = 1000;
            } else {
                P[(x+DX[k]+L)%L][(y+DY[k]+L)%L] = 0;
            }
        }
    }

    int c = 0;
    vector<int> remain_idxs;
    for (int i = 0; i < N; i++) {
        if (P[X[i].first][X[i].second] == 0) continue;
        P[X[i].first][X[i].second] = 500 + c*500/(N-count-1);
        remain_idxs.push_back(i);
        c++;
    }
    set<int> main_idxs;
    for (int i = 0; i < N; i++) main_idxs.insert(i);
    for (int a : remain_idxs) main_idxs.erase(a);

    for (int t = 0; t < 1000; t++) {
        vector<vector<int>> P_new(L, vector<int>(L, 0));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (Y.count(make_pair(i,j)) || P[i][j] == 0 || P[i][j] == 1000) {
                    P_new[i][j] = P[i][j];
                    continue;
                }
                for (int k = 0; k < 4; k++) P_new[i][j] += P[(i+dx[k]+L)%L][(j+dy[k]+L)%L];
                P_new[i][j] /= 4;
            }
        }
        P = P_new;
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) cout << P[i][j] << " ";
        cout << endl;
    }

    vector<pair<int,int>> A, B;

    for (int i = 0; i < N; i++) {
        int s = 0;
        for (int j = 0; j < 10; j++) {
            cout << i << " 0 0" << endl;
            int a;
            cin >> a;
            s += a;
        }
        if (s <= 2500) {
            int I = 0;
            for (int k = 0; k < 8; k++) {
                int t = 0;
                for (int j = 0; j < 10; j++) {
                    cout << i << " " << DX[k] << " " << DY[k] << endl;
                    int a;
                    cin >> a;
                    t += a;
                }
                if (t >= 5000) I += (1 << k);
            }
            A.push_back(make_pair(I, i));
            s *= 10;
        } else {
            for (int j = 0; j < 90; j++) {
                cout << i << " 0 0" << endl;
                int a;
                cin >> a;
                s += a;
            }
        }
        B.push_back(make_pair(s, i));
    }

    vector<int> E(N, -1);
    for (auto a : A) {
        int i = a.second;
        int x = a.first;
        if (main_idxs.count(x)) {
            E[i] = x;
            main_idxs.erase(x);
        }
    }
    sort(B.begin(), B.end());
    c = 0;
    for (auto b : B) {
        if (E[b.second] != -1) continue;
        if (main_idxs.size() >= 1) {
            int i = *main_idxs.begin();
            E[b.second] = i;
            main_idxs.erase(i);
        } else {
            E[b.second] = remain_idxs[c];
            c++;
        }
    }

    cout << "-1 -1 -1" << endl;
    for (int e : E) cout << e << endl;
}
