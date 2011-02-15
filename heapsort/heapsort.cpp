#include <iostream>
#include <vector>

using namespace std;

int PARENT(int i)
{
    return i/2;
}

int LEFT(int i)
{
    return 2*i;
}

int RIGHT(int i)
{
    return 2*i+1;
}

void EXCHANGE(int& a, int& b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

void MAX_HEAPIFY(vector<int>& A, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;
    
    if (l <= A.size() - 1 && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= A.size() - 1 && A[r] > A[largest])
        largest = r;
    
    if (largest != i)
    {
        EXCHANGE(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}

void BUILD_MAX_HEAP(vector<int>& A)
{
    for (int i = (A.size() - 1)/2; i >= 1; i--)
    {
        MAX_HEAPIFY(A, i);
    }
}

void HEAPSORT(vector<int>& A)
{
    BUILD_MAX_HEAP(A);
    for (int i = A.size() - 1; i >= 2; i--)
    {
        EXCHANGE(A[1], A[i]);
        cout << A[i]<< " ";
        A.pop_back();
        MAX_HEAPIFY(A, 1);
    }
    cout << endl;
}



int main(void)
{
    int arr[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    vector<int> V(11);
    for (int i = 0; i < 11; i++)
    {
        V[i] = arr[i];
    }

    HEAPSORT(V);

    return 0;
}
