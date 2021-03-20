#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    
    int64_t begin = 0;
    int64_t end = pow(10, 7);
    int64_t half;
    int64_t halfhalf;
    string half_string;

    while (end - begin > 1) {
        half = (begin + end) / 2;
        half_string = to_string(half);
        half_string = half_string + half_string;
        halfhalf = stoll(half_string);

        if (halfhalf <= N) {
            begin = half;
        } else {
            end = half;
        }
    }

    cout << begin << endl;
}