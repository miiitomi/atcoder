// https://atcoder.jp/contests/abc257/tasks/abc257_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> x, y, P;

void dfs(int i, vector<bool> &reached, ll S) {
    reached[i] = true;
    for (int j = 0; j < N; j++) {
        if (reached[j]) continue;
        if (P[i]*S >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
            dfs(j, reached, S);
        }
    }
}

int main() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    P.resize(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> P[i];

    vector<bool> reached;

    ll left = 0, right = 5e+9;
    while (right - left > 1) {
        ll mid = (right + left) / 2;

        bool done = false;
        for (int i = 0; i < N; i++) {
            reached.assign(N, false);
            dfs(i, reached, mid);
            bool ok = true;
            for (int j = 0; j < N; j++) if (!reached[j]) ok = false;
            if (ok) {
                done = true;
                break;
            }
        }

        if (done) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
