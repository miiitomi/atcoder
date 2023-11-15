#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int k = 0;

    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 2) k++;
        else if (t == 1) {
            x = (x - k) % N;
            if (x < 0) x += N;
            y = (y - k) % N;
            if (y < 0) y += N;
            swap(A[x], A[y]);
        } else {
            x = (x - k) % N;
            if (x < 0) x += N;
            cout << A[x] << endl;
        }
    }
}
