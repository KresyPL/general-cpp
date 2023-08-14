#include <iostream>
#include <algorithm>
#include <cmath>

#define size 29

char A[size][size];
int drawn = 254;

void print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(A[i][j]=='#'){
                std::cout<<char(drawn);
            } else if(A[i][j]=='@'){
                std::cout<<"@";
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<"\n";
    }
}

void clear(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            A[i][j] = ' ';
        }
    }
}

void draw(int x1, int y1, int x2, int y2){
    
    double a;
    double fy;
    double fx;
    int carry;

    if((x2-x1)!=0){
        a = ((double) y2- (double) y1)/((double) x2- (double) x1);
        if(a > 1){ 

            for(int i = std::min(y1,y2); i <= std::max(y1,y2); i++){
                fx = ((double)i - (double)y1)/a + (double) x1;
                fx = std::round(fx);
                carry = fx;
                A[carry][i] = '#';
            }
            
        } else if(a == 1){ 
            
            for(int i = std::min(x1, x2); i <= std::max(x1, x2); i++){
                A[i][i] = '#';
            }


        } else if(a < 1 && a > 0){ 

            for(int i = std::min(x1,x2); i <= std::max(x1,x2); i++){
                fy = a*(i-x1) + y1;
                fy = std::round(fy);
                carry = fy;
                A[i][carry] = '#';
            }

        } else if(a == 0){ 

            for(int i = std::min(x1, x2); i <= std::max(x1,x2); i++){
                A[i][y1] = '#';
            }

        } else if(a < 0 && a > -1) { 
                
                for(int i = std::max(x1,x2); i >= std::min(x1,x2); i--){
                    fy = a*((double) i- (double) x1) + (double) y1;
                    fy = std::round(fy);
                    carry = fy;
                    A[i][carry] = '#';
                }

        } else if(a == -1){ 

            for(int i = std::max(x1, x2); i >= std::min(x1, x2); i--){
                A[std::max(x1,x2)-i+1][i] = '#';
            }

        } else if(a < -1){ 

            for(int i = std::min(y1,y2); i <= std::max(y1,y2); i++){
                fx = ((double)i - (double)y1)/a + (double) x1;
                fx = std::round(fx);
                carry = fx;
                A[carry][i] = '#';
            }

        }

    } else { 
        for(int i = std::min(y1,y2); i <= std::max(y1,y2); i++){
            A[x1][i] = '#';
        }
    }
}

int main(){

    int vertices;
    std::cin>>vertices;

    int ver[vertices][2];

    for(int i = 0; i < vertices; i++){
        std::cin>>ver[i][0]>>ver[i][1];
    }

    for(int i = 0; i < vertices - 1; i++){
        draw(ver[i][0],ver[i][1],ver[i+1][0],ver[i+1][1]);
    }

    draw(ver[vertices-1][0],ver[vertices-1][1],ver[0][0],ver[0][1]);

    print();

}