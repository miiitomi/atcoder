#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), P(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i) >> P.at(i) >> X.at(i);
    }

    bool can_buy = false;
    int minprice = 1 + pow(10, 9);
    for (int i = 0; i<N; i++) {
        if (A.at(i) < X.at(i) && P.at(i) < minprice) {
            can_buy = true;
            minprice = P.at(i);
        }
    }
    if (can_buy) {
        cout << minprice << endl;
    } else {
        cout << -1 << endl;
    }
}