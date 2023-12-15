#include <iostream>

using namespace std;

int main()
{
    
    int a, b, c, d;
    cout << "Enter a, b, c and d: ";
    cin >> a >> b >> c >> d;
    float S = (((a << 1) + (a << 4) + (d << 8) + (d << 5) - (d << 3)) >> 9) - ((b << 7) + (b << 1) - (b << 3)) + ((c << 7) + (c << 1) - (c << 3) + c);
    cout << "Result: " << S << endl;
}
