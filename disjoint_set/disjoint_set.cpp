#include <iostream>
using namespace std;
/*
 *I want to know there are how many sets!
 *test date
 * 1 2
 * 1 3
 * 0 3
 * 4 5
 */

const int NUM = 6;

int p[NUM], rank[NUM];

void MAKE_SET(int x)
{
    p[x] = x;
    rank[x] = 0;
}

void LINK(int x, int y)
{
    if (rank[x] > rank[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
    }
    if (rank[x] == rank[y])
    {
        rank[y] = rank[y]+1;
    }
}

int FIND_SET(int x)
{
    if (x != p[x])
    {
        p[x] = FIND_SET(p[x]);
    }
    return p[x];
}

void UNION(int x, int y)
{
    LINK(FIND_SET(x), FIND_SET(y));
}

int main()
{
    for (int i = 0; i <= 5; i++)
    {
        MAKE_SET(i);
    }
    UNION(1, 2);
    UNION(1, 3);
    UNION(0, 3);
    UNION(4, 5);
    int count = 0;
    for (int i = 0; i <=5; i++)
    {
        if (p[i] == i)
            count++;
    }
    cout << count << endl;
    return 0;
}
