#include<stdio.h>
#include<stdbool.h>
struct requirement
{
	bool pen= 0;
	bool paper = 0;
	bool questionpaper=0;
	bool three=0;
};
int main()
{
	int n=3;
	struct reqirement s[n];
	s[0].pen=1;		
	s[1].paper=1;		
	s[2].questionpaper=1;		
	while(s[0].three==0||s[1].three==0||s[2].three==0)
	{
		char ch1,ch2;
		printf("\n chosse a thing that too be place on shared table");
		printf("Menu: \n1.pen\n2.paper\n3.question paper\n Enter the two things which is to be placed on the shared table");
		scanf("%c%c",&ch1,&ch2);
		if(ch1=='1' && ch2=='2' && s[2].three==0)
		{
			s[2].three=1;
			printf("Student three has completed the task");
		}
		if(ch1=='2' && ch2=='3's[0].three==0)
		{
			s[0].three=1;
			printf("Student one completed the task");
		}
		if(ch1=='1' && ch2=='3's[1].three==0)
		{
			s[1].three=1;
			printf("Student second completed the task");
		}
	}
	printf("All students completed the task");
	return 0;
}
