#include<iostream>
using namespace std;


int acharPivo(int array[], int inicio, int fim){
	int pivo = array[inicio];
    int l = inicio, r = fim+1;
    //printf("pivo = %d\n", pivo);
    do{
        do{
            l++;
        } while(l<fim && array[l]<pivo);
        do{
            r--;
        } while(r>0 && array[r]>pivo);
        int aux = array[l];
        array[l] = array[r];
        array[r] = aux;
    }while(l<r);
    //desfaz a troca porque nesse último l>=r
    int aux = array[l];
    array[l] = array[r];
    array[r] = aux;

    aux = array[inicio];
    array[inicio] = array[r];
    array[r] = aux;
    //for(int i=inicio;i<fim;i++) printf("%d ", array[i]);
    //printf("\n");
    return r;
}

void qSort(int array[], int inicio, int fim){
	if(fim>inicio){
		int part = acharPivo(array, inicio, fim);
    //printf("part = %d\n", part);
		qSort(array, inicio, part-1);
		qSort(array, part+1, fim);
	}	
}

int main(){
    int a[6] {4, 8, 1, -10, 2, -11};
    qSort(a, 0, 6);
    for(int i=0;i<6;i++){
        printf("%d%c", a[i], i==5?'\n':' ');
    }
    return 0;
}