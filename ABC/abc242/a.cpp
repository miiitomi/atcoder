#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    if (X <= A) {
        cout << 1.0 << endl;
    } else if (X <= B) {
        cout << fixed << setprecision(10) << (double)C / (double)(B - A) << endl;
    } else {
        cout << 0.0 << endl;
    }
}
