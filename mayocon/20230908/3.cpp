// https://atcoder.jp/contests/abc183/tasks/abc183_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> A(2+(int)2e+5, 0);
    for (int i = 0; i < N; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        A[s] += p;
        A[t] -= p;
    }

    for (int i = 0; i <= 2e+5; i++) {
        A[i+1] += A[i];
    }

    ll max_v = *max_element(A.begin(), A.end());
    if (max_v <= W) cout << "Yes" << endl;
    else cout << "No" << endl;
}
