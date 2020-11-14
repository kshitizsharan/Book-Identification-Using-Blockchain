#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#define MAX 10


void verify();
void display();
void deleted();
void addTransactions();

struct block
{
        int block_number;
        char hash[10];
        int transactions[10];
        char prev_hash[10];
        struct block *next;
        struct block *prev;
};
struct block *head=NULL;

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
                        for(int i=0;i<10;i++)
                        {
                            printf("Book ID :  %d \n",ptr->transactions[i]);
                        }
                        ptr=ptr->next ;
                }
        }
}
void addTransactions()
{
//int item;
struct block *temp,*ptr;
//char hash_val[10];
//char prev_hash_val[10];
if(rear == MAX - 1)
    {
        printf("Completed 10 Transactions (Book ID) For Block Creation \n");
        temp=(struct block *)malloc(sizeof(struct block));
        printf("flag1");
        if(temp==NULL)
        {
            printf("\nOut of Memory:\n");
            return;
        }

        temp->next=NULL;

        if(head==NULL)
        {
                head=temp;
        }
        else
        {

                ptr=head;
                while(ptr->next!=NULL)
                {       printf("flag2");
                        ptr=ptr->next ;
                }

                ptr->next=temp;
                temp->prev=ptr;


        }
        printf("\nEnter the Block Number:\t" );
        scanf("%d",&temp->block_number);

        for(int i=0;i<MAX;i++)
        {
            temp->transactions[i]=book_id[front];;
            //book_id[front]=0;
            front = front + 1;
        }

//--------------------------------------------------------------------------------------------------------
        // Making it again -1 so that next transactions could be added
        rear = - 1;
        front = - 1;
//--------------------------------------------------------------------------------------------------------
        //  temp->next =NULL;

 /*       if(head==NULL)
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
                temp->prev=ptr;
                ptr->next=temp;
                temp->next = NULL;
                printf("flag1");

        }
*/


//---------------------------------------------------------------------------------------------------------
        int j=0;
        char base_string[500];
        char rev_base_string[500];
        char str[20];
        base_string[0]='\0';
        if(temp->block_number>=1)
        {
            if(temp->block_number==1)
                strcpy(temp->prev_hash,"00");
            else
               strcpy(temp->prev_hash,temp->prev->hash);
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
            rev_base_string[strlen(base_string)]='\0';
            //printf("\n%s\n",rev_base_string);
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
            rev_base_string[strlen(base_string)]='\0';
            //printf("\n%s\n",rev_base_string);
        }
     /*   else
        {
            base_string[0]='\0';
            //printf("hello");
            //printf("\n%s\n",temp->prev->hash);
            strcpy(temp->prev_hash,temp->prev->hash);
            for(int i=0;i<MAX;i++)
            {

                sprintf(str, "%d", temp->transactions[i]);
                strcat(base_string, str);
            }
            //printf("\n%s\n",base_string);
            strcat(base_string,temp->prev->hash);
            //strcat(base_string,"kshitiz151");
            printf("\n%s\n",base_string);
            for(int i=(strlen(base_string)-1);i>=0;i--)
            {
                rev_base_string[j]=base_string[i];
                j++;
            }

            rev_base_string[strlen(base_string)]='\0';
            //printf("\n%s\n",rev_base_string);

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
            rev_base_string[strlen(base_string)]='\0';
            //printf("\n%s\n",rev_base_string);

        }

*/
        strcpy(temp->hash,rev_base_string);
        //printf("\nEnter the Hash of a Block:\t" );
        //scanf("%s",hash_val);
        //strcpy(temp->hash,hash_val);
        //printf("\nEnter the previous Hash of a Block:\t" );
        //scanf("%s",prev_hash_val);
        //strcpy(temp->prev_hash,prev_hash_val);



//----------------------------------------------------------------------------------------------------------
        //printf("\n\n%s\n%d\n\n",base_string,strlen(base_string));
        //for(int i=0;i<strlen(base_string);i++)
        //{
            //printf("%c",rev_base_string[i]);
            //count++;
        //}
        //printf("\n%d\n",count);
        base_string[0] = '\0';
        printf("\nBlock Inserted\n");

    }
else
{
if(front== - 1)
front = 0;
printf("Insert the Book ID : ");
rear = rear + 1;
fflush(stdin);
scanf("%d", &book_id[rear]);
//rear = rear + 1;
//book_id[rear] = item;
}
}
void deleted()
{
if(front == - 1 || front > rear)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("Element deleted from queue is : %d\n", book_id[front]);
book_id[front]=0;
front = front + 1;
}
}
