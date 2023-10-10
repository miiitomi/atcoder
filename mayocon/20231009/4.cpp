// https://atcoder.jp/contests/abc193/tasks/abc193_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll score(vector<ll> c) {
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        int k = c[i-1];
        ans += i*round(pow(10, k));
    }
    return ans;
}

int main() {
    ll K;
    string S, T;
    cin >> K >> S >> T;

    vector<ll> r(9, K);
    vector<ll> cs(9, 0), ct(9, 0);

    for (int i = 0; i < 4; i++) {
        int x = S[i] - '0';
        r[x-1]--;
        cs[x-1]++;
    
        int y = T[i] - '0';
        r[y-1]--;
        ct[y-1]++;
    }

    double ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            bool ok = true;
            if (r[i-1] == 0) ok = false;
            r[i-1]--;
            cs[i-1]++;
            if (r[j-1] == 0) ok = false;
            r[j-1]--;
            ct[j-1]++;

            double prob = 0.0;
            if (i == j) prob = (double)(r[i-1]+2)*(r[i-1]+1) / (double)((9*K - 8)*(9*K - 9));
            else prob = (double)(r[i-1]+1)*(r[j-1]+1) / (double)((9*K - 8)*(9*K - 9));

            if (ok && score(cs) > score(ct)) ans += prob;

            r[i-1]++;
            cs[i-1]--;
            r[j-1]++;
            ct[j-1]--;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}
