#include <iostream>

using namespace std;
int n,m;

void init(){
    scanf("%d %d", &n, &m);
}

int logic(int l){
    int f[l + 2];
    int i;
    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n]%m;

}

int main(){
    init();
    printf("%d", logic(n));

    return 0;
}
