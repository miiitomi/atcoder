#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int x = A[0];
    for (int i = 1; i < N; i++) x = x & A[i];

    if (x > 0) {
        cout << 1 << endl;
        return;
    }

    bool is_new = true;
    int now;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!is_new || A[i] == 0) {
            now = now & A[i];
            if (now == 0) {
                count++;
                is_new = true;
            }
        } else {
            now = A[i];
            is_new = false;
        }
    }

    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
