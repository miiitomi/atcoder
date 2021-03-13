#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, W;
    cin >> A >> B >> W;

    if (((1000 * W) / A) == ((1000 * W) / B) && (1000 * W) % B != 0) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    
    int max_value, min_value;
    max_value = (1000 * W) / A;
    if ((1000 * W) % B == 0) {
        min_value = (1000 * W) / B;
    } else {
        min_value = 1 + (1000 * W) / B;
    }

    cout << min_value << " " << max_value << endl;
    return 0;
}