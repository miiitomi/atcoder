#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    int K;
    cin >> K;
    vector<int> C(K), D(K);
    for (int i = 0; i < K; i++) {
        cin >> C.at(i) >> D.at(i);
    }

    int ans = 0;
    for (int tmp = 0; tmp < (1 << K); tmp++) {
        bitset<16> s(tmp);
        vector<bool> V(N, false);
        for (int i = 0; i < K; i++) {
            if (s[i]) {
                V.at(C.at(i)-1) = true;
            } else {
                V.at(D.at(i)-1) = true;
            }
        }
        int ans_tmp = 0;
        for (int i = 0; i < M; i++) {
            if (V.at(A.at(i)-1) && V.at(B.at(i)-1)) {
                ans_tmp++;
            }
        }
        ans = max(ans, ans_tmp);
    }
    cout << ans << endl;
}