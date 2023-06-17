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
    vector<int> all;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            all.push_back(A[i][j]);
        }
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            auto iter = lower_bound(all.begin(), all.end(), A[i][j]);
            A[i][j] = distance(all.begin(), iter);
        }
        sort(A[i].begin(), A[i].end());
    }

    ll ans = 0;
    BIT bit(N*M);

    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            int a = A[i][j];
            int x = bit.sum(0, a);
            ans += (j+1) * (N-1-i) + x;
            bit.add(a, 1);
        }
    }

    cout << ans << endl;
}
