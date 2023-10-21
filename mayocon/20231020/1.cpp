// https://atcoder.jp/contests/abc260/tasks/abc260_b
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int idx;
    int math;
    int english;

    Student(int idx, int math, int english): idx(idx), math(math), english(english) {}
};

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<Student> Students;
    vector<int> A(N), B(N), Accept;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) {
        Students.push_back(Student(i, A[i], B[i]));
    }

    sort(Students.begin(), Students.end(), [](Student &s, Student &t){if (s.math != t.math) return s.math < t.math; else return s.idx > t.idx;});
    for (int i = 0; i < X; i++) {
        Student s = Students.back();
        Students.pop_back();
        Accept.push_back(s.idx);
    }
    sort(Students.begin(), Students.end(), [](Student &s, Student &t){if (s.english != t.english) return s.english < t.english; else return s.idx > t.idx;});
    for (int i = 0; i < Y; i++) {
        Student s = Students.back();
        Students.pop_back();
        Accept.push_back(s.idx);
    }
    sort(Students.begin(), Students.end(), [](Student &s, Student &t){if (s.english+s.math != t.english+t.math) return s.english+s.math < t.english+t.math; else return s.idx > t.idx;});
    for (int i = 0; i < Z; i++) {
        Student s = Students.back();
        Students.pop_back();
        Accept.push_back(s.idx);
    }

    sort(Accept.begin(), Accept.end());

    for (int i : Accept) {
        cout << i + 1 << endl;
    }
}
