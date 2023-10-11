#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    double ans = 0;
    for (int i = 0; i < N; i++) {
        vector<double> V;
        V.reserve(N-1);
        for (int j = 0; j < N; j++) if (i != j) V.push_back(atan2(Y[j]-Y[i]+0.0, X[j]-X[i]+0.0)*180.0/M_PI);
        sort(V.begin(), V.end());

        for (int j = 0; j < N-1; j++) {
            double target = V[j] + 180.0;
            if (target >= 360.0) target -= 360.0;
            auto iter = lower_bound(V.begin(), V.end(), target);

            if (iter == V.end()) iter = V.begin();
            ans = max(ans, min(abs(V[j] - *iter), 360.0 - abs(V[j] - *iter)));

            if (iter == V.begin()) iter = V.end();
            iter--;
            ans = max(ans, min(abs(V[j] - *iter), 360.0 - abs(V[j] - *iter)));
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}
