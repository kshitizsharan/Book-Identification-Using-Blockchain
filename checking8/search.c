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
int count = 0 ;
int  buffer2[NUMBER_OF_TRANSACTIONS] ;

void searching();
void write();
void read();

int main()
{
    read();
    searching();
    write();
    return 0;
}

void read()
{
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("realcustomercount.txt","r");
    fp2=fopen("bufferZ.txt","r");
    fp3=fopen("database.txt","r");

    fscanf(fp1,"%d\n",&realcustomercount);

    for(int i=0;i<realcustomercount;i++)
        fscanf(fp2,"%d\n",&buffer2[i]);
    
    for(int i=0;i<realcustomercount;i++)
    {
        fscanf(fp3,"%d\n",&array[i].book);
        fscanf(fp3,"%d\n",&array[i].password);
    }

    
}

void write()
{
    FILE *fp1,*fp2,*fp3;

    fp1=fopen("realcustomercount.txt","w");
    fp2=fopen("bufferZ.txt","w+");
    fp3=fopen("database.txt","w+");

    fprintf(fp1,"%d\n",realcustomercount);

    for(int i=0;i<realcustomercount;i++)
        fprintf(fp2,"%d\n",buffer2[i]);

    for(int i=0;i<realcustomercount;i++)
    {
        fprintf(fp3,"%d\n",array[i].book);
        fprintf(fp3,"%d\n",array[i].password);
    }

}

void searching()
{
    int buffer1[NUMBER_OF_TRANSACTIONS];
    int book_id;
    int present = 0;
    int anomally = 0;
    char contact[10];
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("buffer1.txt","r");
    fp2=fopen("buffer2.txt","r");
    fp3=fopen("fakebookowners.txt","a+");

    fscanf(fp2,"%d\n",&count);
    for(int i=0;i<count;i++)
        fscanf(fp1,"%d\n",&buffer1[i]);

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

    for(int i=0;i<realcustomercount;i++)
    {
        if(book_id==buffer2[i])
        {
            anomally=1;
            break;
        }
    }

    // printf("\n\n%d\n\n",present);

    if(anomally==1)
    {
        printf("\n                                               THIS IS NOT AN AUTHENTIC BOOK . SHARE YOUR CONTACT NUMBER FOR MORE DETAILS\n\n");
        printf("                                                                         ");
        scanf("%s",&contact);
        while(strlen(contact)>10||strlen(contact)<10)
        {
            printf("                                                                      INCORRECT NUMBER\n\n");
            printf("                                                                         ENTER AGAIN\n\n");
            printf("                                                                         ");
            scanf("%s",&contact);
        }
        fprintf(fp3,"%s\n",contact);
    }
    else
    {
        if(present==1)
        {
            printf("\n                                                      THIS IS AN AUTHENTIC BOOK . ENJOY YOUR READING\n\n");
            buffer2[realcustomercount] = book_id;

            printf("                                                                       CREATE PASSWORD\n");
            printf("                                                                         ");
            scanf("%d",&array[realcustomercount].password);
            array[realcustomercount].book = book_id ;

            realcustomercount++;

        }
        else
        {
            printf("\n                                                                  COULD NOT FIND THE BOOK\n\n");
        }
    }
    

    // printf("\n\n%d\n\n",realcustomercount);
    // for(int i=0;i<realcustomercount;i++)
    //     printf("%d\n",buffer2[i]);
}