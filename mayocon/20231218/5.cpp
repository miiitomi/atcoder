// https://atcoder.jp/contests/abc266/tasks/abc266_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> p(N, 0);

    for (int k = 1; k <= 6; k++) {
        p[0] += k * (1.0/6.0);
    }

    for (int i = 1; i < N; i++) {
        for (int k = 1; k <= 6; k++) {
            if (k > p[i-1]) p[i] += k * (1.0/6.0);
            else p[i] += p[i-1] * (1.0/6.0);
        }
    }

    cout << fixed << setprecision(15) << p[N-1] << endl;
}
