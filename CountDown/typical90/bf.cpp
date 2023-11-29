#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    ll z = x;
    while (x > 0) {
        z += x % 10;
        x /= 10;
    }
    return z % ((ll)1e+5);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<bool> reached(1e+5, false);
    vector<int> v;

    while (!reached[N]) {
        reached[N] = true;
        v.push_back(N);
        N = f(N);
        K--;
        if (K == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int i = 0;
    for (int j = 0; j < (int)v.size(); j++) {
        if (v[j] == N) {
            i = j;
            break;
        }
    }

    ll s = v.size() - i;
    K %= s;

    while (K--) N = f(N);
    
    cout << N << endl;
}
