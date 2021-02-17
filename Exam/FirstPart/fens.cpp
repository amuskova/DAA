#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long N, C;
vector<long> v;

void merge(vector<long> &v, long left, long mid , long right)
{
    long i , j , k;
    long n1=mid-left+1;
    long n2=right-mid;

    vector<long> Left;
    Left.resize(n1,0);
    vector<long> Right;
    Right.resize(n2,0);

    for(i=0;i<n1;i++)
    {
        Left[i]=v[left+i];
    }
    for(j=0;j<n2;j++)
    {
        Right[j]=v[mid+j+1];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(Left[i]<=Right[j])
        {
            v[k]=Left[i];
            i++;
        }
        else
        {
            v[k]=Right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        v[k]=Left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        v[k]=Right[j];
        j++;
        k++;
    }
}
void mergeSort(vector<long> &v ,long left, long right)
{
    if(left<right)
    {
        long mid=left+(right-left)/2;
        mergeSort(v,left,mid);
        mergeSort(v,mid+1,right);

        merge(v,left,mid,right);
    }
}
long check(long n,vector<long> &hotel)
{
    long cow=1;
    long position=hotel[0];
    for (long i=1; i<N; i++)
    {
        if (hotel[i]-position>=n)
        {
            position=hotel[i];
            cow++;
            if (cow==C)
            {
                return 1;
            }
        }
    }
    return 0;
}

long binarySearch(vector<long> &hotels)
{
    long left=0;
    long right=hotels[N-1];
    long m=-1;
    while (right>left)
    {
        long mid=(left+right)/2;
        if (check(mid,hotels)==1)
        {
            if (mid>m)
            {
                m=mid;
            }
            left=mid+1;
        }
        else
        {
            right=mid;
        }

    }
    return m;
}

void init(){
    scanf("%ld %ld", &N, &C);
    v.reserve(N);
    long a;
    for(long i = 0; i < N; i++){
        scanf("%ld", &a);
        v.push_back(a);
    }
    mergeSort(v,0,N-1);
    if(C == 2){
        printf("%ld", v[N-1]-v[0]);
        return;
    }
    printf("%ld", binarySearch(v));
}
int main()
{
    init();
    return 0;
}
