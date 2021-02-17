#include <iostream>
#include <algorithm>
#include <cstdio>
#include <limits.h>

using namespace std;
#define MAX 1000
int n, pos[MAX], answer[MAX][MAX];

void init()
{
    scanf("%d", &n);
    int a,i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if(i == 0)
        {
            pos[i] = a;
        }else{
            pos[i] = pos[i-1] + a;
        }
    }
}
int minCutsPrice(int left = 0, int right = n-1)
{
    if(left >= right)
    {
        return 0;
    }
    if(answer[left][right])
    {
        return answer[left][right];
    }
    int currentMin = minCutsPrice(left+1, right);

    for(int i = left+1; i < right; i++)
    {
        currentMin = min(currentMin, minCutsPrice(left,i) + minCutsPrice(i+1, right));
    }
    return answer[left][right] = currentMin + pos[right] - (left == 0 ? 0 : pos[left - 1]);
}
int main()
{
    init();
    minCutsPrice();
    printf("%d", answer[0][n - 1]);

    return 0;
}
