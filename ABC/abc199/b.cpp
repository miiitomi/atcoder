#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    int a_max = A.at(0);
    int b_min = B.at(0);
    for (int i = 0; i < N; i++) {
        if (A.at(i) > a_max) {
            a_max = A.at(i);
        }
        if (B.at(i) < b_min) {
            b_min = B.at(i);
        }
    }

    if (b_min >= a_max) {
        cout << b_min - a_max + 1 << endl;
    } else {
        cout << 0 << endl;
    }
}