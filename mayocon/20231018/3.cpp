// https://atcoder.jp/contests/abc159/tasks/abc159_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[A[i]]++;
    }

    ll tmp = 0;
    for (int i = 0; i <= N; i++) {
        if (S[i] >= 2) {
            tmp += (S[i] * (S[i]-1)) / 2;
        }
    }

    for (int i = 0; i < N; i++) {
        int a = A[i];
        cout << tmp - (S[a] - 1) << endl;
    }
}
