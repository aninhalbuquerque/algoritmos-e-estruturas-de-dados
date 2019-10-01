#include<iostream>
using namespace std;

void copy(int a[], int b[], int inicio, int fim, int j){
    int k = j;
    for(int i=inicio;i<fim;i++){
        b[k] = a[i];
        k++;
    }
}

void merge(int b[], int c[], int a[], int x, int y){
    int i=0, j=0, k=0;
    while(i<x && j<y){
        //printf("i=%d x=%d j=%d y=%d\n", i, x, j, y);
        if(b[i]<=c[j]){
            a[k] = b[i];
            i++;
        } else{
            a[k] = c[j];
            j++;
        }
        //printf("a[%d]=%d\n", k, a[k]);
        k++;
    }
    if(i==x){
        copy(c, a, j, y, k);
    } else{
        copy(b, a, i, x, k);
    }

}

void mergesort(int a[], int n){
    if(n>1){
        int x = n/2;
        int y = n-x;
        int b[x], c[y];
        copy(a, b, 0, x, 0);
        copy(a, c, x, n, 0);
        mergesort(b, x);
        mergesort(c, y);
        merge(b, c, a, x, y);
    }
}

int main(){
    int a[6] = {3, 1, 0, 5, -1, 7};
    mergesort(a, 6);
    for(int i=0;i<6;i++){
        printf("%d%c", a[i], i==5?'\n':' ');
    }
    return 0;
}