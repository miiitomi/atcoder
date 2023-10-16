// https://atcoder.jp/contests/abc306/tasks/abc306_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> data;

    BIT(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, ll x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    ll sum(int i) {
        // compute sum of a[i] with i in [0, i)
        ll ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    ll sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    vector<int> v;
    v.reserve(N*M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            v.push_back(A[i][j]);
        }
        sort(A[i].begin(), A[i].end());
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i][j]));
        }
    }


    BIT bit(N*M+1);
    for (int j = 0; j < M; j++) bit.add(A[N-1][j], 1);

    ll ans = 0;
    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            ans += bit.sum(0, A[i][j]);
            ans += (N-1-i)*(j+1);
        }
        for (int j = 0; j < M; j++) bit.add(A[i][j], 1);
    }

    cout << ans << endl;
}
