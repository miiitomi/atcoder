// https://atcoder.jp/contests/abc231/tasks/abc231_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, X;
vector<ll> A;
map<pair<int,ll>, ll> M;

ll rec(int i, ll Y) {
    ll Z = Y;
    if (M.count(make_pair(i, Y))) return M[make_pair(i, Y)];

    ll tmp = Y / A[i];
    Y -= (Y / A[i]) * A[i];

    if (Y == 0) {
        M[make_pair(i, Z)] = tmp;
        return M[make_pair(i, Z)];
    }

    M[make_pair(i, Z)] = tmp + min(rec(i+1, Y), 1 + rec(i+1, -(Y - A[i])));
    return M[make_pair(i, Z)];
}


int main() {
    cin >> N >> X;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    cout << rec(0, X) << endl;
}
