#include <iostream>
using namespace std;

int sum_from_to(int x, int y) {
    // Ensure that x is less than or equal to y
    if (x > y) {
        std::swap(x, y);
    }

    int sum = 0;
    for (int i = x; i <= y; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    int x;
    int y ;
    cout<<"Enter first number"<<endl;
    cin>>x;
    cout<<"Enter last number"<<endl;
    cin>>y;
    int sum = sum_from_to(x, y);
 std::cout << "Sum from " <<  x << " to " << y << "is" << sum << std::endl;
    return 0;
}

