#include <iostream>
#include <string>
#include <iterator>
#include <map>

using namespace std;
int size = 100000;
string first, second;
int n;
multimap<char, pair< char, int> > prices;

void init(){

    cin>>first>>second>>n;
    char a,b;
    int price;
    for(int i = 0; i < n ; i++)
    {
        cin>>a>>b>>price;
        pair<char, int> p = make_pair(b, price);
        prices.insert({a,p});
    }
    multimap<char, pair<char,int> > ::iterator itr;
   /* for(itr = prices.begin(); itr != prices.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second.first<<" " <<itr->second.second<<endl;
    }*/
}

int logic(){
    if(first.size() != second.size())
    {
        return -1;
    }
    int sum = 0, i = 0;
    while(i < first.size() && i < second.size())
    {
        if(first[i] == second[i])
        {
            i++;
            continue;
        }
        /*typedef multimap<char, pair<char, int> > :: iterator MMAPIterator;
        pair<MMAPIterator, MMAPIterator> result = prices.equal_range(first);
        for(MMAPIterator it = result.first; i!= result.second; it++)
        {
            if(it->second.first == second[i])
            {
                sum += it->second.second;
                i++;
                break;
            }
        }*/
        i++;
    }
    return sum;

}
int main()
{
    init();
    printf("%d", logic());
    return 0;
}
