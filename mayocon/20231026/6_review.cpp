// https://atcoder.jp/contests/abc268/tasks/abc268_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<string> S;
vector<ll> x, y;

bool cmp(int &i, int &j) {
    return x[i] * y[j] > x[j]*y[i];
}

int main() {
    cin >> N;
    S.resize(N);
    x.assign(N, 0);
    y.assign(N, 0);

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S[i] = s;

        for (char c : s) {
            if (c == 'X') x[i]++;
            else {
                int n = (int)(c - '0');
                ans += x[i] * n;
                y[i] += n;
            }
        }
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), cmp);

    ll X = 0;
    for (int i : v) {
        ans += X * y[i];
        X += x[i];
    }

    cout << ans << endl;
}
