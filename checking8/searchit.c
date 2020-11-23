#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10
#define MAX_TRANS 5
#define NUMBER_OF_BLOCKS 1000
#define NUMBER_OF_TRANSACTIONS (NUMBER_OF_BLOCKS*MAX_TRANS)

int realcustomercount = 0 ;
int count = 0 ;
int  buffer2[NUMBER_OF_TRANSACTIONS] ;

// void write();

int main()
{   
    
    int realcustomercount;
    int buffer1[NUMBER_OF_TRANSACTIONS];
    int book_id;
    int present=0;
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("buffer1.txt","r");
    fp2=fopen("buffer2.txt","r");

    fscanf(fp2,"%d\n",&count);
    for(int i=0;i<count;i++)
        fscanf(fp1,"%d\n",&buffer1[i]);
    fscanf(fp4,"%d\n",&realcustomercount);
    
    // printf("\n\n%d\n\n",count);
    // for(int i=0;i<count;i++)
    //     printf("%d\n",buffer1[i]);
    
    printf("                                                                    ENTER THE BOOK ID\n\n");
    printf("                                                                             ");
    scanf("%d",&book_id);

    for(int i=0;i<count;i++)
    {
        if(book_id==buffer1[i])
        {
            present=1;
            break;
        }
    }
    
    // printf("\n\n%d\n\n",present);

    if(present==1)
    {
        printf("\n                                                      THIS IS AN AUTHENTIC BOOK . ENJOY YOUR READING\n\n");
        // buffer2[realcustomercount] = book_id;
        // realcustomercount++;

    }
    else
    {
        printf("\n                                        THIS IS NOT AN AUTHINTIC BOOK . PLEASE SHARE YOUR CONTANCT NUMBER FOR MORE DETAILS\n\n");
    }
    



    // printf("\n\n%d\n\n",realcustomercount);
    // for(int i=0;i<realcustomercount;i++)
    //     printf("%d\n",buffer2[i]);
    
    // write();
    // fclose(fp1);
    // fclose(fp2);
}
// void write()
// {
//     FILE *fp1 , *fp2 ;
//     fp1=fopen("realcustomercount.txt","w");
//     fp2=fopen("bufferZ.txt","a+");

//     fprintf(fp1,"%d\n",realcustomercount);
//     for(int i=0;i<realcustomercount;i++)
//         fprintf(fp2,"%d\n",buffer2[i]);

//     // fclose(fp1);
//     // fclose(fp2);
// }