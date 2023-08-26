#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, H, X;
    cin >> N >> H >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 0; i < N; i++) {
        if (H + A[i] >= X) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
