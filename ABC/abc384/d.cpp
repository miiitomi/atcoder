#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

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

void solve() {
    ll N, S, sum = 0;
    cin >> N >> S;
    vector<ll> A(2*N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[N+i] = A[i];
        sum += A[i];
    }
    S %= sum;
    CumulativeSum<ll> CS(A);

    if (S == 0) {
        cout << "Yes" << endl;
        return;
    }


    for (int i = 0; i < N; i++) {
        ll left = 0, right = N;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            ll tmp = CS.query(i, i+m);
            if (tmp == S) {
                cout << "Yes\n";
                return;
            } else if (tmp < S) {
                left = m;
            } else {
                right = m;
            }
        }

        if (CS.query(i, i+left) == S || CS.query(i, i+right) == S) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
