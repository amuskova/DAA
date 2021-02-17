#include <iostream>
#include <vector>
#include <string>

using namespace std;
long n,m;
vector< pair<string, pair<long,long> > > names;

int binarySearch(long left, long right, long toFind){
    if(right >= left){
        long mid = left + (right - left) /2;
        if(toFind >= names[mid].second.first && toFind <= names[mid].second.second)
        {
            return mid;
        }
        if(toFind < names[mid].second.first){
            return binarySearch(left, mid-1, toFind);
        }
        return binarySearch(mid+1, right, toFind);
    }
}
void init(){
    scanf("%ld %ld", &n, &m);
    names.reserve(n);
    long before = 0, dif;
    string name;
    name.reserve(15);
    for(long i = 0 ; i < n ; i++)
    {
        cin>>name;
        scanf("%ld", &dif);
        pair<int,int> p = make_pair(before+1, before+dif);
        names.push_back(make_pair(name, p));
        before += dif;
    }
    long toFind;

    for(long i = 0; i < m; i++)
    {
        scanf("%ld", &toFind);
        long ans = binarySearch(0, n-1, toFind);
        cout<<names[ans].first<<endl;
    }
}

int main(){
    init();
    return 0;
}
