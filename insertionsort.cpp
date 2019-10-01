#include <iostream>
using namespace std;

void insertion_sort(int v[], int n){
    for(int i=1;i<n;i++){
        int a = v[i];
        int j = i-1;
        while(j>=0 && v[j]>a){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = a;
    }
}

int main(){
    int v[6] = {5, 2, 9, 10, 1, -19};
    insertion_sort(v, 6);
    for(int i=0;i<6;i++){
        printf("%d%c", v[i], i==5?'\n':' ');
    }
    return 0;
}