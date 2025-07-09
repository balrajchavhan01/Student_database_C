#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct st{
    int roll_no;
    char name[50];
    float percentage;
    struct st *next;
}SLL;

void add_new_record(SLL **);
void delete_a_record(SLL **);
int del_roll(SLL **);
int del_name(SLL **);
void show_list(SLL *);
void std_mod(SLL **);
void search_roll(SLL *);
void search_name(SLL *);
void search_percentage(SLL *);
void save(SLL *);
void save_exit(SLL *);
void sort_list(SLL *);
//void sort_roll(SLL *,int);
void delete_all(SLL **);
void reverse_link(SLL **);

static int k=0;

int main() {
    char ch;
    SLL *headptr=0;
    int i,j;

    while(1){
   // printf("Enter the option:\n");

    printf(" _________________________________\n");
    printf("| *****STUDENT RECORD MENU******  |\n");
    printf("| _______________________________ |\n");
    printf("| A/a) Add new record             |\n");
    printf("| D/d) Delete a record            |\n");
    printf("| S/s) Show the list              |\n");
    printf("| M/m) Modify a record            |\n");
    printf("| V/v) Save                       |\n");
    printf("| E/e) Exit                       |\n");
    printf("| T/t) Sort the list              |\n");
    printf("| L/l) Delete all the records     |\n");
    printf("| R/r) Reverse the list           |\n");
    printf("|                                 |\n");
    printf("| Enter your Choice:              |\n");
    printf("|_________________________________|\n");
    scanf(" %c", &ch);

    switch (ch)
    {   
    case 'A':
    case 'a':
        add_new_record(&headptr);
        break;

    case 'D':
    case 'd':
       delete_a_record(&headptr);
       break;
       
    case 'S':
    case 's':show_list(headptr);break;

    case 'M':
    case 'm':std_mod(&headptr);break;

    case 'E':
    case 'e':
        printf("Existing from the program:\n");
        exit(0);
            break;
    
    case 'V':
    case 'v':save(headptr);break;
    
    case 'T':
    case 't':sort_list(headptr);break;

    case 'L':
    case 'l':
            delete_all(&headptr);break;

    case 'R':
    case 'r':reverse_link(&headptr);break;
    
    
    default:printf("Wrong option chosen:");
            break;
    
}
}
return 0;
}

void add_new_record(SLL **ptr){
    SLL *new;
    new=malloc(sizeof(SLL));
    if(new==NULL){
        printf("Memory is not allocated:");
        return;
    }
    new->roll_no=++k;
    printf("Enter the Name of student:\n");
    scanf(" ");
    fgets(new->name,sizeof(new->name),stdin);
    new->name[strcspn(new->name,"\n")]=0;
    printf("Enter the percentage of student:\n");
    scanf("%f",&new->percentage);
    new->next=*ptr;
    *ptr=new;
    printf("Record added successfully for Roll No:%d\n",new->roll_no);
}

void delete_a_record(SLL **ptr){
    char ch;
    //char ch1[20];
    //int l;
    //SLL *del;
    while(1){
        if(*ptr==NULL){
            printf("No Record found.\n");
            return;
        }
        printf(" _______________________________\n");
        printf("| R/r) : Enter roll no to del: |\n");
        printf("| N/n) :Enter name to del:     |\n");
        printf("| E/e) :Exit :                 |\n");
        printf("|______________________________|\n");
        printf("Enter the Choice:\n");
        scanf(" %c",&ch);
        int c=0;
        switch (ch){
            case 'R':
            case 'r':c=del_roll(ptr);
            if(!c)
            printf("roll_no not found\n");
            break;
            
            
            case 'N':
            case 'n':c=del_name(ptr);
            if(!c)
            printf("Name is not found:\n");
            break;
            
            
            case 'E':
            case 'e':exit(0);break;

            default:printf("Enter wrong option:");break;
        }
    }
}
int del_roll(SLL **ptr){
int n;
            printf("Enter the Roll_no:");
            scanf("%d",&n);
            SLL *del=*ptr,*prev;//start from first node address
            while(del){
                if(del->roll_no==n){
                    if(del==*ptr){
                    *ptr=del->next;
                    }
                    else{
                    prev->next=del->next;
                    }
                    free(del);
                    printf("record with Roll NO %d deleted.\n",n);
                    return 1;
                    }
                    prev=del;
                    del=del->next;
                    //return;
                
            }
            return 0;
}


