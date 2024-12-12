#include <iostream>

int main() {
    char maze[]=
{"#######"
 "#S#E  #"
 "# ##  #"
 "# #   #"
 "#   ###"
 "#######"
        };

    for (int d=0;d<42;d++){
    int s_index=0;

    for (int  i=0;i<42;i++) {
        if (maze[i]=='S') {s_index=i;}
    }

    int e_index=0;
    for (int j=0;j<42;j++)
        if (maze [j]=='E') {e_index=j;}


    for (int l=0;l<20;l++) {


        if (maze[s_index-1]=='E'|| maze[s_index-7]=='E'||maze[s_index+7]=='E'||maze[s_index-1]=='E') {

            break;}
        else if (maze[s_index-1]==' ') {s_index-=1;maze[s_index]='*';}
        else if (maze[s_index+1]==' ') {s_index+=1;maze[s_index]='*';}
        else if (maze[s_index+7]==' ') {s_index+=7;maze[s_index]='*';}
        else if (maze[s_index-7]==' ') {s_index-=7;maze[s_index]='*';}


    }



    }
    const int width = 7;
    const int height = 6;


    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            std::cout << maze[row * width + col];
        }
        std::cout << std::endl;
    }
}
