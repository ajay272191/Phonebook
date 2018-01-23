#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 15
int add(void);
int search(void);
int print(int);
int namesearch(void);
int addressearch(void);
int phonenumbersearch(void);
int scan(void);
struct
{
     char fn[size],mn[size],ln[size];
     char housenumber[size],village[size];
     char email[size],ps[size],dist[size],post[size];;
     char pin[size];
     char mobile[size],fax[size],landline[size];
}data[100];
int count=0;
FILE *fptr;
int main()
{
     int ch;

     fptr=fopen("phnbook.bin","ab+");
     while(1)
     {
          printf("1.for add contact\n");
          printf("2.search contact\n");
          printf("3.for exit\n");
          scanf("%d",&ch);
          switch (ch)
          {
          case 1:
               add();
               break;
          case 2:
               search();
               break;
          case 3:
              exit(0);
          default:
               printf("enter right choice\n");
               break;

          }
     }
}
int add(void)
{
     int ch;
     while(1)
     {
          printf("1.for enter contact details for add contact\n");
          printf("2.for exit\n");
          scanf("%d",&ch);
          switch (ch)
          {
          case 1:
               printf("give the information asked below.......\n\n");
               printf("give first name\n");
               scanf(" %[^\n]s",data[count].fn);
               printf("middle name ");
               scanf(" %[^\n]s",data[count].mn);
               printf("last name\n ");
               scanf(" %[^\n]s",data[count].ln);
               printf("house number \n");
               scanf(" %[^\n]s",&data[count].housenumber);
               printf("village name \n");
               scanf(" %[^\n]s",&data[count].village);
               printf("post office \n");
               scanf(" %[^\n]s",data[count].post);
               printf("district \n");
               scanf(" %[^\n]",data[count].dist);
               printf("police station\n ");
               scanf(" %[^\n]s",data[count].ps);
               printf("email \n");
               scanf(" %[^\n]s",data[count].email);
               printf("pin number \n");
               scanf(" %[^\n]s",&data[count].pin);
               printf("mobile number\n");
               scanf(" %[^\n]s",&data[count].mobile);
               printf("fax number\n");
               scanf(" %[^\n]s",&data[count].fax);
               printf("land line number\n");
               scanf(" %[^\n]s",&data[count].landline);
               fwrite(&data[count],sizeof(data[count]),1,fptr);
               count=count+1;
          break;
          case 2:
               return 0;
          default:
               printf("enter right choice\n");
               break;
          }
     }
}
int search(void)
{
   int ch;
   scan();
   while(1)
   {

     printf("using which details would you like to search contact details\n");
     printf("1.for name\n 2.for address 3.for phone number\n 4 for stop searching\n");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:
          namesearch();
          break;
     case 2:
          addressearch();
          break;
     case 3:
          phonenumbersearch();
          break;
     case 4:
            return 0;
          break;
     default :
        printf("enter right choice");
     }

   }
}
int namesearch(void)
{
     int ch,i=0;
     char detail[15];
     char search;
     while(1)
     {
          printf("1.for search by first name\n");
          printf("2.for search by middle name\n");
          printf("3.for search by last name\n");
          printf("4.for exit");
          scanf("%d",&ch);
          switch(ch)
          {
          case 1:
               printf("give the first name\n");
               scanf(" %[^\n]s",detail);

                    if((strcmp(detail,data[i].fn))==0)
                         {print(i);
                         i++;
                         }
                    else if(i==count)
                    {
                         i++;
                    }
               break;
          case 2:
               printf("give the middle name\n");
               scanf(" %[^\n]",detail);
               if((strcmp(detail,data[i].mn))==0)
                         {print(i);
                         i++;
                         }
                    else if(i==count)
                    {
                         i++;
                    }
               break;
          case 3:
               printf("give the last name\n");
               scanf(" %[^\n]",detail);
               for(i=0;i<count;i++)
               {
                    if((strcmp(detail,data[i].ln))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
         case 4:
            return;
            break;
          default:
               printf("enter right choice\n");
               break;
          }
     }

}
int addressearch(void)
{
    int ch,i;
     char detail[15];
     char search;
     while(1)
     {
          printf("1.for search by house number \n");
          printf("2.for search by village\n");
          printf("3.for search by post office\n");
          printf("4.for search by district\n");
          printf("5.for search by police station\n");
          printf("6.for search by email\n");
          printf("7.for search by pin number\n");
          printf("8.for exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
          case 1:
               printf("give the house number");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].housenumber))==0)
                         print(i);
                    else if(i==count)
                    {
                        printf("no such contact is there which you want to search\n");
                        return 0;
                    }

               }
               break;
          case 2:
               printf("give the village name\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].village))==0)
                         print(i);
                         else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
          case 3:
               printf("give the post office name\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].post))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
          case 4:
               printf("give the district name");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].dist))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
        case 5:
               printf("give the police station name\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].ps))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
        case 6:
               printf("give the email\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].email))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
         case 7:
               printf("give the pin number\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].pin))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                         return 0;
                    }
               }
               break;
         case 8:
               return 0;
               break;
          default:
               printf("enter right choice\n");
               break;
          }
     }
}
int phonenumbersearch(void)
{
     int ch,i;
     char detail[size];
     while(1)
     {
          printf("1.for search by mobile number\n");
          printf("2.for search by fax number\n");
          printf("3.for search by land number\n");
          printf("4.for exit\n");
          scanf("%d",&ch);
          switch(1)
          {
          case 1:
               printf("give the mobile number\n");
               scanf(" %[^\n]s",detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].mobile))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                    }

               }
               break;
          case 2:
               printf("give the fax number\n");
               scanf(" %[^\n]s",&detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].fax))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                    }

               }
               break;
          case 3:
               printf("give the landline number\n");
               scanf(" %[^\n]s",&detail);
               for(i=0;i<=count;i++)
               {
                    if((strcmp(detail,data[i].landline))==0)
                         print(i);
                    else if(i==count)
                    {
                         printf("no such contact is there which you want to search\n");
                    }

               }
               break;
            case 4:
                return 0;
                break;
          default:
               printf("enter right choice\n");
               break;
          }
     }

}

int print(int x)
{
     printf("contact details related to your search given below.......\n\n");
               printf(" name:: %s ",data[x].fn);
               printf(" %s ",data[x].mn);
               printf(" %s \n",data[x].ln);
               printf("house number ::");
               printf(" %s\n",&data[x].housenumber);
               printf("village name:: ");
               printf(" %s\n",&data[x].village);
               printf("post office:: ");
               printf(" %s\n",data[x].post);
               printf("district:: ");
               printf(" %s\n",data[x].dist);
               printf("police station ::");
               printf(" %s\n",data[x].ps);
               printf("email ::");
               printf(" %s\n",data[x].email);
               printf("pin number ::");
               printf("%s\n",&data[x].pin);
               printf("mobile number::");
               printf("%s\n",&data[x].mobile);
               printf("fax number::");
               printf("%s\n",&data[x].fax);
               printf("land line number::");
               printf("%s\n\n",&data[x].landline);
}
int scan(void)
{
     FILE *fptr1;
     int i=0;
     fptr1=fopen("phnbook.txt","r");
     while(fread(&data[i],sizeof(data[i]),1,fptr1)==1)
     {
          i++;
     }
}

