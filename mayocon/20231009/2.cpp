// https://atcoder.jp/contests/abc310/tasks/abc310_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N), C(N);
    vector<set<int>> F(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int x;
            cin >> x;
            F[i].insert(x);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j || P[i] < P[j]) continue;
            bool ok = true;
            for (int v : F[i]) if (!F[j].count(v)) ok = false;
            if (!ok) continue;
            if (F[i].size() < F[j].size() || P[i] > P[j]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
