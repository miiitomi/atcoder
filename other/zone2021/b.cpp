#include <bits/stdc++.h>
using namespace std;

int main() {
    float N, D, H;
    cin >> N >> D >> H;
    vector<float> d(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> d.at(i) >> h.at(i);
    }

    float b_max = 0.0;
    for (int i = 0; i < N; i++) {
        float b = ((d.at(i) * H) - (D * h.at(i)))/(d.at(i) - D);

        if (b > b_max) {
            b_max = b;
        }
    }
    cout << b_max << endl;
}