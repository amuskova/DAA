#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> safe;

int binarySearch(int left, int right, int elem){
    if(right >= left){

    int mid = left + (right - left) / 2;
    if(safe[mid] == elem)
    {
        return mid;
    }else if(safe[mid] > elem){
        return binarySearch(left, mid-1, elem);
    }
    return binarySearch(mid+1, right, elem);
    }
    return -1;
}
void init(){
    scanf("%d", &n);
    safe.resize(n, 0);
    int a;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a);
        safe[i] = a;
    }
    sort(safe.begin(), safe.end());

    while(true){
        cin>>a;
        if(a == 0){
            break;
        }
        int answer = binarySearch(0, n-1, a);
        if(answer == -1){
            printf("-1\n");
            continue;
        }
        printf("%d\n", answer+1);
    }
}

int main(){

    init();

    return 0;
}
