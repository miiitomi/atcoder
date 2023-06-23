#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> v(N+1, 0);
    v[1] = 1;
    v[2] = 1;
    for (int x = 3; x <= N; x++) {
        v[x] = (v[x-1] + v[x-2]) % MOD;
    }
    cout << v[N] << endl;
}
