
#include <stdio.h>
#include <string.h>
int medicines_count=0;
char medi[20];
struct med{
    char medname[20];
    float cost;
    int expire;
};
void addmedicines()
{
    struct med m;
    printf("enter medicine name");
    scanf("%s",m.medname);
    printf("enter the cost");
    scanf("%f",&m.cost);
    printf("enter the expire year");
    scanf("%d",&m.expire);
    printf("%s %f %d\n",m.medname,m.cost,m.expire);
    FILE *addmedicines;
    addmedicines=fopen("medicineslist.txt","a");
    if(addmedicines==NULL)
    {
        printf("medicines list cannot be opened");
    }
    else
    {
        fprintf(addmedicines,"%s %f %d\n",m.medname,m.cost,m.expire);
        medicines_count++;
    }
    fclose(addmedicines);
    printf("your medicine is added successfully");
    return;
}
void searchmedicines()
{
    char medname[15];
    float cost;
    int expire;
    char searchedmedi[10];
    char word[10];
    char search;
    int c=0;
    FILE* f;
    f=fopen("medicineslist.txt","r");
    if(f==NULL)
    {
        printf("file is not avaliable");
    }
    else
    {
        
        printf("enter the name of the medicine");
        scanf("%s",searchedmedi);
    do
    {
      search=fscanf(f,"%s%f%d",word,&cost,&expire);
       if(strcmp(word,searchedmedi)==0)
       {
           c++;
       }
    }
    while(search!=EOF);
    if(c==0)
    {
    printf("not found your medicine\n");
    }
    else
    {
       printf("found the medicine\n");
       printf("%s %d %f\n",searchedmedi,expire,cost);
    }
    }
} 
int main()
{
int input;  
printf("enter the action you want to perform\n");
printf("enter 1 to add new medicines\n");
printf("enter 2 to search for medicines\n");
scanf("%d",&input);
switch(input)
{
    case 1:addmedicines();
          break;
    case 2:
           searchmedicines();
          break;
    default:
         return 0;
         
          
          
}
}




