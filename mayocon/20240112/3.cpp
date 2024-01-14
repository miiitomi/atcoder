// https://atcoder.jp/contests/abc312/tasks/abc312_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll left = 0, right = 2e+9;
    while (right - left > 1) {
        ll m = (right + left) / 2;
        ll s = distance(A.begin(), lower_bound(A.begin(), A.end(), m+1));
        ll d = distance(lower_bound(B.begin(), B.end(), m), B.end());
        if (s >= d) right = m;
        else left = m;
    }

    cout << right << endl;
}
