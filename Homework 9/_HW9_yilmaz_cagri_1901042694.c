#include <stdio.h>

#include <string.h>
typedef struct{
    char name[50];
    int age;
    int Label;
}personal_information;
int findIdx(personal_information *list,int row,int size){
	return -1;
}
void copy(personal_information *originalList,personal_information *tempList){
    int i;
    for(i=0;i<50;i++){
       tempList[i].age=originalList[i].age;
        tempList[i].Label=originalList[i].Label;
        strcpy(tempList[i].name,originalList[i].name);
    }
}
void single_copy(personal_information *originalList,personal_information *tempList){
       originalList->age=tempList->age;
        originalList->Label=tempList->Label;
        strcpy(originalList->name,tempList->name);
		tempList->age = -1;
}
void print(int a0,int a1,int a2,int a3,int a4,personal_information *orginalList,int count){
	int l;
	int idx = 0;
	personal_information tempList[50];
	int temp = 0;
	int row = 0;
	while(a1!=0 || a2!=0||a0!=0 || a3!=0 || a4!=0){
		switch(row){
			case 0:
				if(temp >=5 || a0 ==0) {
					row++;
					temp = 0;
					break;
				}
				int tempIdx = 0;
				for(;tempIdx<count;tempIdx++){
					if(orginalList[tempIdx].Label == 0)
						break;
				}
				tempList[idx]=orginalList[tempIdx];

				idx++;
				orginalList[tempIdx].Label = -1;
				temp++;
				a0--;
				printf("0 ");
				break;
			case 1:
				if(temp >=3 || a1 ==0) {
					row++;
					temp = 0;
					break;
				}
				tempIdx = 0;
				for(;tempIdx<count;tempIdx++){
					if(orginalList[tempIdx].Label == 1)
						break;
				}
				tempList[idx]=orginalList[tempIdx];
				orginalList[tempIdx].Label = -1;
				idx++;
				temp++;
				a1--;
				printf("1 ");
				break;
			case 2:
				if(temp >=3 || a2 ==0) {
					row++;
					temp = 0;
					break;
				}
					tempIdx = 0;
				for(;tempIdx<count;tempIdx++){
					if(orginalList[tempIdx].Label == 2)
						break;
				}
			tempList[idx]=orginalList[tempIdx];
				idx++;
				orginalList[tempIdx].Label = -1;
				temp++;
				a2--;
				printf("2 ");
				break;
			case 3:
				if(temp >=2 || a3 ==0) {
					row++;
					temp = 0;
					break;
				}
					tempIdx = 0;
				for(;tempIdx<count;tempIdx++){
					if(orginalList[tempIdx].Label == 3)
						break;
				}
			tempList[idx]=orginalList[tempIdx];
				orginalList[tempIdx].Label = -1;
				idx++;
				temp++;
				a3--;
				printf("3 ");
				break;
			case 4:
				if(temp >=2 || a4 ==0) {
					row = 0;
					temp = 0;
					break;
				}
					tempIdx = 0;
				for(;tempIdx<count;tempIdx++){
					if(orginalList[tempIdx].Label == 4)
						break;
				}
			tempList[idx]=orginalList[tempIdx];
				orginalList[tempIdx].Label = -1;
				idx++;
				temp++;
				a4--;
				printf("4 ");
				break;
			default:
				printf("error");
		}
	}
	copy(tempList,orginalList);
}
void maintain_process(personal_information *list,int size){
    int i;
   for(i=0;i<size-1;i++){
    list[i]=list[i+1];
   }
   --i;
   int j;
}
int main(){
   personal_information list[50];
   char name1[50];
   int length;
   int call_list=0,call_list1=0,call_list2=0,call_list3=0,call_list4=0,Count=0,choice,x,i,j;
   int countforlabel0=0,countforlabel1=0,countforlabel2=0,countforlabel3=0,countforlabel4=0;
   int flag=0;
   printf("*********Banking System********\n");
   do{
	  if(flag==1&&Count>0){
		   printf("Current Sequence: ");
		  print(countforlabel0,countforlabel1,countforlabel2,countforlabel3,countforlabel4,list,Count);
		  printf("\n");
	  }
        printf("1-)Add customer\n");
        printf("2-)Process customer\n");
        printf("3-)Exit\n");
       scanf("%d",&choice);
        switch(choice){
        case 1:
        printf("Please enter the name of customer : \n");
   scanf("%s",name1);
   length=strlen(name1);
   strcpy(list[Count].name,name1);
    fflush(stdin);
   printf("Please enter the age of the customer : \n");
 scanf("%d",&list[Count].age);
  printf("Please enter the label of the customer : \n");
  scanf("%d",&list[Count].Label);
        if(list[Count].Label==0){
        ++countforlabel0;
       }if(list[Count].Label==1){
        ++countforlabel1;
       }if(list[Count].Label==2){
        ++countforlabel2;
       }if(list[Count].Label==3){
        ++countforlabel3;
       }if(list[Count].Label==4){
        ++countforlabel4;
       }
	   flag=0;
        ++Count;
		  printf("Current Sequence: ");
    	print(countforlabel0,countforlabel1,countforlabel2,countforlabel3,countforlabel4,list,Count);
			printf("\n");

        break;
        case 2:
            if(Count==0){
                printf("There is not any customer in bank system sequence\n");
            }else{

                printf("Proceed customer is %s\n",list[0].name);
               if(list[0].Label==0){
                countforlabel0--;
               }else if(list[0].Label==1){
                countforlabel1--;
               }else if(list[0].Label==2){
                countforlabel2--;
               }else if(list[0].Label==3){
                countforlabel3--;
               }else if(list[0].Label==4){
                countforlabel4--;
               }
			   maintain_process(list,Count);
               flag=1;
                --Count;

			}
            break;
        case 3:
            //printf("yii");
            Count=51;
            printf("See you...\n");
            break;
        default:
            printf("Error\n");
        }
   }while(Count<50);

    return 0;
}
