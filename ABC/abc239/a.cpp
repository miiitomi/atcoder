#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll H;
    cin >> H;
    double ans = sqrt(H*(12800000 + H) + 0.0);
    cout << fixed << setprecision(10) << ans << endl;
}
