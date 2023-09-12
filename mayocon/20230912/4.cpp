// https://atcoder.jp/contests/abc260/tasks/abc260_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    set<int> S;
    vector<pair<int, int>> V(N+1, make_pair(-1, -1));

    vector<int> A(N+1, -1);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;

        auto iter = S.lower_bound(p);
        if (iter == S.end()) {
            S.insert(p);
            V[p] = make_pair(-1, 1);
        } else {
            int q = *iter;
            S.erase(q);
            S.insert(p);
            V[p] = make_pair(q, V[q].second + 1);
        }

        if (V[p].second == K) {
            S.erase(p);
            while (p != -1) {
                A[p] = i+1;
                p = V[p].first;
            }
        }
    }

    for (int i = 1; i < N+1; i++) cout << A[i] << endl;
}
