#include <bits/stdc++.h>
using namespace std;

int f(int N, vector<int64_t> &A, int64_t a) {
    int begin = -1;
    int end = N;
    int half = (end + begin) / 2;

    while (end - begin > 1) {
        half = (end + begin) / 2;
        if (A.at(half) <= a) {
            begin = half;
        } else {
            end = half;
        }
    }
    return begin + 1;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N), K(Q);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int j = 0; j < Q; j++) cin >> K.at(j);

    for (int q = 0; q < Q; q++) {
        int64_t ans = K.at(q);
        int64_t ans_old = 0;
        int64_t f_old = 0;
        int64_t f_new = f(N, A, K.at(q));
        while (f_new > f_old) {
            ans += f_new - f_old;
            f_old = f_new;
            f_new = f(N, A, ans);
        }
        cout << ans << endl;
    }
}