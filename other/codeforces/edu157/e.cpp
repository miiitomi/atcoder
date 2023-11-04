#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a0, d0, a1, d1;
vector<pair<int,int>> c0, c1;
vector<int> res0, res1;  // 0:未実施, 1:実施中, 2:先攻, 3:後攻, 4:引き分け

int rec(bool first, int d, int i) {
    if (i != -1) {
        if (res0[i] >= 2) return res0[i];
        else {
            res0[i] = 1;
            int r = rec(false, d0[i], -1);
            res0[i] = r;
            return r;
        }
    }

    if (first) {
        i = c0[d].first;
        if (i == -1) {
            return 3;
        } else if (res0[i] >= 2) {
            return res0[i];
        } else if (res0[i] == 1) {
            res0[i] = 4;
            return 4;
        } else {
            res0[i] = 1;
            int r = rec(false, d0[i], -1);
            res0[i] = r;
            return r;
        }
    } else {
        i = c1[d].first;
        if (i == -1) {
            return 2;
        } else if (res1[i] >= 2) {
            return res1[i];
        } else if (res1[i] == 1) {
            res1[i] = 4;
            return 4;
        } else {
            res1[i] = 1;
            int r = rec(true, d1[i], -1);
            res1[i] = r;
            return r;
        }
    }
}

void solve() {
    cin >> N;
    a0.resize(N);
    d0.resize(N);
    for (int i = 0; i < N; i++) cin >> a0[i];
    for (int i = 0; i < N; i++) cin >> d0[i];
    c0.assign(1e+6 + 1, make_pair(-1, 0));
    for (int i = 0; i < N; i++) {
        if (c0[a0[i]-1].second < d0[i]) {
            c0[a0[i]-1] = make_pair(i, d0[i]);
        }
    }
    for (int x = 1e+6; x > 0; x--) {
        if (c0[x-1].second < c0[x].second) {
            c0[x-1] = c0[x];
        }
    }

    cin >> M;
    a1.resize(M);
    d1.resize(M);
    for (int i = 0; i < M; i++) cin >> a1[i];
    for (int i = 0; i < M; i++) cin >> d1[i];
    c1.assign(1e+6 + 1, make_pair(-1, 0));
    for (int i = 0; i < M; i++) {
        if (c1[a1[i]-1].second < d1[i]) {
            c1[a1[i]-1] = make_pair(i, d1[i]);
        }
    }
    for (int x = 1e+6; x > 0; x--) {
        if (c1[x-1].second < c1[x].second) {
            c1[x-1] = c1[x];
        }
    }

    res0.assign(N, 0);
    res1.assign(M, 0);

    int cnt2=0, cnt3=0, cnt4=0;
    for (int i = 0; i < N; i++) {
        int r = rec(true, 0, i);
        if (r == 2) cnt2++;
        else if (r == 3) cnt3++;
        else cnt4++;
    }

    cout << cnt2 << " " << cnt4 << " " << cnt3 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
