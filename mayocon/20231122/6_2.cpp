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
            double a = (x[i] + x[j])/2.0, b = (y[i]+y[j])/2.0;

            double tmp = 0.0;
            for (int l = 0; l < N; l++) {
                tmp = max(tmp, (x[l]-a)*(x[l]-a) + (y[l]-b)*(y[l]-b));
            }
            ans = min(ans, tmp);
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                if ((x[i]-x[j])*(y[j]-y[k]) == (x[j]-x[k])*(y[i]-y[j])) continue;
                double x1 = x[i], x2 = x[j], x3 = x[k], y1 = y[i], y2 = y[j], y3 = y[k];
                double a = ((x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2)) / (2.0 * ((x1-x2)*(y2-y3) - (x2-x3)*(y1-y2)));
                double b = ((x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+(x3*x3+y3*y3)*(x1-x2)) / (2.0 * ((x2-x3)*(y1-y2) - (x1-x2)*(y2-y3)));

                double tmp = 0.0;
                for (int l = 0; l < N; l++) {
                    tmp = max(tmp, (x[l]-a)*(x[l]-a) + (y[l]-b)*(y[l]-b));
                }
                ans = min(ans, tmp);
            }
        }
    }

    cout << fixed << setprecision(15) << sqrt(ans) << endl;
}
