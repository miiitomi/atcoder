#include <bits/stdc++.h>
using namespace std;
const double pi = M_PI;

int main() {
    double a, b, d;
    cin >> a >> b >> d;

    if (a == 0 && b == 0) {
        cout << fixed << setprecision(10) << 0.0 << " " << 0.0 << endl;
        return 0;
    }

    double r = sqrt(a*a + b*b);
    double costheta = a / r;
    double sintheta = b / r;

    double cosd = cos(2.0*pi*(d/360.0));
    double sind = sin(2.0*pi*(d/360.0));

    double x = r*(costheta*cosd - sintheta*sind);
    double y = r*(sintheta*cosd + costheta*sind);

    cout << fixed << setprecision(10) << x << " " << y << endl;
}
