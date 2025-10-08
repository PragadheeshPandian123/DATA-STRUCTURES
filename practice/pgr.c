# include <stdio.h>
union student{
    int x;
    int y;
};

int main(){
    union student s1={1,2};
    printf("%d",s1.x);
}