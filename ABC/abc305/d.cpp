#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sleep_time(vector<ll> &A, vector<ll> &S, int t, int N) {
    auto iter = lower_bound(A.begin(), A.end(), t);
    int idx = distance(A.begin(), iter);

    if (idx == N) return S[N-1];

    if (idx == 0) return 0;

    if (idx % 2 == 1) return S[idx];

    return S[idx] + (t - A[idx]);
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) {
            S[i] = 0;
        } else if (i % 2 == 0) {
            S[i] = S[i-1] + A[i] - A[i-1];
        } else {
            S[i] = S[i-1];
        }
    }

    int Q;
    cin >> Q;

    for (int x = 0; x < Q; x++) {
        int l, r;
        cin >> l >> r;

        cout << sleep_time(A, S, r, N) - sleep_time(A, S, l, N) << endl;
    }
}
