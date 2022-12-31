#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            S[i+1] = S[i] + 1;
        } else {
            S[i+1] = S[i] - 1;
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int res = S[r+1] - S[l];
        if (res > 0) {
            cout << "win" << endl;
        } else if (res == 0) {
            cout << "draw" << endl;
        } else {
            cout << "lose" << endl;
        }
    }
}
