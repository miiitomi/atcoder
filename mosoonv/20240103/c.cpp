// https://atcoder.jp/contests/abc254/tasks/abc254_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B = A;
    sort(B.begin(), B.end());

    vector<vector<int>> C(K);
    for (int i = 0; i < N; i++) {
        C[i % K].push_back(A[i]);
    }
    for (int k = 0; k < K; k++) {
        sort(C[k].begin(), C[k].end());
        int i = k;
        for (int j = 0; j < C[k].size(); j++) {
            A[i] = C[k][j];
            i += K;
        }
    }

    if (A == B) cout << "Yes" << endl;
    else cout << "No" << endl;
}
