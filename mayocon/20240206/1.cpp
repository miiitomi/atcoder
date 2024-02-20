// https://atcoder.jp/contests/abc294/tasks/abc294_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C.push_back(A[i]);
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        C.push_back(B[i]);
    }
    sort(C.begin(), C.end());

    for (int a : A) cout << distance(C.begin(), lower_bound(C.begin(), C.end(), a)) + 1 << " ";
    cout << "\n";
    for (int a : B) cout << distance(C.begin(), lower_bound(C.begin(), C.end(), a)) + 1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
