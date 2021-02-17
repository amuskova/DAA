#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> seq;
int answer;

void init(){
    scanf("%d", &n);
    seq.reserve(n);
    for(int i = 0; i < n ; i++){
        scanf("%d", &seq[i]);
    }
    answer = n;
}

void solution(){
    for(int i = 0; i < n-1; i++){
        if(seq[i] == seq[i+1]){
            int j = i;
            while(true){
                if(seq[j] != seq[j+1]){
                    break;
                }
                answer++;
                j++;
            }
        }
    }
}
int main(){
    init();
    solution();
    printf("%d", answer);
    return 0;
}
