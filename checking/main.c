#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#define MAX 10


void verify();
void display();
void addTransactions();

struct block
{
        int block_number;
        char hash[10];
        int transactions[10];
        char prev_hash[10];
        struct block *next;
        //struct block *prev;
};
struct block *head=NULL;
char historyHash[10];
int book_id[MAX];
int rear = - 1;
int front = - 1;

int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
 //             printf("\n 1.Add new Block  \n");
                printf("\n 1.Add Book ID    \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Verify    \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {

                        case 1:
                                        addTransactions();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        verify();
                                        break;
                        case 4:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void verify()
{
    struct block *ptr;
    if(head==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
    else
        {
                ptr=head;
                printf("\nVerifying the blockchain\n");
                while(ptr!=NULL)
                {

                    if(strcmp(ptr->hash,ptr->next->prev_hash)==0)
                    {
                        printf("\nVerified\n");
                    }
                    else
                    {
                        printf("\nIncorrect Blockchain\n");
                    }
                    ptr=ptr->next ;
                }
        }
}
void display()
{
        struct block *ptr;
        if(head==NULL)
        {
                printf("\nBlockcChain is empty:\n");
                return;
        }
        else
        {
                ptr=head;
                printf("\nBLOCKCHAIN :\n\n");
                while(ptr!=NULL)
                {
                        printf("BLOCK No. :  %d\nHash :  %s\nPrevious Hash :  %s\n",ptr->block_number,ptr->hash,ptr->prev_hash );
                        for(int i=0;i<MAX;i++)
                        {
                            printf("Book ID :  %d\n",ptr->transactions[i]);
                        }
                        ptr=ptr->next ;
                }
        }
}
void addTransactions()
{
int item,a;
struct block *temp,*ptr;
char hash_val[10];
char prev_hash_val[10];
if(rear == MAX - 1)
    {
        printf("Completed 10 Transactions (Book ID) For Block Creation \n");
        temp=(struct block *)malloc(sizeof(struct block));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }

        printf("\nEnter the Block Number:\t" );
        scanf("%d",&temp->block_number );
        if(temp->block_number==1)
        {
            printf("\nPrevious Hash:  000");
        }
        else
        {
            printf("\nPrevious Hash:  %s",historyHash);
        }
        printf("\nEnter the previous Hash of a Block:\t" );
        scanf("%s",prev_hash_val);
        strcpy(temp->prev_hash,prev_hash_val);

        for(int i=0;i<MAX;i++)
        {
            temp->transactions[i]=book_id[front];;
            book_id[front]=0;
            front = front + 1;
        }
//--------------------------------------------------------------------------------------------------------
        // Making it again -1 so that next transactions could be added
        rear = - 1;
        front = - 1;
//--------------------------------------------------------------------------------------------------------
        temp->next =NULL;


//---------------------------------------------------------------------------------------------------------
        int j=0,count=0;
        char base_string[500];
        //char yalayolo[500];
        char rev_base_string[500];
        char str[20];
        base_string[0]='\0';
        if(temp->block_number==1)
        {
            //temp->prev_hash=="0000000000";
            for(int i=0;i<MAX;i++)
            {
                sprintf(str, "%d", temp->transactions[i]);
                strcat(base_string, str);
            }
            strcat(base_string,temp->prev_hash);
            //strcat(base_string,"kshitiz151");
            for(int i=(strlen(base_string)-1);i>=0;i--)
            {
                rev_base_string[j]=base_string[i];
                j++;
            }
            for(int i=0;i<strlen(base_string);i++)
            {
                if(rev_base_string[i]=='t'||rev_base_string[i]=='T')
                {
                    if(rev_base_string[i]=='t')
                    {
                        rev_base_string[i]='a';
                    }
                    else
                    {
                        rev_base_string[i]='A';
                    }
                }
                else if(rev_base_string[i]=='u'||rev_base_string[i]=='U')
                {
                    if(rev_base_string[i]=='u')
                    {
                        rev_base_string[i]='b';
                    }
                    else
                    {
                        rev_base_string[i]='B';
                    }
                }
                else if(rev_base_string[i]=='v'||rev_base_string[i]=='V')
                {
                    if(rev_base_string[i]=='v')
                    {
                        rev_base_string[i]='c';
                    }
                    else
                    {
                        rev_base_string[i]='C';
                    }
                }
                else if(rev_base_string[i]=='w'||rev_base_string[i]=='W')
                {
                    if(rev_base_string[i]=='w')
                    {
                        rev_base_string[i]='c';
                    }
                    else
                    {
                        rev_base_string[i]='C';
                    }
                }
                else if(rev_base_string[i]=='x'||rev_base_string[i]=='X')
                {
                    if(rev_base_string[i]=='x')
                    {
                        rev_base_string[i]='d';
                    }
                    else
                    {
                        rev_base_string[i]='D';
                    }
                }
                else if(rev_base_string[i]=='y'||rev_base_string[i]=='Y')
                {
                    if(rev_base_string[i]=='y')
                    {
                        rev_base_string[i]='e';
                    }
                    else
                    {
                        rev_base_string[i]='E';
                    }
                }
                else if(rev_base_string[i]=='z'||rev_base_string[i]=='Z')
                {
                    if(rev_base_string[i]=='z')
                    {
                        rev_base_string[i]='f';
                    }
                    else
                    {
                        rev_base_string[i]='F';
                    }
                }
                else if(rev_base_string[i]=='3')
                {
                    rev_base_string[i]='0';
                }
                else if(rev_base_string[i]=='4')
                {
                    rev_base_string[i]='1';
                }
                else if(rev_base_string[i]=='5')
                {
                    rev_base_string[i]='2';
                }
                else if(rev_base_string[i]=='6')
                {
                    rev_base_string[i]='3';
                }
                else if(rev_base_string[i]=='7')
                {
                    rev_base_string[i]='4';
                }
                else if(rev_base_string[i]=='8')
                {
                    rev_base_string[i]='5';
                }
                else if(rev_base_string[i]=='9')
                {
                    rev_base_string[i]='6';
                }
                else
                {
                    rev_base_string[i]=rev_base_string[i]+7;
                }
            }


        }
        else
        {
            for(int i=0;i<MAX;i++)
            {

                sprintf(str, "%d", temp->transactions[i]);
                strcat(base_string, str);
            }
            strcat(base_string,temp->prev_hash);
            //strcat(base_string,"kshitiz151");
            for(int i=(strlen(base_string)-1);i>=0;i--)
            {
                rev_base_string[j]=base_string[i];
                j++;
            }
            for(int i=0;i<strlen(base_string);i++)
            {
                if(rev_base_string[i]=='t'||rev_base_string[i]=='T')
                {
                    if(rev_base_string[i]=='t')
                    {
                        rev_base_string[i]='a';
                    }
                    else
                    {
                        rev_base_string[i]='A';
                    }
                }
                else if(rev_base_string[i]=='u'||rev_base_string[i]=='U')
                {
                    if(rev_base_string[i]=='u')
                    {
                        rev_base_string[i]='b';
                    }
                    else
                    {
                        rev_base_string[i]='B';
                    }
                }
                else if(rev_base_string[i]=='v'||rev_base_string[i]=='V')
                {
                    if(rev_base_string[i]=='v')
                    {
                        rev_base_string[i]='c';
                    }
                    else
                    {
                        rev_base_string[i]='C';
                    }
                }
                else if(rev_base_string[i]=='w'||rev_base_string[i]=='W')
                {
                    if(rev_base_string[i]=='w')
                    {
                        rev_base_string[i]='c';
                    }
                    else
                    {
                        rev_base_string[i]='C';
                    }
                }
                else if(rev_base_string[i]=='x'||rev_base_string[i]=='X')
                {
                    if(rev_base_string[i]=='x')
                    {
                        rev_base_string[i]='d';
                    }
                    else
                    {
                        rev_base_string[i]='D';
                    }
                }
                else if(rev_base_string[i]=='y'||rev_base_string[i]=='Y')
                {
                    if(rev_base_string[i]=='y')
                    {
                        rev_base_string[i]='e';
                    }
                    else
                    {
                        rev_base_string[i]='E';
                    }
                }
                else if(rev_base_string[i]=='z'||rev_base_string[i]=='Z')
                {
                    if(rev_base_string[i]=='z')
                    {
                        rev_base_string[i]='f';
                    }
                    else
                    {
                        rev_base_string[i]='F';
                    }
                }
                else if(rev_base_string[i]=='3')
                {
                    rev_base_string[i]='0';
                }
                else if(rev_base_string[i]=='4')
                {
                    rev_base_string[i]='1';
                }
                else if(rev_base_string[i]=='5')
                {
                    rev_base_string[i]='2';
                }
                else if(rev_base_string[i]=='6')
                {
                    rev_base_string[i]='3';
                }
                else if(rev_base_string[i]=='7')
                {
                    rev_base_string[i]='4';
                }
                else if(rev_base_string[i]=='8')
                {
                    rev_base_string[i]='5';
                }
                else if(rev_base_string[i]=='9')
                {
                    rev_base_string[i]='6';
                }
                else
                {
                    rev_base_string[i]=rev_base_string[i]+7;
                }
            }

        }
//----------------------------------------------------------------------------------------------------------
        //printf("\n\n%s\n%d\n\n",base_string,strlen(base_string));
        printf("\nHash For this BLOCK:  \n");
        for(int i=0;i<strlen(base_string);i++)
        {
            printf("%c",rev_base_string[i]);
            //count++;
        }
        //printf("\n%d\n",count);
        base_string[0] = '\0';
        printf("\n\nEnter only The FIRST 10 DIGITS");
        printf("\nEnter the Hash of a Block:\t" );
        scanf("%s",hash_val);
        strcpy(temp->hash,hash_val);
        strcpy(historyHash,hash_val);

        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }

                ptr->next =temp;
                //temp ->prev=ptr;
                temp->next = NULL;
        }
        printf("\nBlock Inserted\n");

    }
else
{
if(front== - 1)
front = 0;
printf("Insert the Book ID : ");
scanf("%d", &item);
rear = rear + 1;
book_id[rear] = item;
}
}
