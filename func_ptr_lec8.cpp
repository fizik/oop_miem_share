#include <iostream>
using namespace std;

int f1(float a, char b) {
    cout<<a<<"; "<<b<<"\n";
    return 1;
}

int f2(float a, char b) {
    cout<<b<<"; "<<a<<"\n";
    return 2;
}

int main() {
    int (*pt2Function)(float, char);
    pt2Function=f1;
    pt2Function(1.1, 'd');
}
