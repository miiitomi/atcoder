// https://atcoder.jp/contests/abc114/tasks/abc114_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<ll> primes;
    for (int x = 2; x <= N; x++) {
        bool is_prime = true;
        for (int y = 2; y < x-1; y++) if (x % y == 0) is_prime = false;
        if (is_prime) primes.push_back(x);
    }

    vector<ll> cnt(primes.size(), 0);
    for (int x = 2; x <= N; x++) {
        int s = x;
        for (int j = 0; j < primes.size(); j++) {
            int y = primes[j];
            while (s % y == 0) {
                cnt[j]++;
                s /= y;
            }
        }
    }

    vector<vector<ll>> dp(primes.size()+1, vector<ll>(76, 0));
    dp[0][1] = 1;
    for (int i = 0; i < (int)primes.size(); i++) {
        for (int j = 1; j <= 75; j++) {
            for (int k = 1; k <= cnt[i]+1; k++) {
                if (j * k <= 75) {
                    dp[i+1][j*k] += dp[i][j];
                }
            }
        }
    }

    cout << dp[(int)primes.size()][75] << endl;
}
