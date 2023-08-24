#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vector1 = {1, 2, 3, 4, 5};

    // siez 5 of the same elements 5
    vector<int> vector3(5, 12);

    cout << "Vector  = ";

    // ranged loop
    for (int i : vector1)
    {
        cout << i << "  ";
    }

    cout << "\nVector3  = ";

    // ranged loop
    for (int i : vector3)
    {
        cout << i << "  ";
    }
    return 0;
}