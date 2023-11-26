#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cout << clamp(a, L, R) << " ";
    }
    cout << endl;
}
