#include <iostream>
#include <vector>

using namespace std;

void EXCHANGE(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int PARTITION(vector<int>&A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r-1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            EXCHANGE(A[i], A[j]);
        }
    }
    EXCHANGE(A[i+1], A[r]);
    return i + 1;
}

void QUICKSORT(vector<int>&A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = PARTITION(A, p, r);
        QUICKSORT(A, p, q-1);
        QUICKSORT(A, q+1, r);
    }
}

void print_test(vector<int> A)
{
    vector<int>::iterator i = A.begin();
    while (i != A.end())
        cout << *i++ << " ";
    cout << endl;
}

int main(void)
{
    int arr[9] = {0, 2, 8, 7, 1, 3, 5, 6, 4};
    vector<int> V(9);
    for (int i = 0; i < 9; i++)
    {
        V[i] = arr[i];
    }
    print_test(V);
    QUICKSORT(V, 1, 8);
    print_test(V);
    
    return 0;
}
