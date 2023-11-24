#include <stdio.h>

int main(){
    int p,c,count=0,allocation[5][3],max[5][3],available[5][3],i,j,need[5][3],done[5],safe[5], terminate=0;
    printf("Enter the number of process and resources");
  scanf("%d %d", & p, & c);
  
  printf("enter allocation of resource of all process %dx%d matrix", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", & allocation[i][j]);
    }
  }
  printf("enter the max resource process required %dx%d matrix", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", & max[i][j]);
    }
  }
  printf("enter the  available resource");
  for (i = 0; i < c; i++)
    scanf("%d", & available[i]);


//calculate the need ,atrix 
printf("the need matrix is :\n");
for( i=0;i<p;i++){
    for(j=0;j<c;j++){
        need[i][j]=max[i][j]-allocation[i][j];
       printf("%d\t",need[i][j]);

    }
    printf("\n");
}
k,k
//now calculating the algorithm
//assign done to check if process already executed or not 
for(i=0;i<p;i++){
    done[i]=0;
}
while(count<p){
    for(i=0;i<p;i++){
        if(done[i]==0){
            for(j=0;j<c;j++){
                if(need[i][j]>available[j])
                break;
            }
            if(j==count){
                safe[count]=i;
                done[i]=1;
            
            for(j=0;j<p;j++){
           available[j]+=allocation[i][j];
            }
            count++;
            terminate=0;
            }
            else terminate++;

        }
    }
}
    return 0;
}