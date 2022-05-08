#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+9;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    map<int, int> MA, MB;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        int b = B[i];
        if (!MA.count(a)) MA[a] = i;
        if (!MB.count(b)) MB[b] = i;
    }

    vector<int> VA(N, -1), VB(N, -1);
    int va_old = -1;
    int vb_old = -1;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (!MB.count(a)) {
            VA[i] = INF;
        } else {
            VA[i] = max(va_old, MB[a]);
        }
        va_old = VA[i];

        int b = B[i];
        if (!MA.count(b)) {
            VB[i] = INF;
        } else {
            VB[i] = max(vb_old, MA[b]);
        }
        vb_old = VB[i];
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (y >= VA[x] && x >= VB[y]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
