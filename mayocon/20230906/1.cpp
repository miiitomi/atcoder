// https://atcoder.jp/contests/abc265/tasks/abc265_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    ll T;
    cin >> T;
    vector<ll> A(N, 0);
    for (int i = 0; i < N-1; i++) cin >> A[i];
    vector<ll> Y(N, 0);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        Y[x] = y;
    }

    int i = 0;
    while (i < N-1) {
        T += Y[i];
        if (T > A[i]) {
            T -= A[i];
            i++;
        } else {
            break;
        }
    }

    if (i == N-1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
