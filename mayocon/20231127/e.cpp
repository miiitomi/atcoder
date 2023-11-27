// https://atcoder.jp/contests/abc169/tasks/abc169_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    ll mi, ma;
    vector<ll> v, w;
    for (int i = 0; i < N; i++) {
        v.push_back(A[i]);
        w.push_back(B[i]);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    if (N % 2 == 1) {
        mi = v[N/2];
        ma = w[N/2];
        cout << ma - mi + 1 << endl;
    } else {
        mi = v[(N-1)/2] + v[(N-1)/2 + 1];
        ma = w[(N-1)/2] + w[(N-1)/2 + 1];
        cout << ma - mi + 1 << endl;
    }
}
