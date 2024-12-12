#include <iostream>

int main() {
    int n=3;
    char  matrix [n][n]{
         {0,0,0},
         {0,0,0},
         {0,0,0}
    };



    char symbols []{'x','+'};
    srand(time(NULL));
    char u =symbols[rand()%2];
    for (int y=0;y<1;y++) {

        std::cout<<"narisuy "<<u;
    }
    std::cout<<std::endl;




    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cout<<matrix[i][j];
        }
            std::cout<<std::endl;
        }
    char symbol='*';

    int unsigned h=0;
    int unsigned x=0;
    for (int g=0;g<n*2-1;g++){


        while (true) {
            if (u=='x'||u=='+') {
                std::cout<<"vvedite pervuyu koordinatu";
                std::cin>>h;
                std::cout<< "\n";
                std::cout<<"vvedite vtoruyu koordinatu";
                std::cin>>x;
                if ( h<n && x<n && matrix[h][x]==0 ) {
                    break;
                }
                else {std::cout<<"error input   ";}
            }

            else break;
        }
        for (int f=h;f<h+1;h++) {
            for (int o=x;o<x+1;o++) {
                matrix[h][x]=symbol;
                break;

            }break;
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                std::cout<<matrix[i][j];
            }
            std::cout<<std::endl;
        }





    }
    int zero_symbols=0;
    int diaqonal_stars=0;
    int plus_stars=0;
    for (int p=0;p<n;p++) {
        for(int t=0;t<n;t++){
            if  (matrix[p][t]==0){zero_symbols++;}
        }
    }

    for (int b = 0; b < n; ++b) {
        if (u=='+'& matrix[b][n / 2] == symbol & matrix[n / 2][b] == symbol & zero_symbols==n*n-(2*n-1)) {

        }
        else if (u=='x'& matrix[b][b] == symbol & matrix[b][n - b - 1] == symbol & zero_symbols==n*n-(2*n-1)){}
        else std::cout<<"game over";
    }



    return 0;
}
