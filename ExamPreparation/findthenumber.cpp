#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

int n,k;
vector<queue<int> > vectorOfQueues;

void init(){
    scanf("%d %d", &k, &n);
    vectorOfQueues.reserve(k+1);
    for(int i = 0; i < k+1; i++){
        vectorOfQueues.push_back(queue<int>());

    }
    int request, where, val;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &request);
        if(request == 0){
            int smallest = INT_MAX-1;
            int position=1;
            for(int j = 1; j < vectorOfQueues.size(); j++){
                if(!vectorOfQueues[i].empty() && vectorOfQueues[j].front() < smallest  ){
                    smallest = vectorOfQueues[j].front();
                    position = j;
                    cout<<smallest<<" "<<position<<endl;
                }
            }
            printf("%d\n", smallest);
            vectorOfQueues[position].pop();
        }else{
            scanf("%d %d", &where, &val);
            vectorOfQueues[where].push(val);
        }

    }

}

int main(){
    init();
    return 0;
}
