// https://atcoder.jp/contests/abc181/tasks/abc181_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                ll a1 = X[i] - X[j], a2 = X[i] - X[k], b1 = Y[i] - Y[j],  b2 = Y[i] - Y[k];
                ll s = a1*b2 - a2*b1;
                if (s == 0) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}
