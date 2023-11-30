// https://atcoder.jp/contests/abc300/tasks/abc300_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;

    ll cnt_all_x = 0;
    vector<ll> v, w;
    ll tmp = 0, tmp2 = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'x') {
            cnt_all_x++;
            v.push_back(tmp);
            tmp = 0;
        } else {
            tmp++;
        }

        if (S[N-1-i] == 'x') {
            w.push_back(tmp2);
            tmp2 = 0;
        } else {
            tmp2++;
        }
    }
    v.push_back(tmp);
    w.push_back(tmp2);

    ll ans = -1;
    if (K < cnt_all_x) {
        ll sum = v[0];
        ll tmp = -1, tmp_idx = 1;
        queue<ll> Q;
        Q.push(v[0]);
        ll k = K;
        while (k--) {
            sum += v[tmp_idx] + 1;
            Q.push(v[tmp_idx]);
            tmp_idx++;
        }
        tmp = max(tmp, sum);
        while (tmp_idx < (int)v.size()) {
            sum -= Q.front();
            Q.pop();
            sum += v[tmp_idx];
            Q.push(v[tmp_idx]);
            tmp = max(sum, tmp);
            tmp_idx++;
        }
        ans = tmp;
    } else {
        ans = N;
    }

    for (int i = 0; i < (int)v.size()-1; i++) {
        v[i+1] += v[i] + 1;
        w[i+1] += w[i] + 1;
    }

    for (int s = 0; s <= min(K, cnt_all_x); s++) {
        ll n=N, m=M, k=K;
        ll tmp = w[s];
        m--;
        k -= s;
        if (k >= cnt_all_x && m >= 1) {
            ll x = min(m, k /cnt_all_x);
            tmp += x * n;
            m -= x;
            k -= cnt_all_x*x;
        }
        if(m >= 1) tmp += v[min(cnt_all_x, k)];
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
