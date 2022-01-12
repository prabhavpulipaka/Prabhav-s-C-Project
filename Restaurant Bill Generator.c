#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct items{
    char item[20];
    float price;
    int qty;

};

struct orders{
    char customers[50];
    char date[50];
    int numofitems;
    struct items itm[50];

};


//functions to generate the bills
void generateBillHeader(char name[50],char date[30])
{
    printf("\n\n");
    printf("\t     RA34 RESTAURANT");
    printf("\nDATE:%s",date);
    printf("\nINVOICE TO: %s",name);
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("ITEMS\t\t");
    printf("QTY\t\t");
    printf("TOTAL\t\t");
    printf("\n---------------------------------------------------\n");
    printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price)
{
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty * price);
    printf("\n");
}


void generateBillFooter(float total){
    printf("\n");
    float amt;
    float change;
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;
    printf("---------------------------------------------------\n");
    printf("SUB TOTAL\t\t\t%.2f",total);
    printf("\nDISCOUNT @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t---------------");
    printf("\nNET TOTAL\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n--------------------------------------------------");
    printf("\nGRAND TOTAL\t\t\t%.2f",grandTotal);
    printf("\n------------------------------------------------\n");
            printf("Enter the amount given : \n");
            scanf("%f",&amt);
            change=amt-grandTotal;
            printf("Change : %.2f",change);
}
int main()
{
    int opt,n,i;
    float total;
    struct orders ord;
    //dashboard
    printf("\t RA34 RESTAURANT");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Exit");

    printf("\n\n Select the respected command:");
    scanf("%d",&opt);
    fgetc(stdin);

    switch(opt)
    {
        case 1:
        printf("\n Please enter the name of the customer :\t");
        fgets(ord.customers,50,stdin);
        ord.customers[strlen(ord.customers)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        ord.numofitems = n;

        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d :",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("\nPlease enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("\nPlease enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            
         

        }

        generateBillHeader(ord.customers,ord.date);
        for(int i=0;i<ord.numofitems;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }
            
        generateBillFooter(total);
        
         case 2:
         printf("\n\t\t See you soon :-) ");
         exit(0);
         break;
         default:
         printf("sorry invalid option");
         break;
    
         







    }










    printf("\n\n");

    return 0;
}
