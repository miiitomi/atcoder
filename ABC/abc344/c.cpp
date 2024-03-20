#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, L;
    vector<int> A, B, C;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    B.resize(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    cin >> L;
    C.resize(L);
    for (int i = 0; i < L; i++) cin >> C[i];

    set<int> S;
    for (int a : A) for (int b : B) for (int c : C) S.insert(a+b+c);

    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        if (S.count(x)) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
