#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, M, D;
    cin >> N >> M >> D;

    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }
    vector<ll> eat_cookies(M+1, 0);

    for (int i = 0; i <= M; i++) {
        if (i == 0) {
            eat_cookies[0] = 1;
            eat_cookies[0] += max(0, S[i]-2) / D;
            eat_cookies[0] += (S[i] > 1);
        } else if (i < M) {
            eat_cookies[i] += 1+(max(0, S[i]-S[i-1]-1) / D);
        } else {
            eat_cookies[i] += max(0, N - S[i-1]) / D;
        }
    }

    vector<ll> minus(M, 0);
    for (int i = 0; i < M; i++) {
        if (i == 0) {
            ll tmp_eat_cookies = 1;
            tmp_eat_cookies += max(0, S[i+1]-2)/D;
            tmp_eat_cookies += (S[i+1] > 1);
            minus[0] = -(eat_cookies[1]+eat_cookies[0]-tmp_eat_cookies);
        } else if (i < M-1) {
            ll tmp_eat_cookies = 1 + (max(0, S[i+1]-S[i-1]-1) / D);
            minus[i] = -(eat_cookies[i]+eat_cookies[i+1]-tmp_eat_cookies);
        } else {
            ll tmp_eat_cookies = max(0, N-S[i-1])/D;
            minus[i] = -(eat_cookies[i]+eat_cookies[i+1]-tmp_eat_cookies);
        }
    }

    int min_v = *min_element(minus.begin(), minus.end());
    ll sum = 0;
    for (int a : eat_cookies) sum += a;
    sum += min_v;
    int c = 0;
    for (int m : minus) if (m == min_v) c++;

    cout << sum << " " << c << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
