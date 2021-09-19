#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(46, 0LL), B(46, 0LL), C(46, 0LL);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a%46]++;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B[b%46]++;
    }
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        C[c%46]++;
    }

    long long ans = 0LL;
    for (int a = 0; a < 46; a++) {
        for (int b = 0; b < 46; b++) {
            for (int c = 0; c < 46; c++) {
                if ((a+b+c)%46 == 0) {
                    ans += A[a] * B[b] * C[c];
                }
            }
        }
    }

    cout << ans << endl;
}
