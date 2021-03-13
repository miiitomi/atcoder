#include <bits/stdc++.h>
using namespace std;

int f(vector<int> W, vector<int> V, vector<bool> E, int x) {
    int max_value = 0;
    int idx = -1;
    for (int i = 0; i < W.size(); i++) {
        if (E.at(i)) {
            continue;
        }
        if (W.at(i) <= x && V.at(i) > max_value) {
            max_value = V.at(i);
            idx = i;
        }
    }
    return idx;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N), X(M), L(Q), R(Q);

    for (int i = 0; i < N; i++) {
        cin >> W.at(i) >> V.at(i);
    }
    for (int i = 0; i < M; i++) {
        cin >> X.at(i);
    }
    for (int i = 0; i < Q; i++) {
        cin >> L.at(i) >> R.at(i);
    }

    for (int q = 0; q < Q; q++) {
        vector<int> Y;

        for (int m = 0; m < M; m++) {
            if (m >= L.at(q)-1 && m <= R.at(q)-1) {
                continue;
            }
            Y.push_back(X.at(m));
        }

        sort(Y.begin(), Y.end());
        vector<bool> E(N, false);
        int ans = 0;

        for (int m = 0; m < Y.size(); m++) {
            int idx = f(W, V, E, Y.at(m));

            if (idx == -1) {
                continue;
            }
            E.at(idx) = true;
            ans += V.at(idx);
        }

        cout << ans << endl;
    }

    return 0;
}