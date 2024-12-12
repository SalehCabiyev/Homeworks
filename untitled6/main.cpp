#include <iostream>
const unsigned n=12;

char pole[n][n]={
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#'}


};
char minnoye_pole[n][n]={
    {'#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#'}


};

int kolicestvo_min=0;


void print_pole(char pole[n][n]){
    for  (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cout<<pole[i][j]<<" ";
        }std::cout<<std::endl;
    }
}

int cislo_min=0;
void randomnoe_razmeseniye_min() {
while (true) {
    srand(time(NULL));
    for (int j=0;j<1;j++) {
        minnoye_pole[rand()%10+1][rand()%10+1]='*';

    }for  (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            minnoye_pole[i][j];
            if (minnoye_pole[i][j]=='*'){cislo_min++;}
        }
    }
    if (cislo_min==kolicestvo_min){break;}
    cislo_min=cislo_min-cislo_min;

}



}
int tocki=0;
int  unsigned k=0;
int unsigned a=0;
int unsigned count=0;
int unsigned win_counter=0;
void naxojdeniye_min() {
    while (true){



        count=count-count;

        std::cout <<"vvedite pervuyu koorinatu (1-10)";
        std::cin>>k;
        std::cout <<"vvedite vtoruyu koorinatu (1-10)";
        std::cin>>a;
        if (minnoye_pole[k][a]=='.') {

            std::cout<<"v etoy yaceyke min ne obnarujeno"<<std::endl;
            pole[k][a]='o',print_pole(pole);
            if (minnoye_pole[k-1][a]=='*'){count++;}

            if (minnoye_pole[k+1][a]=='*'){count++;}
            if (minnoye_pole[k][a-1]=='*'){count++;}
            if (minnoye_pole[k][a+1]=='*'){count++;}
            std::cout<<" radom naxoditsa  " <<count<<" mini" <<std::endl;
        }
            if (minnoye_pole[k][a]=='*'){print_pole(minnoye_pole),std::cout<<"game over"<<std::endl;

                break;}
        tocki=tocki-tocki;
        if (minnoye_pole[k][a]=='o'){win_counter++;}
        for  (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (minnoye_pole[i][j]=='.'){tocki++;}
            }
        }

        if (tocki==0){std::cout<<"you win!";break;}





    }
}


int main() {
    std::cout<<"how many mins?";
    std::cin >>kolicestvo_min ;
    std::cout<<"podojdite idet razmeseniye min ..."<<std::endl;
    randomnoe_razmeseniye_min();
    print_pole(pole);
    naxojdeniye_min();





    return 0;
}
