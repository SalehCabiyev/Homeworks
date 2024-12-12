#include  <iostream>
#include <string.h>


void str_cpy(char *source,char *destination) {
    for (int i=0;source[i]!='\0';i++) {
    destination[i]=source[i];
    }
}
 int counter=0;
void str_cat(char*str1,char*str2) {
    while (str1[counter]!='\0') {
        counter++;
    }
    for (int i=0;i<counter-1;i++) {
        str1[counter+i]=str2[i];
    }

}
char symbol='o';
void strchr(char*str,  char symbol) {
    for (int i=0;i<strlen(str);i++) {

        if (str[i]==symbol){std::cout<<symbol;break;}
    }

}

void strstrP(char* str,char *word) {
    for (int i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while (str[i + j] == word[j] && word[j] != '\0') {
            j++;
        }


        if (word[j] == '\0') {
            std::cout <<  word << std::endl;
            return;
        }
    }
}
    void strlength (char* word){
   for (int i=0;i<i+1;i++){
       if (word[i]=='\0'){std::cout<<i;break;}

    }
}



int main() {
    //test 1 strcpy_s
     // char source[] = "Hello ";
    // char destination[100];
    // str_cpy(source,destination);
    // std::cout<<destination;

    //test 2 strcat
    // char str_1[100] = "Hello ";
    // char str_2[] = "World!";
    // str_cat(str_1,str_2);
    // std::cout<<str_1;


    // test 3 strchr
    // char str[] = "Hello, world";
    // strchr(str,symbol);

    //test4  strstr

    // char word[]="Hello";
    // char str[] = "Hello, world";
    // strstrP(str,word);

    //test5 strlen
    // char word[]="DSjkshfdGHKJ";
    // strlength(word);




    return 0;
}
