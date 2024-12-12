 #include <iostream>
//
// int main() {
//     int n,count;
//     std:: cout <<"N=";
//     std::cin>>n;
//     count=n-2;
//     int space_count=1;
//     int star_count=n-2;
//
//
//     for (int i = 0;i <2 ;i++) {
//
//         for (int k = 0;k < n ;k++) {
//
//             std::cout<<"*";
//
//
//
//         }
//
//         std::cout<< std::endl;
//     }
//     for (int i = 0;i <n-3 ;i++) {
//
//         for (int k = 0;k < count ;k++) {
//
//             std::cout<<"*";
//
//
//
//
//         }
//         count--;
//         for (int j=0;j<space_count;j++) {
// std::cout<<' ';
//
//
//
//         }
//         space_count++;
//         for (int s=0;s<1;s++) {
//
//
//             std::cout<<'*';
//
//         }
//         std::cout<< std::endl;
//
//     }
//     for (int j=0;j<n;j++) {
//         std::cout<<'*';
//     }
//     return 0;
// }
//
//
//
//
//
// test 2-------------------------------------------------------------------------------------
int main() {
 int n,count ,count1,count2,count3;
 std:: cout <<"N=";
 std::cin>>n;
 count=n;
    count1=n;
    count2=1;
    count3=1;
    int space_count=0;
    int star_count = n-2;
    int space_count2= 0;
    int space_count3=n-2;
    int space_count4=n-2;

    for (int i = 0;i <n ;i++) {
        for (int k = 0;k < count ;k++) {
            std::cout<<"*";
        }
        for (int j=0;j<space_count2;j++) {
            std::cout<<' ';
        }
        space_count2++;

        for (int j=0;j<space_count;j++) {
            std::cout<<' ';
        }
        space_count++;

        for (int k = 0;k < count1 ;k++) {
            std::cout<<"*";

        }




        count1--;
        count--;

        std::cout <<std::endl;
    }
    for (int l=0;l<n;l++) {
        for (int k = 0;k <= count2 ;k++) {
            std::cout<<"*";
        }

        if (count2==n) {
            break;
        }
        for (int j=0;j<space_count3;j++) {
            std::cout<<' ';
        }
        for (int j=0;j<space_count4;j++) {
            std::cout<<' ';
        }
        for (int m = 0;m <= count3 ;m++) {
            std::cout<<"*";
        }
        count3++;
        if (count3==n) {
            break;
        }
        count2++;
        space_count3--;
        space_count4--;
        std::cout <<std::endl;

    }


  return 0;
}