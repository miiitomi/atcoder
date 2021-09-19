#include <bits/stdc++.h>
using namespace std;

int T, L, X, Y, Q;

double f(int e) {
    double theta = (3.0/2.0 - 2.0*((e%T+0.0)/(T+0.0)))*M_PI;
    double y = ((L + 0.0)/2.0) * cos(theta);
    double z = ((L + 0.0)/2.0) * sin(theta) + (L+0.0)/(2.0);
    double w = sqrt((Y- y)*(Y-y) + (X+0.0)*(X+0.0));
    double tau = atan(z/w);
    return (tau / M_PI)*180.0;
}

int main() {
    cin >> T >> L >> X >> Y >> Q;
    vector<int> E(Q);
    for (int i = 0; i < Q; i++) cin >> E[i];
    
    cout << fixed << setprecision(12);
    for (int e : E) {
        cout << f(e) << endl;
    }
}
