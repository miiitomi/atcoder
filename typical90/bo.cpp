#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll a, ll b) {
    ll ans = 1LL;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

void f(string &N) {
    int n = N.size();
    ll N_int = 0LL;
    for (int i = 0; i < n; i++) {
        N_int += (ll)((int)(N[i] - '0')) * power(8LL, n-1-i);
    }
    N = "";
    while (N_int != 0LL) {
        N = to_string(N_int % 9) + N;
        N_int /= 9;
    }
    for (int i = 0; i < (int)N.size(); i++) {
        if (N[i] == '8') N[i] = '5';
    }
    if (N == "") N = "0";
}

int main() {
    string N;
    int K;
    cin >> N >> K;

    for (int k = 0; k < K; k++) f(N);
    cout << N << endl;
}
