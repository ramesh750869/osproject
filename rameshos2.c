#include<stdio.h> 
#include<conio.h>

void thirdIteration(int num,int remt[10],int current_time,int arrt[10], int burt[10]);

int main() 
{
	int pno,j,num,currentTime,remainingProcess,flag,tq,wt,tut,arrt[10],burt[10],remt[10],iterator=1;
	flag = 0;
	wt = 0;
	tut = 0;
	printf("Enter number of processes... "); 
	scanf("%d",&num);
	remainingProcess = num;
	
	printf("\nEnter details of the processes\n");
	for(pno = 0;pno < num;pno++) 
	{
		printf("\nProcess P%d\n\t",pno+1);
		printf("Arrival time = "); 
		scanf("%d",&arrt[pno]);
		printf("\tBurst time = "); 
		scanf("%d",&burt[pno]); 
		remt[pno]=burt[pno]; 
	} 
	
	printf("___________________________________________________________\n");
	printf("\nFirst iteration... (time quantum = 3)\n"); 
	tq=3;
	currentTime=0;
	for(pno=0;remainingProcess!=0;) 
	{
		if(remt[pno]<=tq && remt[pno]>0)	//Process can be executed before time quantum expires
		{ 
			currentTime+=remt[pno]; 
			remt[pno]=0; 
			flag=1; 
		} 
		else if(remt[pno]>0)
		{ 
			remt[pno]-=tq; 
			currentTime+=tq; 
		} 
		if(remt[pno]==0 && flag==1)			//Current process is completely executed
		{ 
			remainingProcess--;				//decrement process counter
			printf("P%d",pno+1); 
			printf("\t\t\t%d",currentTime-arrt[pno]);
			printf("\t\t\t%d\n",currentTime-burt[pno]-arrt[pno]);
			wt+=currentTime-arrt[pno]-burt[pno]; 
			tut+=currentTime-arrt[pno]; 
			flag=0; 
		} 
		if(pno==num-1){
			iterator++;
			if(iterator==2){
				pno=0;
				tq=6;
				printf("\nFirst iteration completes...");
				printf("\n___________________________________________________________\n");
				printf("\nSecond iteration starts... (time quantum 6)\n\n");
			}
			else{
				printf("\n\nSecond iteration completes...");
				break;
			}
		}
		else if(currentTime >= arrt[pno+1]){
			pno++;
		}
		else{
			pno=0;
		}
	}
	
	thirdIteration(num,remt,currentTime,arrt,burt);
	
	return 0;
}


void thirdIteration(int num,int remt[10],int current_time,int arrt[10], int burt[10]){
	
	float averagewt,averagetut;
    int i,j,n=num,temp,btime[20],pno[20],wtime[20],tutime[20],total=0,loc;
    
    printf("\n___________________________________________________________\n");
    printf("\nThird iteration started...(least burst time)\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        wtime[i]=current_time-arrt[i]-btime[i];
		pno[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=pno[i];
        pno[i]=pno[loc];
        pno[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	wtime[i]+=btime[j];
        }
        total+=wtime[i];
    }
 
    averagewt=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tutime[i]=btime[i]+wtime[i];
        total=total + tutime[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",pno[i],btime[i],wtime[i],tutime[i]);
    }
    averagetut=(float)total/n;
    printf("\n\nAverage waiting time of execution = %f",averagewt);
    printf("\nAverage turnaround time of execution = %f\n",averagetut);
	
}
