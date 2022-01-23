#include <bits/stdc++.h>
using namespace std;


int ans = 0;

void rec(int N, vector<vector<int>> &A, vector<int> &P, set<int> &R) {
    if (R.empty()) {
        int ans_new = A[0][P[0]];
        set<int> S;
        for (int i = 1; i < 2*N; i++) S.insert(i);
        S.erase(P[0]);
        while (!S.empty()) {
            int v = *S.begin();
            S.erase(v);
            S.erase(P[v]);
            ans_new = ans_new ^ A[v][P[v]];
        }
        ans = max(ans, ans_new);
        return;
    }

    int v = *R.begin();
    R.erase(v);

    for (int w : R) {
        set<int> X = R;
        X.erase(w);
        vector<int> Q = P;
        Q[v] = w;
        Q[w] = v;
        rec(N, A, Q, X);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2*N-1, vector<int>(2*N));
    for (int i = 0; i < 2*N-1; i++) {
        for (int j = i + 1; j < 2*N; j++) {
            cin >> A[i][j];
        }
    }

    set<int> R;
    for (int i = 0; i < 2*N; i++) R.insert(i);

    vector<int> P(2*N, -1);
    rec(N, A, P, R);

    cout << ans << endl;
}
