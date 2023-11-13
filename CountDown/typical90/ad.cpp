#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> is_prime(N+1, true);
    vector<int> num_factors(N+1, 0);
    int ans = 0;

    for (int x = 2; x <= N; x++) {
        if (is_prime[x]) {
            num_factors[x]++;
            for (int y = 2*x; y <= N; y += x) {
                num_factors[y]++;
                is_prime[y] = false;
            }
        }
        if (num_factors[x] >= K) ans++;
    }

    cout << ans << endl;
}
