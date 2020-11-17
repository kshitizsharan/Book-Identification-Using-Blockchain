#include <dos.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#define MAX 10
#define MAX_TRANS 10
#define NUMBER_OF_BLOCKS 1000
#define NUMBER_OF_TRANSACTIONS (NUMBER_OF_BLOCKS*10)

void block_init();
void bufferread1();
void bufferread();
void bufferwrite();
int searchbuffer(int);
int searchbuffer(int);
void insert();
void search();
void read(int);
void verify();
void display();
void addTransactions();

struct block
{
        int block_number;
        char hash[MAX];
        int transactions[MAX_TRANS];
        char prev_hash[MAX];
        struct block *next;
        //struct date *dt;
};
struct block *head=NULL;
char historyHash[MAX];
int count=0,count1=0,track=0,rear = - 1,front = - 1,book_id[MAX];
int block_number_init[NUMBER_OF_BLOCKS],buffer[NUMBER_OF_TRANSACTIONS],bufferblock[NUMBER_OF_BLOCKS];

int main()
{/**<  */
        //struct block* node;
        //int block_count;
        int stamp=-1;
        FILE *fileName/* ,*fp1 */;
        fileName = fopen("blockchain.txt","a+");
        bufferread1();
        block_init();
        //fp1 = fopen("History.txt","w");
        int choice /*number_blocks*/;
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
                                            //printf("\nENTER TOTAL NUMBER OF BLOCKS IN BLOCKCHAIN\n");
                                            //scanf("%d",&number_blocks);
                                            read(count1);
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
                                        printf("\n INVALID INPUT:\n");
                                        break;
                }
        }


        return 0;
}
void verify()
{
    struct block *ptr;
    int check=1, j=0;;
    if(head==NULL)
        {
                printf("\nLIST IS EMPTY:\n");
                return;
        }
    else
        {
                ptr=head;
                printf("\nVERIFTING THE BLOCKCHAIN...\n");
                while(ptr!=NULL)
                {
                    for(int i=0;i<10;i++)
                    {
                        if(ptr->hash[i]==ptr->next->prev_hash[i])
                            check=0;
                    }
                    //check=strcmp(ptr->hash,ptr->next->prev_hash);
                    if(check==0)
                    {
                        printf("\nVERIFIED BLOCK %d\n",j+2);
                        j++;
                    }
                    else
                    {
                        printf("\nINCORRECT BLOCKCHAIN\n");
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
                printf("\n\nBLOCKCHAIN IS EMPTY:\n\n");
                return;
        }
        else
        {
                ptr=head;
                printf("\n|BLOCKCHAIN:\n\n");
                while(ptr!=NULL)
                {
                        printf("BLOCK No. :  %d\nHash :  %s\nPrevious Hash :  %s\n",ptr->block_number,ptr->hash,ptr->prev_hash );
                       // printf("%d/%d/%d", ptr->dt.da_day, ptr->dt.da_mon, ptr->dt.da_year);
                        for(int i=0;i<MAX_TRANS;i++)
                        {
                            printf("Book ID :  %d\n",ptr->transactions[i]);
                        }
                        ptr=ptr->next ;
                }
        }
}
void addTransactions()
{
int item;
//int key,key1;
//int a;
struct block *temp,*ptr;
//char hash_val[10];
//char prev_hash_val[10];
//FILE *fp1;
//fp1 = fopen("History.txt","w");


//for(int i=0;i<count;i++)
//    printf("%d\n",buffer[i]);
if(rear == MAX_TRANS - 1)
    {
        printf("Completed 10 Transactions (Book ID) For Block Creation \n");
        temp=(struct block *)malloc(sizeof(struct block));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }

        //printf("\nEnter the Block Number:\t" );
        //scanf("%d",&temp->block_number );
        //printf("%d\n",track);
        temp->block_number=block_number_init[track];
        track++;
        while(temp->block_number<1)
        {
            printf("\nINVALID BLOCK NUMBER");
            printf("\n\nTRY AGAIN:\n\n" );
            printf("\nEnter the Block Number:\t" );
            scanf("%d",&temp->block_number);
            if(temp->block_number<1)
                continue;
        }

        for(int i=0;i<(count1);i++)
        {
            if(bufferblock[i]==temp->block_number)
            {
                printf("\n\nBLOCK EXISTS\n\nTRY AGAIN\n\n");
                printf("\nEnter the Block Number:\t" );
                scanf("%d",&temp->block_number);
                i=-1;
            }
        }

        bufferblock[count1]=temp->block_number;
        count1++;


        if(temp->block_number==1)
        {
            //printf("\nPrevious Hash: '000'\n");
            for(int i=0;i<3;i++)
            {
                temp->prev_hash[i]='0';
            }
            temp->prev_hash[3]='\0';
            //strncpy(temp->prev_hash,'000',3);
            //printf("%s\n",temp->prev_hash);
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                temp->prev_hash[i]=historyHash[i];
            }
            temp->prev_hash[10]='\0';
            //printf("\nPrevious Hash:  '%s' ",historyHash);
            //strncpy(temp->prev_hash,historyHash,10);
            //printf("%s\n",temp->prev_hash);
        }
        //printf("\n\nENTER MANUALLY THE CHARACTERS IN BRACKETS ABOVE\n\n");
        //printf("\nEnter the previous Hash of a Block:\t" );
        //scanf("%s",prev_hash_val);

        //strcpy(temp->prev_hash,prev_hash_val);

        getdate(&temp->dt);

        for(int i=0;i<MAX_TRANS;i++)
        {
            temp->transactions[i]=book_id[front];
            //buffer[count]=book_id[front];
            //count++;
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
        int j=0;
//        int count=0;
        char base_string[500];
        //char yalayolo[500];
        char rev_base_string[500];
        char str[20];
        base_string[0]='\0';
        if(temp->block_number==1)
        {
            //temp->prev_hash=="000";
            for(int i=0;i<MAX_TRANS;i++)
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
            for(int i=0;i<MAX_TRANS;i++)
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
        char rev_base[11];
        //printf("\n\n%s\n%d\n\n",base_string,strlen(base_string));
        printf("\nHash For this BLOCK:  \n");
        printf("'");
        for(int i=0;i<10;i++)
        {
            rev_base[i]=rev_base_string[i];
            //printf("%s",rev_base_string);
            //count++;
        }
        rev_base[10]='\0';
        printf("%s",rev_base);
        printf("'");
        //printf("\n%d\n",count);
        base_string[0] = '\0';
        //printf("\n\nEnter only The FIRST 10 DIGITS PRESENT IN BRACKETS ABOVE");
        //printf("\nEnter the Hash of a Block:\t" );
        //scanf("%s",hash_val);
        for(int i=0;i<10;i++)
            {
                temp->hash[i]=rev_base[i];
            }
        temp->hash[10]='\0';
        for(int i=0;i<10;i++)
            {
                historyHash[i]=rev_base[i];
            }
        historyHash[10]='\0';
        //strncpy(temp->hash,rev_base,10);
        //strncpy(historyHash,rev_base,10);
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
                temp->next = NULL;
        }
        printf("\n\nBLOCK INSERTED\n\n");

    }
else
{
if(front== - 1)
front = 0;
printf("INSERT BOOK ID : ");
scanf("%d", &item);

for(int i=0;i<count;i++)
{
    if(buffer[i]==item)
    {
        printf("\n\nBOOK ID EXISTS\n\nTRY AGAIN\n\n");
        printf("INSERT BOOK ID : ");
        scanf("%d", &item);
        i=-1;
    }
}
buffer[count]=item;
count++;
rear = rear + 1;
book_id[rear] = item;

}
}
void search()
{
    struct block *current;
 //   char hash_val[10];
    int block_number;
    current = head;
    printf("\nENTER THE BLOCK NUMBER TO SEARCH ALL DETAILS: \n");
    scanf("%d",&block_number);
    while(current != NULL)
    {

        if (current->block_number == block_number)
           {
                printf("\n\nBLOCK FOUND\n");
                printf("\nHASH: %s\n\n",current->hash);

                for(int i=0;i<MAX_TRANS;i++)
                    printf("Book ID %d\n",current->transactions[i]);
           }

        current = current->next;

    }

}
void read(int number_of_blocks)
{   struct block *temp,*ptr;
//    char hash[10];
 //   char prev_hash[10];
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
	for(int j=0;j<MAX_TRANS;j++)
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
	printf("\n\nDONE\n\n");
}
void insert()
{
//    int block_count;
    struct block *node;
    FILE *fileName/* ,*fp1 */;
    fileName = fopen("blockchain.txt","w");
    node = head;
    //printf("\nENTER TOTAL NUMBER OF BLOCKS IN BLOCKCHAIN : \n");
    //scanf("%d",&block_count);

    for(int i=0 ;i < count1; i++)
    {
        fprintf(fileName,"%d\n",node->block_number);
        fprintf(fileName,"%s\n",node->hash);
        //strcpy(historyHash,node->hash);
        //fprintf(fp1,"%s",historyHash);
        fprintf(fileName,"%s\n",node->prev_hash);
        for(int j=0;j<MAX_TRANS;j++)
        {
            fprintf(fileName,"%d\n",node->transactions[j]);
        }
        printf("\n");
        printf("---------------------------------------------------------\n");
        node = node->next;
    }
    //printf("done\n");
}
void bufferwrite()
{
    FILE *fp,*fp3,*fp2;
    FILE *fp4,*fp5,*fp6;
    fp=fopen("buffer.txt","w+");
    //printf("\n%s\n",historyHash);
    fprintf(fp,"%s\n",historyHash);

    fp3=fopen("buffer2.txt","w+");
    fprintf(fp3,"%d\n",count);

    fp2=fopen("buffer1.txt","w");
    for(int i=0;i<count;i++)
    fprintf(fp2,"%d\n",buffer[i]);

    fp4=fopen("bufferblock.txt","w");
    fprintf(fp4,"%d\n",count1);

    fp5=fopen("bufferblockdata.txt","w");
    for(int i=0;i<count1;i++)
    fprintf(fp5,"%d\n",bufferblock[i]);

    fp6=fopen("track1.txt","w");
    fprintf(fp6,"%d\n",track);

//    for(int i=0;i<count1;i++)
//    printf("%d\n",bufferblock[i]);
}
void bufferread1()
{
    FILE *fp11,*fp12;
    fp11=fopen("bufferblock.txt","r");
    fscanf(fp11,"%d\n",&count1);

    fp12=fopen("track1.txt","r");
    fscanf(fp12,"%d\n",&track);
    //printf("\nFLAG\n");
}
void bufferread()
{
    FILE *fp,*fp2,*fp3;
    FILE *fp5;
 //   char history[10];
 //   int buffer1[count];
 //   int buffer2;
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

    fp5=fopen("bufferblockdata.txt","r");
    for(int i=0;i<count1;i++)
    fscanf(fp5,"%d\n",&bufferblock[i]);

}
void block_init()
{
    for(int i=0;i<NUMBER_OF_BLOCKS;i++)
    {
        block_number_init[i]=(i+1);
    }
}

int searchbufferblock(int key)
{
    int flag=-1;

  for(int i=0;i<count1;i++)
  {printf("%d\n",bufferblock[i]);
      if(bufferblock[i]==key)
        flag=1;
    else
        flag=0;
  }
  if(flag==1)
    return 1;
  else
    return 0;
}
int searchbuffer(int key)
{
    int flag=-1;
    for(int i=0;i<count;i++)
  {
      if(buffer[i]==key)
        flag=1;
      else
        flag=0;
  }
    if(flag==1)
        return 1;
    else
        return 0;
}


