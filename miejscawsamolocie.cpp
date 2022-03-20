#include <bits/stdc++.h>
using namespace std;

int main(){
vector<vector<int>>V(7, vector<int>(5, 0));
vector<vector<int>>Z(7, vector<int>(5, 0));

int k, r;
int zk, zr;
string h,g;
string wybor;
srand(time(NULL));

for(int i = 0; i < 8; i++){
r = rand()%7;
k = rand()%5;

if(V[r][k]==1){
    i--;
} else {
    V[r][k]=1;
}
}

cout<<"Rozpocznij prace z terminalem wpisujac MIEJSCE (kolumna/rzad),"<<endl<<"albo wpisz POROWNANIE spoza zakresu aby wykonac porownanie lub KONIEC aby zakonczyc prace"<<endl;

while(true){
cin>>g;
if(g=="KONIEC"){
    return 0;
} else if(g=="MIEJSCE") {
for(int i = 0; i < 7; i++){
    for(int j = 0; j < 5; j++){
        cout<<V[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"Wpisz polozenie miejsca (kolumna/rzad)"<<endl;
cin>>zk>>zr;
if(zk>0&&zr>0&&zr<8&&zr<6){
if(V[zr-1][zk-1]==1){
    cout<<"Miejsce jest zajete"<<endl;
} else {
    cout<<"Miejsce jest wolne, chcesz je zajac? Napisz TAK jesli chcesz"<<endl;
    cin>>wybor;
    if(wybor=="TAK"){
        cout<<"Zajeto"<<endl;
        V[zr-1][zk-1]=1;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 5; j++){
                cout<<V[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"Nie zajeto miejsca"<<endl;
    }
}
} else {
    cout<<"Nieprawidlowe polozenie miejsca"<<endl;
}
} else if(g=="POROWNANIE"){

for(int i = 0; i < 13; i++){
r = rand()%7;
k = rand()%5;

if(Z[r][k]==1){
    i--;
} else {
    Z[r][k]=1;
}
}

cout<<"Macierz wynikowa:"<<endl;

for(int i = 0; i < 7; i++){
    for(int j = 0; j < 5; j++){
        if(V[i][j]==Z[i][j]&&V[i][j]==1){
            cout<<1<<" ";
        } else {
            cout<<0<<" ";
        }
    }
    cout<<endl;
}

} else {
    cout<<"Nieprawidlowe polecenie"<<endl;
}


}


}

