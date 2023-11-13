// https://atcoder.jp/contests/abc268/tasks/abc268_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<string> S;
vector<ll> x, y;

bool cmp(int &i, int &j) {
    return x[i]*y[j] > x[j]*y[i];
}

int main() {
    cin >> N;
    S.resize(N);
    x.assign(N, 0);
    y.assign(N, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        for (char c : S[i]) {
            if (c == 'X') x[i]++;
            else {
                int q = (int)(c - '0');
                ans += x[i] * q;
                y[i] += q;
            }
        }
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), cmp);

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ans += cnt * y[v[i]];
        cnt += x[v[i]];
    }

    cout << ans << endl;
}
