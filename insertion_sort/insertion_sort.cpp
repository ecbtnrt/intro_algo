#include <iostream>
#include <vector>

using namespace std;

void INSERTION_SORT(vector<int>& A)
{
    int i, j;
    int key;
    for (j = 2 ; j < A.size(); j++)
    {
        key = A[j];
        i = j - 1;
        while (i > 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

void print_test(vector<int> v)
{
    vector<int>::iterator i = v.begin();
    while (i != v.end())
        cout << *i++;
    cout << endl;
}

int main(void)
{
    int arr[7] = {0, 5, 2, 4, 6, 1, 3};
    
    vector<int> V;
    for (int i = 0; i < 7; i++)
    {
        V.push_back(arr[i]);
    }

    print_test(V);

    INSERTION_SORT(V);

    print_test(V);
    
    return 0;
}

