#include <iostream>
#include <vector>

using namespace std;

#define INFINITUDE 1000

void MERGE(vector<int>& A, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    vector<int> L(10), R(10);
    
    for (int i = 1; i <= n1; i++)
    {
        L[i] = A[p+i-1];
    }
    for (int j = 1; j <= n2; j++)
    {
        R[j] = A[q+j];
    }
    
    L[n1+1] = INFINITUDE;
    R[n2+1] = INFINITUDE;

    int i = 1;
    int j = 1;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void MERGE_SORT(vector<int>& A, int p , int r)
{
    int q;
    if (p < r)
    {
        q = (p+r)/2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE(A, p, q, r);
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
    int arr[9] = {0, 5, 2, 4, 7, 1, 3, 2, 6};
    vector<int> V(9);
    for (int i = 0; i <= 8; i++)
    {
        V[i] = arr[i];
    }

    print_test(V);
    
    MERGE_SORT(V, 1, 8);

    print_test(V);

    return 0;
}
