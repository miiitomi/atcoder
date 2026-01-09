#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll a) {
    ll ans = 0;
    while (a > 0) {
        ans += a%10;
        a /= 10;
    }
    return ans;
}

int main() {
    vector<ll> A(101, 1), f(101, 1);
    for (int i = 1; i <= 100; i++) {
        A[i] = 0;
        for (int j = 0; j < i; j++) {
            A[i] += f[j];
        }
        f[i] = func(A[i]);
    }
    int N;
    cin >> N;
    cout << A[N] << "\n";
}
