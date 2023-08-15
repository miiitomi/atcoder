#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N = 100;
    ll counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                counter = (counter + (i*j*k)) % 100000;
            }
        }
    }
    cout << counter << endl;
}
