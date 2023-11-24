#include <stdio.h>
#include<stdlib.h>
#include<string.h>


 void convert(char h[12]);
char bitmask[12];
char bit[12]={0};

int main(){
    
    char input[10],pn[5],add[6],length[10],relocbit;
    int start,tlen,address,len,opcode,addr,actualadd;
    FILE *fp1,*fp2;
    scanf("%x",&start);
      fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    fscan(fp1,"%s",input);


    while(strcmp(input,"E")!=0){
        if(strcmp(input,"H")==0){
            fscanf(fp1,"%s",pn);
            fscanf(fp1,"%x",add);
             fscanf(fp1,"%x",length);
              fscanf(fp1,"%s",input);

        }

        while(strcmp(input,"T")==0){
            fscanf(fp1,"%x",&address);
            fscanf(fp1,"%x",tlen);
            fscanf(fp1,"%s",bitmask);
             address+=start;
             convert(bitmask);
             len=strlen(bit);
             if(len>=11)
             len=10;
             for(int i=0;i<len;i++){
                 fscanf(fp1, "%x", &opcode);
                fscanf(fp1, "%x", &addr);
                relocbit=bit[i];
                if(relocbit=='0')
                actualadd=addr;
                else
                actualadd=addr+start;
fprintf(fp2, "\n  %x\t\t%x%x\n", address, opcode, actualadd);
                address += 3;
             }
            
  fscanf(fp1, "%s", input);

        }

    }

return 0;

}


void convert(char h[12]){

    int i,l;
    strcpy(bit,"");
    l=strlen(h);
    for(i=0;i<l;i++){
       switch(h[i]){
        case '0':
           strcat(bit,"0");
           break;
       
       case '1':
                strcat(bit,"01");
                break;
      }
     return ;
   }
    
}