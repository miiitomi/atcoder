#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(46, 0), B(46, 0), C(46, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a % 46]++;
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        B[a % 46]++;
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        C[a % 46]++;
    }

    ll ans = 0;
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 46; j++) {
            for (int k = 0; k < 46; k++) {
                if ((i+j+k) % 46 != 0) continue;
                ans += A[i]*B[j]*C[k];
            }
        }
    }
    cout << ans << endl;
}