int del_name(SLL **ptr){
    char ch1[50];
            printf("Enter the Name to delete:");
            scanf(" ");
            fgets(ch1,sizeof(ch1),stdin);
            ch1[strcspn(ch1,"\n")]=0;
            
            SLL *del=*ptr,*prev;
            while(del){
                if(strcmp(del->name,ch1)==0){
                    if(del==*ptr){
                        *ptr=del->next;
                    }
                    else{
                        prev->next=del->next;
                    }
                    free(del);
                    printf("Record with name '%s' deleted.\n",ch1);
                    return 1;
                }
                prev=del;
                del=del->next;
                //return;
            }
            return 0;
}


void show_list(SLL *ptr){
    //SLL *new;
    if(ptr==0){
        printf("No record found\n");
        return;
    }
    printf("\033[34m****************************\033[0m\n");

    while(ptr){
        printf("%d %s %.2f\n",ptr->roll_no,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("\033[34m****************************\033[0m\n");

}

void std_mod(SLL **ptr){
    char ch2[50];
    int i,j;
    char ch;

    printf(" __________________________\n");
    printf("| R/r: to search a rollno: |\n");
    printf("| N/n: to search a name    |\n");
    printf("| P/p: percetage based     |\n");
    printf("|__________________________|\n");
    printf("Enter the Choice:\n");
    scanf(" %c",&ch);

    switch(ch){
        case 'R':
        case 'r':search_roll(*ptr); break;
        
        case 'n':
        case 'N':search_name(*ptr);break;
        
        case 'P':
        case 'p':search_percentage(*ptr);break;


        default: printf("Wrong option is choosen\n");break;
    }
}

void search_roll(SLL *ptr){
    if(ptr==0){
        printf("Record not found\n");
        return;
    }
    printf("Enter the roll_no:\n");
    int n;
    scanf("%d",&n);
    SLL *temp=ptr;

    while(temp){
        if(temp->roll_no==n){
            printf("%d %s %.2f\n",temp->roll_no,temp->name,temp->percentage);
            //printf("Enter the updated roll_no\n");
            //scanf("%d",&temp->roll_no);

            printf("Enter the updated name:\n");
            scanf(" ");
            fgets(temp->name,sizeof(temp->name),stdin);
            temp->name[strcspn(temp->name,"\n")]=0;

            // printf("Enter new percentage:");
            // scanf("%f",&temp->percentage);

            printf("record updated successfully\n");
            return;
        }
        temp=temp->next;
    }
    printf("Roll no %d not found.\n",n);
}

void search_name(SLL *ptr){
    if(ptr==0){
        printf("Record not found\n");
        return;
    }
    printf("Enter the Name:\n");
    char ch[50];
    scanf(" ");
    fgets(ch,sizeof(ch),stdin);
    ch[strcspn(ch,"\n")]=0;
    SLL *temp=ptr;

    while(temp){
        if(strcmp(temp->name,ch)==0){
            printf("%d %s %.2f\n",temp->roll_no,temp->name,temp->percentage);
            //printf("Enter the updated roll_no\n");
            //scanf("%d",&temp->roll_no);

            printf("Enter the updated name:\n");
            scanf(" ");
            fgets(temp->name,sizeof(temp->name),stdin);
            temp->name[strcspn(temp->name,"\n")]=0;

            // printf("Enter new percentage:");
            // scanf("%f",&temp->percentage);

            printf("record updated successfully\n");
            return;
        }
        temp=temp->next;
    }
    printf("name no %s not found.\n",ch);
}

void search_percentage(SLL *ptr){
    if(ptr==0){
        printf("Record not found\n");
        return;
    }
    printf("Enter the percentage:\n");
    int n;
    scanf("%d",&n);
    SLL *temp=ptr;

    while(temp){
        if(temp->percentage==n){
            printf("%d %s %.2f\n",temp->roll_no,temp->name,temp->percentage);
            //printf("Enter the updated roll_no\n");
            //scanf("%d",&temp->roll_no);

            // printf("Enter the updated name:\n");
            // scanf(" ");
            // fgets(temp->name,sizeof(temp->name),stdin);
            // temp->name[strcspn(temp->name,"\n")]=0;

            printf("Enter new percentage:");
            scanf("%f",&temp->percentage);

            printf("record updated successfully\n");
            return;
        }
        temp=temp->next;
    }
    printf("percentage %d not found.\n",n);
}


void save(SLL *ptr){
    if(ptr==0){
        printf("Not recoard found\n");
        return ;
    }
    char ch;
    printf(" ___________________________\n");
    printf("| S/s:save and exit         |\n");
    printf("| E/e:exit without saving   |\n");
    printf("|___________________________|\n");
    printf("Enter the Choice:\n");
    scanf(" %c",&ch);
    switch(ch){
        case 'S':
        case 's':save_exit(ptr);break;
        
        case 'E':
        case 'e':
        printf("Exit without saving\n");exit(0);break;
        
        default:printf("wrong option is choosen\n");break;
    }
}
void save_exit(SLL *ptr){
    printf("\033[34m****************************\033[0m\n");
    FILE *fp;
    fp=fopen("student.txt","w");
    
    if(fp==NULL){
        printf("File is not open:\n");
        return;
    }
    
    
    while(ptr){
        fprintf(fp, "%d\t%s\t%.2f\n",ptr->roll_no,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("\033[34m****************************\033[0m\n");
    fclose(fp);
}


void sort_list(SLL *ptr){
    if(ptr==0){
        printf("record not found:\n");
        return;
    }
    
    char ch;
    printf(" ______________________________________________\n");
    printf("| R/r: sort with roll_no                       |\n");
    printf("| N/n: sort with name                          |\n");
    printf("| I/i: sort with percentage (increasing order) |\n");
    printf("| P/p: sort with percentage (decreasing)       |\n");
    printf(" ______________________________________________\n");
    printf("Enter the Choice:\n");
    scanf(" %c",&ch);
    SLL *i,*j;
    struct st temp;
    
    switch(ch){
        case 'R':
        case 'r':
                for(i=ptr;i!=NULL;i=i->next){
                    for(j=i->next;j!=NULL;j=j->next){
                        if(i->roll_no > j->roll_no){
                            temp=*i;
                            *i=*j;
                            *j=temp;

                            SLL *tem=i->next;
                            i->next=j->next;
                            j->next=tem;
                        }
                    }
                }
        printf("Sorted by Roll number.\n");
        break;


        case 'P':
        case 'p':
        for(i=ptr;i!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(i->percentage >j->percentage){
                    temp=*i;
                    *i=*j;
                    *j=temp;

                    SLL *tmp=i->next;
                    i->next=j->next;
                    j->next=tmp;
                }
            }
        }
        printf("Sorted by percentage(decreasing).\n");break;

        case 'I':
        case 'i':
                 for(i=ptr;i!=NULL;i=i->next){
                    for(j=i->next;j!=NULL;j=j->next){
                        if(i->percentage < j->percentage){
                            temp=*i;
                            *i=*j;
                            *j=temp;

                            SLL *tem=i->next;
                            i->next=j->next;
                            j->next=tem;
                        }
                    }
                 }
                 printf("Sorted by percentage(increassing.\n");break;


        case 'N':
        case 'n':
                for(i=ptr;i!=NULL;i=i->next){
                    for(j=i->next;j!=NULL;j=j->next){
                        if(strcmp(i->name,j->name)>0){
                            temp=*i;
                            *i=*j;
                            *j=temp;

                            SLL *tmp=i->next;
                            i->next=j->next;
                            j->next=tmp;

                        }
                    }
                }
                printf("Sorted by name.\n");break;
        
        default: printf("wrong Choice:\n");break;
    }
}

void delete_all(SLL **ptr){
    if(*ptr==0){
        printf("No records found\n");
        return;
    }
    //int c=1;
    SLL *del=*ptr;
    while(del){
        *ptr=del->next;
       // printf("Node %d is deleted\n",c++);
       free(del);
       del=*ptr;
    }
    k=0;
    printf("all the records is Deleted Successfully\n");
}

void reverse_link(SLL **ptr){
    if(*ptr==0){
        printf("Record is not Found\n");
        return;
    }

    int c=0;
    SLL *temp=*ptr;
    while(temp){
        c++;
        temp=temp->next;
    }

    if(c>1){
        SLL **arr,*t=*ptr;
        arr=malloc(sizeof(SLL *)*c);
        int i=0;
        while(t){
            arr[i]=t;
            i++;
            t=t->next;
        }

        //change the link

        for(i=1;i<c;i++)
        arr[i]->next=arr[i-1];
        arr[0]->next=0;
        *ptr=arr[c-1];
    }

}
