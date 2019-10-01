#include <iostream>
using namespace std;

int binary_search(int v[], int n, int k){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int meio = (l+r)/2;
        if(v[meio]==k) return meio;
        else if(v[meio]<k) l = meio+1;
        else r = meio - 1;
    }
    return -1;
}

int main(){
    int v[6] = {1, 4, 7, 8, 10, 16};
    int x = binary_search(v, 6, 10);
    printf("x = %d\n", x);
    x = binary_search(v, 6, 12);
    printf("x = %d\n", x);


    return 0;
}