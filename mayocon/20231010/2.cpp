// https://atcoder.jp/contests/abc263/tasks/abc263_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(M);
    for (int i = 1; i <= M; i++) v[i-1] = i;
    set<vector<int>> S;
    do {
        vector<int> x(N);
        bool ok = true;
        for (int i = 0; i < N; i++) {
            x[i] = v[i];
            if (i > 0 && !(x[i-1] < x[i])) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        S.insert(x);
    } while (next_permutation(v.begin(), v.end()));

    for (auto x : S) {
        for (int a : x) cout << a << " ";
        cout << endl;
    }
}
