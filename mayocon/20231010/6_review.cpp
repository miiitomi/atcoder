// https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> C(N+1, 0), D(N+1, 0), B(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        C[a]++;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B[i] = b;
        D[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (C[i] + D[i] > N) {
            cout << "No" << endl;
            return 0;
        }
        C[i] += C[i-1];
        D[i] += D[i-1];
    }

    int x = 0;
    for (int i = 1; i <= N; i++) x = max(x, C[i] - D[i-1]);

    vector<int> V(N);
    for (int i = 0; i < N; i++) V[(i + x) % N] = B[i];

    cout << "Yes" << endl;
    for (int v : V) cout << v << " ";
    cout << endl;
}
