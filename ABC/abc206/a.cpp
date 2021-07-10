#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    double x = 1.08 * N;
    if (x < 206.0) {
        cout << "Yay!" << endl;
    } else if (x >= 207.0) {
        cout << ":(" << endl;
    } else {
        cout << "so-so" << endl;
    }
}
