#include <iostream>
#define endl '\n'
using namespace std;

typedef struct{
    string table[101];
    int tam;
} Hash;

//função pra achar a posição que vou colocar na hash
int h(string key){
    int s = key.length();
    int x = 0;
    for(int i=0;i<s;i++){
        x += (19*((int)key[i]*(i+1))) % 101;
    }
    return x%101;
}

Hash iniHash(){
    Hash aux;
    aux.tam = 0;
    for(int i=0;i<101;i++) aux.table[i] = "";
    return aux;
}

void addHash(Hash *map, string str){
  //cout << "oi" << endl;
  int pos = h(str);
  //cout << "pos=" << pos << endl;
  if(map->table[pos]!=str){
    if(map->table[pos]==""){
      //cout << "map->table[pos]=" << map->table[pos] << endl;
      map->table[pos] = str; 
      map->tam++;
    } else{
      int ind = -1;
      if(map->table[pos]=="NaoTaOcupado") ind = pos;
      bool coloquei = false, naoAchei = true;
      for(int i=1;i<=19;i++){
        int pos2 = (pos + i*i + i*23) % 101;
        if(map->table[pos2]==str){
          naoAchei = false;
          break;
        } 
        if(map->table[pos2]=="NaoTaOcupado"){
          if(ind==-1) ind = pos2;
        }
        if(map->table[pos2]==""){
          if(ind==-1){
            map->table[pos2] = str; 
            map->tam++;
          } else{
            map->table[ind] = str; 
            map->tam++;
          }
          coloquei = true;
          break;
        }
      }
      if(!coloquei && ind!=-1 && naoAchei){
        map->table[ind] = str; 
        map->tam++;
      }
    }
  }
}

void delHash(Hash *map, string str){
    int pos = h(str);
    if(map->table[pos]==str){
        map->table[pos] = "NaoTaOcupado"; 
        map->tam--;
    } else{
        for(int i=1;i<=19;i++){
            int pos2 = (pos + i*i + i*23) % 101;
            if(map->table[pos2]==str){
                map->table[pos2] = "NaoTaOcupado"; 
                map->tam--;
                break;
            } else if(map->table[pos2]=="") break;
        }
    }
}

int main(){

    return 0;
}