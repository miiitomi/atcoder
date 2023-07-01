#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> C(N), D(M);
    vector<int> P(M+1);
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < M; i++) cin >> D[i];
    for (int i = 0; i < M+1; i++) cin >> P[i];

    int ans = 0;
    for (string c : C) {
        auto iter = find(D.begin(), D.end(), c);
        if (iter == D.end()) {
            ans += P[0];
        } else {
            ans += P[1 + (int)distance(D.begin(), iter)];
        }
    }

    cout << ans << endl;
}
