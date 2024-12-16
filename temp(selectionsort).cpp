/*
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement:Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.
*/

// BEGINNING OF CODE
#include<iostream>
using namespace std;
#define max 10

int n;
template <class T>
void selection(T A[max])
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted list : ";
    for (i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    int i, A[max];
    float B[max];
    int choice;
    bool flag1 = true;
    while (flag1)
    {
        cout << "\nYOUR CHOICES ARE......\n";
        cout << "\nSelection sort";
        cout << "\n1. Integer Element: \n2. Float element: \n3. Exit: ";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter desired number of elements: ";
            cin >> n;
            cout << "\nEnter integer elements: \n";
            for (i = 0; i < n; i++)
            {
                cin >> A[i];
            }
            selection(A);
            break;

        case 2:
            cout << "\nFloat elements........";
            cout << "\nEnter desired number of elements: ";
            cin >> n;
            cout << "\nEnter float elements: \n";
            for (i = 0; i < n; i++)
            {
                cin >> B[i];
            }
            selection(B);
            break;

        case 3:
            flag1 = false;
            break;

        default:
            cout << "\nEnter valid choice!!!";
            break;
        }
    }
    return 0;
}
// END OF CODE
