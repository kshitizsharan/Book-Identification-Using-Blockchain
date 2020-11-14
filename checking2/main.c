#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#define MAX 10


void bufferread();
void bufferwrite();
void insert();
void search();
void read(int);
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
        struct block *prev;
};
struct block *head=NULL;
char historyHash[10];
int count=0;
int buffer[100];
int book_id[MAX];
int rear = - 1;
int front = - 1;

int main()
{
        struct block* node;
        int block_count;
        int stamp=-1;
        FILE *fileName/* ,*fp1 */;
        fileName = fopen("blockchain.txt","a+");
        //fp1 = fopen("History.txt","w");
        int choice,number_blocks;
        printf("\n\n   READ IF ALREADY BLOCKS ARE CREATED\n\n\n");
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.ADD BOOK ID    \n");
                printf("\n 2.DISPLAY    \n");
                printf("\n 3.VERIFY    \n");
                //printf("\n 4.INSERT       \n");
                printf("\n 4.READ       \n");
                printf("\n 5.SEARCH       \n");
                printf("\n 6.EXIT       \n");
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
                                        stamp++;
                                        if(stamp==1)
                                        {
                                            printf("\n\nCANNOT RUN MORE THAN ONCE\n\n");
                                            break;
                                        }
                                        bufferread();
                                        fseek(fileName, 0, SEEK_END); // goto end of file
                                        if(ftell(fileName) == 0)
                                        {
                                            printf("\nFILE IS EMPTY\n");
                                        }
                                        else
                                        {
                                            printf("\nEnter Number of Blocks Already Inserted\n");
                                            scanf("%d",&number_blocks);
                                            read(number_blocks);
                                        }
                                        fseek(fileName, 0, SEEK_SET);
                                        break;

                        case 5:         search();
                                        break;
                        case 6:
                                        bufferwrite();
                                        insert();
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
    int check=1;
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
                    check=strcmp(ptr->hash,ptr->next->prev_hash);
                    if(check==0)
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
                printf("\nBlockChain is empty:\n");
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
int item,a,m;
struct block *temp,*ptr;
char hash_val[10];
char prev_hash_val[10];
FILE *fp1;
fp1 = fopen("History.txt","w");


//for(int i=0;i<count;i++)
//    printf("%d\n",buffer[i]);


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
        if(temp->block_number<1)
        {
            printf("INVALID BLOCK NUMBER");
            exit(0);
        }
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
            temp->transactions[i]=book_id[front];
            buffer[count]=book_id[front];
            book_id[front]=0;
            front = front + 1;
            count++;
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
        //fprintf(fp1,"%s",historyHash);

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
                temp ->prev=ptr;
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
void search()
{   int a;
    struct block* current;// Initialize current
    //int hash[10];
    char hash_val[10];
    int block_number;
    current = head;
    printf("\nEnter The Block Number: \n");
    scanf("%d",&block_number);
    printf("\nEnter The Hash: \n");
    scanf("%s",hash_val);
    //strcpy(hash,hash_val);
    //printf("\n%s\n",hash_val);

    //printf("\n%d\n",a);
    while(current != NULL)
    {
        printf("\n%s\n",hash_val);
        printf("\n%s\n",current->hash);
        a = strcmp(hash_val,current->hash);
        printf("\n\n%d\n\n",a);
        if (current->block_number == block_number /*&& a==0*/)
           {
                printf("\n\nBLOCK FOUND\n\n");
                for(int i=0;i<MAX;i++)
                    printf("Book ID %d\n",current->transactions[i]);
           }
        //printf("\n\nflag0\n\n");
        current = current->next;
        //printf("\n\nflag1\n\n");
    }

}
void read(int number_of_blocks)
{   struct block *temp,*ptr;
    char hash[10],prev_hash[10];
    //int block_number;
	FILE *py/* ,*fp1 */;
	//fp1=fopen("History.txt","r");
	py=fopen("blockchain.txt","r");
	if(py==NULL)
    {
        printf("\nNO SUCH FILE\n");
    }
    //fscanf(fp1,"%s",&historyHash);
	for(int i=0;i<number_of_blocks;i++)
	{
    temp=(struct block*)malloc(sizeof(struct block));
	fscanf(py,"%d\n",&temp->block_number);
	fscanf(py,"%s\n",&temp->hash);
	fscanf(py,"%s\n",&temp->prev_hash);
	for(int j=0;j<MAX;j++)
    {
        fscanf(py,"%d\n",&temp->transactions[j]);
    }
    temp->next=NULL;
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
                temp->next = NULL;
        }
	}
	//fclose(py);
}
void insert()
{
    int block_count;
    struct block *node;
    FILE *fileName/* ,*fp1 */;
    fileName = fopen("blockchain.txt","w");
    node = head;
    printf("Enter the number of blocks you entered : ");
    scanf("%d",&block_count);

    for(int i=0 ;i < block_count; i++)
    {
        fprintf(fileName,"%d\n",node->block_number);
        fprintf(fileName,"%s\n",node->hash);
        //strcpy(historyHash,node->hash);
        //fprintf(fp1,"%s",historyHash);
        fprintf(fileName,"%s\n",node->prev_hash);
        for(int j=0;j<MAX;j++)
        {
            fprintf(fileName,"%d\n",node->transactions[j]);
        }
        printf("\n");
        printf("---------------------------------------------------------\n");
        node = node->next;
    }
    printf("done\n");
}
void bufferwrite()
{
    FILE *fp,*fp3,*fp2;
    fp=fopen("buffer.txt","w+");
    //printf("\n%s\n",historyHash);
    fprintf(fp,"%s\n",historyHash);

    fp3=fopen("buffer2.txt","w+");
    fprintf(fp3,"%d\n",count);

    fp2=fopen("buffer1.txt","w");
    for(int i=0;i<count;i++)
    fprintf(fp2,"%d\n",buffer[i]);

}

void bufferread()
{
    FILE *fp,*fp2,*fp3;
    char history[10];
    int buffer1[count];
    int buffer2;
    fp=fopen("buffer.txt","r");
    //printf("\n%s\n",historyHash);
    fscanf(fp,"%s\n",&historyHash);
    //strcpy(historyHash,history);

    fp3=fopen("buffer2.txt","r");
    fscanf(fp3,"%d\n",&count);
    //count=buffer2;

    fp2=fopen("buffer1.txt","r");
    for(int i=0;i<count;i++)
    {
        fscanf(fp2,"%d\n",&buffer[i]);
        //buffer[i]=buffer1[i];
    }

}
