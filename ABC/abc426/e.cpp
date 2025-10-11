#include <bits/stdc++.h>
using namespace std;

double dist(double ax, double ay, double bx, double by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

double f(double tsx, double tsy, double tgx, double tgy, double asx, double asy, double agx, double agy) {
    double left = 0.0, right = 1.0;
    double ans = min(dist(tsx, tsy, asx, asy), dist(tgx, tgy, agx, agy));
    for (int i = 0; i < 100; i++) {
        double l = left + (right - left)*(1.0/3.0);
        double r = left + (right - left)*(2.0/3.0);
        double d1 = dist(tsx+l*(tgx-tsx), tsy+l*(tgy-tsy), asx+l*(agx-asx), asy+l*(agy-asy));
        double d2 = dist(tsx+r*(tgx-tsx), tsy+r*(tgy-tsy), asx+r*(agx-asx), asy+r*(agy-asy));
        ans = min(ans, min(d1, d2));
        if (d1 <= d2) right = r;
        else left = l;
    }
    return ans;
}

void solve() {
    double tsx, tsy, tgx, tgy, asx, asy, agx, agy;
    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
    double tt = dist(tsx, tsy, tgx, tgy), ta = dist(asx, asy, agx, agy);
    if (tt > ta) {
        swap(tsx, asx);
        swap(tsy, asy);
        swap(tgx, agx);
        swap(tgy, agy);
        swap(tt, ta);
    }
    double ans = f(tsx, tsy, tgx, tgy, asx, asy, asx+(agx-asx)*tt/ta, asy+(agy-asy)*tt/ta);
    ans = min(ans, f(tgx, tgy, tgx, tgy, asx+(agx-asx)*tt/ta, asy+(agy-asy)*tt/ta, agx, agy));
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
    }
}
