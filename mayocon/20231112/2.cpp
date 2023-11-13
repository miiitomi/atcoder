// https://atcoder.jp/contests/abc202/tasks/abc202_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N), cnt(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        cnt[A[i]]++;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }

    ll ans = 0;
    for (int c : C) {
        ans += cnt[B[c]];
    }
    cout << ans << endl;
}
