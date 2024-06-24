// https://atcoder.jp/contests/abc308/tasks/abc308_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> A, B;

bool cmp(const int i, const int j) {
    if (A[i]*(A[j]+B[j]) == A[j]*(A[i]+B[i])) return i < j;
    return A[i]*(A[j]+B[j]) > A[j]*(A[i]+B[i]);
}

void solve() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        v[i] = i;
    }
    sort(v.begin(), v.end(), cmp);

    for (int x : v) cout << x+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
