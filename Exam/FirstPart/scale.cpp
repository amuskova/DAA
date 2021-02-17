#include <bits/stdc++.h>

using namespace std;
int n,q;
vector<pair<string, pair<long,long> > > v;

void merge(vector<pair<string, pair<long,long> > > &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;


   vector<pair<string, pair<long,long> > > L;
   vector<pair<string, pair<long,long> > > R;
   L.reserve(n1);
   R.reserve(n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if(L[i].second.second == R[j].second.second){
            if(L[i].second.first < R[j].second.first){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
        }
        if (L[i].second.second <= R[j].second.second) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<string, pair<long,long> > > &arr, int l, int r){
    if(l<r){
        int m =l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }

}

int binarySearch(int findElement){
    int left=0, mid = 0, right = n;
    while(left<=right){
        mid = left + (right - left) /2;
        if(v[mid].second.second == findElement){
            right = mid - 1;
        }else if(v[mid].second.second < findElement){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}
void init(){
    scanf("%d %d", &n, &q);
    string name;
    long fn, points;
    v.reserve(n+1);
    for(int i = 0; i < n ; i++){
        cin>>name>>fn>>points;
        pair<long,long> pi = make_pair(fn,points);
        v.push_back(make_pair(name,pi));
    }

    mergeSort(v,0,n-1);
    int questionP;
    for(int i = 0; i < q; i++){
        scanf("%d", &questionP);
        int b = binarySearch(questionP);
        cout<<v[b].first<<" "<<v[b].second.first<<endl;
    }
}

int main(){
    init();
    return 0;
}
