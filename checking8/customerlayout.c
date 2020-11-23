#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10
#define MAX_TRANS 5
#define NUMBER_OF_BLOCKS 1000
#define NUMBER_OF_TRANSACTIONS (NUMBER_OF_BLOCKS*MAX_TRANS)

struct customer{
    int book;
    int password;
};

struct customer array[NUMBER_OF_TRANSACTIONS];
int realcustomercount = 0 ;

void read()
{
    FILE *fp1,*fp2;
   // char pass[MAX];
    fp1=fopen("realcustomercount.txt","r");
    fp2=fopen("database.txt","r");

    fscanf(fp1,"%d\n",&realcustomercount);
    
    for(int i=0;i<realcustomercount;i++)
    {
        fscanf(fp2,"%d\n",&array[i].book);
        fscanf(fp2,"%d\n",&array[i].password);
        //printf("%s\n",pass);
        //strcpy(array[i].password,pass);
    }

    
}

int main()
{
    int book_id;
    int pass;
    int satisfy = 0;
    read();
    printf("                                                                                LOGIN\n\n");
    printf("                                                                          ENTER THE BOOK ID\n");
    printf("                                                                                  ");
    scanf("%d",&book_id);
    printf("                                                                         ENTER THE PASSWORD\n\n");
    printf("                                                                                ");
    scanf("%d",&pass);

    for(int i=0;i<realcustomercount;i++)
    {
        if(pass==array[i].password && book_id==array[i].book)
        {
            satisfy = 1;
            break;
        }
    }
    
    if(satisfy == 1)
    {
        printf("                                                                                GREAT\n\n");
    }
    else
    {
        printf("                                                                           NO TRESPASSING\n\n");
    }
    

}


