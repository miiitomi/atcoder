#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum() {}

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
};

ll N, K;
vector<ll> A;
CumulativeSum<ll> S;

ll f(ll x) {
    vector<vector<ll>> p(21, vector<ll>(2*N));
    for (int i = 0; i < 2*N; i++) {
        if (S.query(i, 2*N) >= x) {
            ll left = i, right = 2*N;
            while (right - left > 1) {
                ll m = (left+right)/2;
                if (S.query(i, m) >= x) right = m;
                else left = m;
            }
            p[0][i] = right;
        } else {
            p[0][i] = 2*N;
        }
    }
    for (int k = 0; k < 20; k++) {
        for (int i = 0; i < 2*N; i++) {
            if (p[k][i] < 2*N) p[k+1][i] = p[k][p[k][i]];
            else p[k+1][i] = 2*N;
        }
    }
    bool ok = false;
    ll cnt = N;
    for (int i = 0; i < N; i++) {
        ll x = i;
        for (int k = 0; k <= 20; k++) {
            if (!(K & (1 << k))) continue;
            x = p[k][x];
            if (x == 2*N) break;
        }
        if (x <= i + N) {
            ok = true;
            cnt--;
        }
    }
    if (ok) return cnt;
    else return -1;
}

void solve() {
    cin >> N >> K;
    A.resize(2*N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[N+i] = A[i];
    }
    S = CumulativeSum<ll>(A);
    ll left = 1, right = S.query(0, N)+1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        if (f(m) == -1) right = m;
        else left = m;
    }
    cout << left << " " << f(left) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
