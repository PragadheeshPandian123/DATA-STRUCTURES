# include <stdio.h>
# include <stdlib.h>
struct student
{
	int rollno;
	char name[50];
	float gpa;
};
int main()
{
	FILE *fp;
	struct student s;
	int n,i;
	fp=fopen("Student.dat","wb");
	if(fp==NULL)
	{
		printf("Cannot open file.\n");
		return 1;
	}
	printf("Enter number of students: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details for student %d \n",i+1);
		printf("Enter roll no: ");
		scanf("%d",&s.rollno);

		printf("Enter Name: ");
		scanf(" %[^\n]s",s.name);

		printf("Enter GPA: ");
		scanf("%f",&s.gpa);
		fwrite(&s,sizeof(s),1,fp);
	}
	fclose(fp);
	printf("\n Student data written to the file successfully. \n");
	struct student s2;
	fp=fopen("Student.dat","rb");
	if(fp==NULL)
	{
		printf("Cannot open file.\n");
		return 1;
	}
	printf("Students Records.\n");
	printf("----------------------------------------------------\n");
	while(fread(&s2,sizeof(s2),1,fp))
	{
		printf("Roll No: %d \n",s2.rollno);
		printf("Name: %s\n",s2.name);
		printf("GPA: %.2f\n",s2.gpa);
		printf("----------------------------------------------------\n");
	}
	fclose(fp);
	return 0;
}
	
