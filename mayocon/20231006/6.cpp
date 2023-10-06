// https://atcoder.jp/contests/abc260/tasks/abc260_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    set<pair<int,int>> S;
    for (int i = 0; i < N; i++) S.insert(make_pair(A[i], i));

    vector<int> f(M+1, 0);
    for (int k = 1; k <= M && S.size() == N; k++) {
        auto iter = S.end();
        iter--;
        int p = iter->first;

        f[p-k+1]++;
        if (k != 1) f[M-k+2]--;

        bool ok = true;
        while (true) {
            auto iter1 = S.begin();
            int x = iter1->first, y = iter1->second;
            if (x == k) {
                S.erase(iter1);
                if (A[y] == x) {
                    S.insert(make_pair(B[y], y));
                } else {
                    ok = false;
                    break;
                }
            } else {
                break;
            }
        }
        if (!ok) break;
    }

    for (int k = 1; k <= M; k++) f[k] = f[k] + f[k-1];
    for (int k = 1; k <= M; k++) cout << f[k] << " ";
    cout << endl;
}
