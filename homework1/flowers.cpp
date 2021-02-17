#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n,d,l,cnt=0;
bool isWrong = true;

void finddrops(vector<long long> &v, vector<long long> &cop, long long left, long long r)
{
    if(left<=r)
    {
        long long mid = (r + left)/2;
        sort(v.begin(), v.begin() + mid);
        bool isValid = true;
        if(v[0] > d)
        {
            isValid = false;
        }
        if(l-v[mid-1] > d)
        {
            isValid = false;
        }
        if(isValid)
        {
            for(long long i = 1; i < mid; i++)
            {
                if(v[i] - v[i-1] > d)
                {
                    isValid = false;
                    break;
                }
            }
        }
        if(isValid)
        {
            isWrong = false;
            if(n == 1)
            {
                cnt = mid+1;
                return;
            }else{
                cnt = mid;
            }
            for(long i = 0; i < mid; i++)
            {
                v[i]=cop[i];
            }
            finddrops(v,cop,left,mid-1);
        }else{
            cnt = mid+1;
            finddrops(v,cop,mid+1, r);
        }
        if(isWrong)
        {
            sort(v.begin(), v.begin() + n);
            if(v[0] > d || l-v[n-1] > d)
            {
                cnt = -1;
                return;
            }
            for(int i = 1; i < n; i++)
            {
                if(v[i]-v[i-1] > d)
                {
                    cnt = -1;
                    return;
                }
            }
        }
    }
}

int main()
{
    long long x,a,b;
    scanf("%lld%lld%lld%lld%lld%lld",&n,&l,&d,&x,&a,&b);
    if(n == 1)
    {
       if((l - x > d) || (x > d))
        {
          cout<<-1;
          return 0;
        }else{
            cout<<1;
            return 0;
        }
    }
    vector<long long> cop;
    vector<long long> v;
    v.resize(n,0);
    cop.resize(n,0);
    v[0] = x;
    cop[0] = x;
    for(long long i = 1; i < n ; i++)
    {
        x = (x * a + b) % (l + 1);
        v[i] = x;
        cop[i] = v[i];
    }
    finddrops(v,cop,0, n-1);
    printf("%lld", cnt);
    return 0;
}
