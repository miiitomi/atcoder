#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll S = 0LL;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }
    ll X;
    cin >> X;
    ll a = X / S;
    ll i = a * N;
    a *= S;
    int idx = 0;
    while (a <= X) {
        a += A[idx];
        idx++;
        i++;
    }
    cout << i << endl;
}
