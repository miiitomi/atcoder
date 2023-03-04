#include <bits/stdc++.h>
using namespace std;

bool local = false;

int N, W, K, C, remain_houses;
vector<int> a, b, c, d;
vector<vector<int>> S;
vector<vector<bool>> flowed;
vector<vector<int>> block_type;  // 0=None, 1=source, 2=house

vector<int> dx{-1, 1, 0, 0};
vector<int> dy{0, 0, -1, 1};

bool check_flowed(int x, int y) {
    if (S[x][y] > 0) {
        return false;
    }

    if (block_type[x][y] == 1) {
        flowed[x][y] = true;
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int s = x + dx[i];
        int t = y + dy[i];
        if (0 <= s && s < N && 0 <= t && t < N) {
            if (flowed[s][t]) {
                flowed[x][y] = true;
                return true;
            }
        }
    }
    return false;
}

void rec_flowing(int x, int y) {
    bool tmp_flowed = check_flowed(x, y);

    if (tmp_flowed) {

        if (block_type[x][y] == 2) remain_houses--;

        for (int i = 0; i < 4; i++) {
            int s = x + dx[i];
            int t = y + dy[i];
            if (0 <= s && s < N && 0 <= t && t < N && !flowed[s][t]) {
                rec_flowing(s, t);
            }
        }
    }
}

int local_destruct(int x, int y, int P) {
    cout << x << " " << y << " " << P << endl;
    S[x][y] -= P;
    if (S[x][y] > 0) {
        return 0;
    } else {
        rec_flowing(x, y);
        if (remain_houses > 0) return 1;
        else return 2;
    }
}

int prd_destruct(int x, int y, int P) {
    cout << x << " " << y << " " << P << endl;
    int r;
    cin >> r;

    if (r == 1) {
        S[x][y] = 0;
        rec_flowing(x, y);
    }

    return r;
}

void solve() {
    int P = 5000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int r;
            if (local) {
                r = local_destruct(i, j, P);
            } else {
                r = prd_destruct(i, j, P);
            }

            if (r == 2) {
                return;
            }
        }
    }
}

int main() {
    cin >> N >> W >> K >> C;

    remain_houses = K;

    a.resize(W);
    b.resize(W);
    c.resize(K);
    d.resize(K);

    S.resize(N);
    for (int i = 0; i < N; i++) S[i].assign(N, 1);

    flowed.resize(N);
    for (int i = 0; i < N; i++) flowed[i].assign(N, false);

    block_type.resize(N);
    for (int i = 0; i < N; i++) block_type[i].assign(N, 0);

    if (local) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> S[i][j];
            }
        }
    }

    for (int i = 0; i < W; i++) {
        cin >> a[i] >> b[i];
        block_type[a[i]][b[i]] = 1;
    }

    for (int i = 0; i < K; i++) {
        cin >> c[i] >> d[i];
        block_type[c[i]][d[i]] = 2;
    }

    solve();
}
