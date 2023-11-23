// https://atcoder.jp/contests/abc245/tasks/abc245_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N+1, 0), B(M+1, 0), C(N+M+1, 0);
    for (int i = 0; i <= N; i++) cin >> A[i];
    for (int i = 0; i <= N+M; i++) cin >> C[i];

    B[M] = C[N+M] / A[N];
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            if(0 <= N-i+j && N-i+j <= N) C[N+M-i] -= B[M-j]*A[N-i+j];
        }
        B[M-i] = C[N+M-i]/A[N];
    }

    for (ll b : B) cout << b << " ";
    cout << endl;
}
