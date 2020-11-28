#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 6
#define MAX_TRANS 5
#define NUMBER_OF_BLOCKS 1000
#define NUMBER_OF_TRANSACTIONS (NUMBER_OF_BLOCKS*MAX_TRANS)

struct customer{
    int book;
    char password[MAX];
};

struct customer array[NUMBER_OF_TRANSACTIONS];
int realcustomercount = 0 ;

void read()
{
    FILE *fp1,*fp2;
    // char pass[MAX];
    // int cypher ;
    // int number ;
    // int book_id ;
    fp1=fopen("realcustomercount.txt","r");
    fp2=fopen("database.txt","r");

    fscanf(fp1,"%d\n",&realcustomercount);
    
    for(int i=0;i<realcustomercount;i++)
    {
        fscanf(fp2,"%d\n",&array[i].book);
        // book_id = array[i].book ;
        fscanf(fp2,"%s\n",&array[i].password);
        // number = (cypher - (1111*book_id));
        // array[i].password = number;
        //printf("%s\n",pass);
        //strcpy(array[i].password,pass);
        //printf("\n%s\n",array[i].password);
    }

    
}

int main()
{
    int book_id;
    int count = 0;
    //int pass;
    int satisfy = 0;
    int cmp = 0;
    char pass[MAX];
    read();
    printf("                                                                                LOGIN\n\n");
    printf("                                                                          ENTER THE BOOK ID\n");
    printf("                                                                                  ");
    scanf("%d",&book_id);
    printf("                                                                            ENTER THE PIN\n\n");
    printf("                                                                                ");
    //fflush(stdin);
    //fgets(pass, (sizeof(pass)+1) , stdin);
    scanf("%s",pass);
    //printf("\n%s\n",pass);
    for(int i=0;i<realcustomercount;i++)
    {
/*        for(int j=0;j<5;j++)
        {
            if(pass[j]==array[i].password[j])
            {   
                if(j == 4 && count == 4)
                    cmp = 1;
                count++;
            }
        }
        count = 0 ;
    */
        if( strcmp(array[i].password,pass) == 0 && book_id==array[i].book)
        {
            satisfy = 1;
            break;
        }
    }
    
    if(satisfy == 1)
    {
        printf("                                                             THIS IS AN AUTHENTIC BOOK AND ENJOY YOUR READ\n\n");
    }
    else
    {
        printf("                                                                            INCORRECT PIN\n\n");
    }
    

}


