// https://atcoder.jp/contests/abc232/tasks/abc232_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> A(M), B(M);;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[i] = make_pair(a, b);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        B[i] = make_pair(a, b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    do {
        vector<pair<int,int>> C(M);
        for (int i = 0; i < M; i++) {
            int a = B[i].first, b = B[i].second;
            a = v[a];
            b = v[b];
            C[i] = make_pair(min(a, b), max(a, b));
        }
        sort(C.begin(), C.end());
        if (A == C) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
}
