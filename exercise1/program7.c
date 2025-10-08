#include <stdio.h>
struct student {
    int roll_no;
    char name[50];
    float math, physics, chemistry;
    float total;
    int rank;
};

void computeRanks(struct student s[], int n) {
    int i, j;
    struct student temp;

    for (i = 0; i < n; i++) {
        s[i].total = s[i].math + s[i].physics + s[i].chemistry;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].total < s[j + 1].total) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i > 0 && s[i].total == s[i - 1].total) {
            s[i].rank = s[i - 1].rank; 
        } else {
            s[i].rank = i + 1;
        }
    }
}

void getstudent(struct student *stptr);
void printstudent(struct student *stptr);
int main() {
    
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student s[n];

    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
       	getstudent(&s[i]);
    }


    computeRanks(s, n);

    for (i = 0; i < n; i++) {
        printf("\nS.no %d:\n", i + 1);
        printstudent(&s[i]);
    }

    return 0;
}
void getstudent(struct student *stptr)
{
        printf("Roll Number: ");
        scanf("%d", &stptr->roll_no);

        printf("Name: ");
        scanf(" %[^\n]s", stptr->name);

        printf("Mathematics mark: ");
        scanf("%f", &stptr->math);

        printf("Physics mark: ");
        scanf("%f", &stptr->physics);

        printf("Chemistry mark: ");
        scanf("%f", &stptr->chemistry);
}
void printstudent(struct student *stptr)
{
        printf("Roll number: %d\n",stptr->roll_no);
        printf("Name:%s\n",stptr->name);
        printf("Total mark : %.2f\n",stptr->total);
        printf("Computed rank: %d\n",stptr->rank);
}
