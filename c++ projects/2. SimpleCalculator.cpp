#include <iostream>
using namespace std;
int main()
{

    int choice;
    float i, j;
    while (1)
    {
        cout << "\n\n1. Addition";
        cout << "\n2. Substraction ";
        cout << "\n3. Multiplication ";
        cout << "\n4. Division ";
        cout << "\n5. EXIT program";

        cout << "\n\n ENTER YOUR CHOICE (1,2,3,4,5) : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Two Numbers for Addition : ";
            cin >> i >> j;
            cout << "------\tResult of " << i << " + " << j << " = " << i + j;
            break;
        }
        case 2:
        {
            cout << "Enter Two Numbers for Substraction : ";
            cin >> i >> j;
            cout << "------\tResult of " << i << " - " << j << " = " << i - j;
            break;
        }
        case 3:
        {
            cout << "Enter Two Numbers for Multiplication : ";
            cin >> i >> j;
            cout << "------\tResult of " << i << " * " << j << " = " << i * j;
            break;
        }
        case 4:
        {
            cout << "Enter Two Numbers for Division : ";
            cin >> i >> j;
            if (j != 0)
                cout << "------\tResult of " << i << " / " << j << " = " << i / j;
            else
                cout << "??????\tDivision by Zero(0) not possible";
            break;
        }

        case 5:
            exit(0);

        default:
        {
            cout << "<><><><INVALID INPUT><><><>";
        }
        }
    }
    return 0;
}
