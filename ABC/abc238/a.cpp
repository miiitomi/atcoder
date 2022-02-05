#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N >= 5) {
        cout << "Yes" << endl;
    } else if (pow(2, N) > N*N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
