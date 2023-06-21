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
    int N;
    cin >> N;
    vector<int> P(N);

    BIT bit(N);
    int inversion_number = 0;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p--;
        P[i] = p;
        inversion_number += bit.sum(p, N);
        bit.add(p, 1);
    }

    if (inversion_number % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vector<pair<int, int>> V;

    for (int x = 0; x < N-1; x++) {
        int i = distance(P.begin(), find(P.begin(), P.end(), x));

        if (i == x) continue;

        if (i == N-1) {
            V.push_back(make_pair(N-2, N-2));
            swap(P[N-1], P[N-2]);
            swap(P[N-2], P[N-3]);
            i = N-3;
        }

        V.push_back(make_pair(i+1, x));

        for (int k = i-1; k >= x; k--) {
            swap(P[k], P[k+1]);
            swap(P[k+1], P[k+2]);
        }
    }

    cout << (int)V.size() << endl;
    for (auto q : V) {
        cout << q.first << " " << q.second << endl;
    }
}
