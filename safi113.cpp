#include <iostream>
using namespace std;

template <typename T, typename U>
class Pair {
    T first;
    U second;
public:
    Pair(T f, U s) : first(f), second(s) {}
    void display() {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(5, "Hello");
    p1.display();
    Pair<double, int> p2(3.14, 42);
    p2.display();
    return 0;
}