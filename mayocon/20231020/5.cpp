// https://atcoder.jp/contests/abc232/tasks/abc232_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll a=0, t=0, y=0, o=0;
    if (x1 == x2 && y1 == y2) a++;
    else if (x1 == x2) y++;
    else if (y1 == y2) t++;
    else o++;

    for (int i = 0; i < K; i++) {
        ll na = (t + y) % MOD;
        ll nt = (o + t*(H-2)%MOD + a*(H-1)%MOD) % MOD;
        ll ny = (o + y*(W-2)%MOD + a*(W-1)%MOD) % MOD;
        ll no = (o*(H+W-4)%MOD + t*(W-1)%MOD + y*(H-1)%MOD) % MOD;
        a = na;
        t = nt;
        y = ny;
        o = no;
    }

    cout << a << endl;
}
