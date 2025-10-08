# include <stdio.h>

void tower_of_hanoi(int n,char source,char dest,char spare){
    if(n==1){
        printf("\nMove %c to %c \n",source,dest);
    }
    else{
        tower_of_hanoi(n-1,source,spare,dest);
        tower_of_hanoi(1,source,dest,spare);
        tower_of_hanoi(n-1,spare,dest,source);
    }
}

int main(){
    tower_of_hanoi(4,'A','B','C');
    return 0;
}