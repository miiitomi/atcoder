// https://atcoder.jp/contests/abc151/tasks/abc151_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    if (N == 2) {
        double X = abs(x[0] - x[1]), Y = abs(y[0] - y[1]);
        double r = X*X + Y*Y;
        cout << fixed << setprecision(15) << sqrt(r) / 2.0 << endl;
        return 0;
    }

    double ans = 1e+8;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                ll a = x[i], b = y[i], c = x[j], d = y[j], e = x[k], f = y[k];
                double px, py;

                if ( ((c != a) || (e != a)) && (2*(e-a)*(b-d) - 2*(c-a)*(b-f) != 0)) {
                    py = (double)((e-a)*(a*a+b*b-c*c-d*d) - (c-a)*(a*a + b*b - e*e - f*f)) / (2.0*(e-a)*(b-d) - 2.0*(c-a)*(b-f));
                    if (c - a != 0) {
                        px = (2.0*(b-d)*py - a*a - b*b + c*c + d*d) / (2.0*(c - a));
                    } else if (e - a != 0) {
                        px = (2.0*(b-f)*py - a*a - b*b + e*e + f*f) / (2.0*(e - a));
                    }
                }else {
                    px = (a + c + e) / 3.0;
                    py = (b + d + f) / 3.0;
                }

                double tmp = 0.0;
                for (int l = 0; l < N; l++) {
                    tmp = max(tmp, (x[l]-px)*(x[l]-px)+(y[l]-py)*(y[l]-py) );
                }
                ans = min(ans, tmp);
            }
        }
    }

    cout << fixed << setprecision(15) << sqrt(ans) << endl;
}
