#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_COUNT 1000
#define MAX 30
typedef struct movie_budget{
    int budget;
    int year;
    char *name;
    struct movie_budget *next_budget;
}Movie_Budget;
typedef struct movie_name{
    double score;
    char *genre;
    char *name;
    struct movie_name *next_name;
}Movie_Name;
int length_of_file(char *filename){
    FILE *input;
    input=fopen(filename,"r");
    int i=0;
    char *dizi=(char *)malloc(LINE_COUNT);
    fgets(dizi,LINE_COUNT,input);
    while(fgets(dizi,LINE_COUNT,input)){
    printf("%d %s\n",i,dizi);
        i++;
    }
    i++;
    free(dizi);
    return i;
}
void decided_to_index(char *dizi,int *budget,int *genre,int *name,int *score,int *year);
void parse_array(char *dizi,Movie_Budget **list_budget,Movie_Name **list_name,int budget,int genre,int name,int score,int year){
    char *column;
    int flag=0,length=0;
    int temp=0;
    Movie_Budget *foo1 = *list_budget;
       Movie_Name *foo = *list_name;
    Movie_Budget *temp_budget = (Movie_Budget*) malloc(sizeof(Movie_Budget));
    temp_budget->next_budget=NULL;
    Movie_Name *temp_name = (Movie_Name*) malloc(sizeof(Movie_Name));
    temp_name->next_name=NULL;
    column=strtok(dizi,",");
    while(column!=NULL){
        if(flag==budget){
            if(strncmp(column,"unknown",7)==0){
            temp_budget->budget =-1;
            }
            else{
            temp_budget->budget=strtod(column,NULL);
            }
        }else if(flag==genre){
            (temp_name)->genre=(char *)malloc(MAX);
            if(strncmp((temp_name)->genre," ",1)==0){
            }else{
             strncpy((temp_name)->genre,column,MAX);
            }

        } else if(flag==name){
            length=strlen(column);
            length++;
            (temp_budget)->name=(char *)malloc(length);
            strncpy((temp_budget)->name,column,length);
            (temp_name)->name=(char *)malloc(length);
            strncpy((temp_name)->name,column,length);
        }
        else if(flag==score){
            (temp_name)->score=strtod(column,NULL);
        } else if(flag==year){
            (temp_budget)->year=(int)strtod(column,NULL);
        }
        column=strtok(NULL,",");
        flag++;
    }
    if (*list_name == NULL){
        *list_name = temp_name;
    }
    else{
        while (foo->next_name != NULL){
            foo = foo->next_name;
        }
        foo->next_name = temp_name;
    }
    if (*list_budget == NULL){
        *list_budget = temp_budget;
    }
    else{
        while (foo1->next_budget != NULL){
            foo1 = foo1->next_budget;
        }
        foo1->next_budget = temp_budget;
    }
}
void swap(Movie_Budget * temp,Movie_Name* temp1,Movie_Budget *temp2,Movie_Name*temp3){
	int tempyear = temp->year;
	int tempbudget = temp->budget;
	char *tempname = temp->name;
	temp->year = temp2->year;
	temp->budget = temp2->budget;
	temp->name = temp2->name;
	temp2->year = tempyear;
	temp2->budget = tempbudget;
	temp2->name = tempname;
	double tempscore = temp1->score;
    char *tempgenre = temp1->genre;
    tempname = temp1->name;
    temp1->score = temp3->score;
	temp1->genre = temp3->genre;
	temp1->name = temp3->name;
	temp3->score = tempscore;
	temp3->genre = tempgenre;
	temp3->name = tempname;
}
void edit_our_linked_list(int size,Movie_Budget *list_budget,Movie_Name* list_name){
     int i,j,z;
     int removeSize = 0;
     for(i = 0;i<size;i++){
     	Movie_Budget * temp = list_budget;
     	Movie_Name*    temp1 = list_name;
     	for(z=0;z<i;z++){
     		temp = temp->next_budget;
     		temp1 = temp1->next_name;
		}
     	Movie_Budget * temp2 = list_budget;
     	Movie_Name*    temp3 = list_name;
     	for(j = 0;j<size;j++){
     		if(strcmp(temp->name,temp2->name) == 0&& i!=j && strcmp(temp->name,"cagri") != 0){
     			removeSize++;
     			swap(temp,temp1,temp2,temp3);
     			temp2->name = "cagri";
     			temp2->year = 0;
			 }
     		temp2 = temp2->next_budget;
     		temp3 = temp3->next_name;
		}
	 }
     for(i = 0;i<size;i++){
     	Movie_Budget * temp = list_budget;
     	Movie_Name*    temp1 = list_name;
     	for(z=0;z<i;z++){
     		temp = temp->next_budget;
     		temp1 = temp1->next_name;
		}
     	Movie_Budget * temp2 = list_budget;
     	Movie_Name*    temp3 = list_name;
     	for(j = 0;j<size;j++){
     		if(temp->year > temp2->year || ((temp->year == temp2->year) && (temp->budget > temp2->budget) )){
     			//printf("%d/%d ->",temp->year,temp2->year);
     			swap(temp,temp1,temp2,temp3);
     			//printf("%d/%d\n",temp->year,temp2->year);
			 }
     		temp2 = temp2->next_budget;
     		temp3 = temp3->next_name;
		}
	 }
	 Movie_Budget * temp = list_budget;
     Movie_Name*    temp1 = list_name;
     while(temp!=NULL && temp->next_budget->year !=0){
     	temp = temp->next_budget;
     	temp1 = temp1->next_name;
	 }
	 temp->next_budget = NULL;
     temp1->next_name =NULL;
}
void insert_data_to_struct(int *size,char *filename,Movie_Budget **list_budget,Movie_Name **list_name){
    FILE *input;
    int q=0;
    input=fopen(filename,"r");
    int i=0;
    char *dizi;
    int budget=-1,genre=-1,name=-1,score=-1,year=-1;
    dizi=(char *)malloc(LINE_COUNT);
    fgets(dizi,LINE_COUNT,input);
    decided_to_index(dizi,&budget,&genre,&name,&score,&year);
     while(fgets(dizi,LINE_COUNT,input)){
        parse_array(dizi,list_budget,list_name,budget,genre,name,score,year);
        q++;
        (*size)++;
        i++;
    }
    free(dizi);
    fclose(input);
}
void decided_to_index(char *dizi,int *budget,int *genre,int *name,int *score,int *year){
        char *column;
        int flag=0;
        column = strtok (dizi,",");
        while (column!= NULL){
      if(strncmp(column,"budget",6)==0){
            *budget=flag;
        }else if(strncmp(column,"genre",5)==0){
            *genre=flag;
        }else if(strncmp(column,"name",4)==0){
            *name=flag;
        }else if(strncmp(column,"score",5)==0){
            *score=flag;
        }else if(strncmp(column,"year",4)==0){
            *year=flag;
        }
      column = strtok (NULL, ",");
        flag++;
    }
}
void parse_file_into_the_list(Movie_Budget **list_budget,Movie_Name **list_name,char *filename){}
void part6(Movie_Budget *head,Movie_Name *head1,char *point,int *flag1){
    int length1;
    int length=strlen(point);
    int flag=0;
    while (head != NULL&&head1!=NULL&&flag==0) {
       length1=strlen(head1->name);
       if(strncmp(head1->name,point,length1)==0&&length1==length){
            if(head->budget==-1){
                printf("Budget: Unknown\n");
            }else{
            printf("Budget: %d\n",head->budget);
            }
            printf("Genre: %s\n",head1->genre);
            printf("Name: %s\n",head->name);
            printf("Score: %.2lf\n",head1->score);
            printf("Year: %d\n",head->year);
            flag=1;
            *(flag1)=1;
       }
        head1=head1->next_name;
        head = head->next_budget;
    }
}
void part5(Movie_Budget *head,Movie_Name *head1,double score,int sayi,int *count1){
                int count=0;
                (*count1)=0;
        while(head1!=NULL&&head!=NULL){
                if(sayi==1){
                if(score<head1->score){
                printf("%s\n",head1->name);
                count++;
                }
                }
            if(sayi==0){
                if(score>head1->score){
                printf("%s\n",head1->name);
                count++;
                }
            }
            head=head->next_budget;
            head1=head1->next_name;
        }
        if(count==0){
            (*count1)=1;
            printf("TRY AGAIN\n");
        }
}
void part4(Movie_Budget *head,Movie_Name *head1,int year,int flag,int *count1){
     int count=0;
     (*count1)=0;
    while(head1!=NULL&&head!=NULL){
        if(flag==0){
            if(year>head->year){
                printf("%s\n",head1->name);
                count++;
            }
        }else if(flag==1){
            if(year< head->year){
                  printf("%s\n",head1->name);
                count++;
            }
        }
        head1=head1->next_name;
        head=head->next_budget;
    }
    if(count==0){
        printf("TRY AGAIN\n");
        (*count1)=1;
    }
}
int check_our_part3(char **arr1,char *str1,int size){
    int flag=0;
    int i;
    int length1,length2;
    length1=strlen(str1);
    for(i=0;i<size;i++){
            length2=strlen(arr1[i]);
        if(strncmp(arr1[i],str1,length2)==0&&length1==length2){
            flag=0;
            break;
        }else{
            flag=1;
        }
    }
    return flag;
}
void part3(Movie_Budget *list1,Movie_Name *list2,char **array1,int *size){
    Movie_Name *list3=(Movie_Name *)malloc(sizeof(Movie_Name));
    list3=list2;
    int length1,length2;
    length1=strlen(list3->genre);
    int i=0;
    int flag=0;
    int result=0;
      strncpy(*(array1+i),list2->genre,length1);
    ++i;
    while(list2!=NULL){
            result=check_our_part3(array1,list2->genre,i);
        if(result==1){
            strncpy(*(array1+i),list2->genre,strlen(list2->genre));
            ++i;
        }
            list2=list2->next_name;
    }
    *(size)=i;
    int x;
    for(x=0;x<i;x++){
        printf("%s\n",array1[x]);
    }
    free(array1);
}

void sortByColumn(int size,Movie_Budget *list_budget,Movie_Name* list_name,int start,int end,int column){
	int i,j,z;
	int count=0;
    Movie_Budget *head_budget=NULL,*current_budget=NULL,*iterator_budget=NULL;
    Movie_Name *head_name=NULL,*current_name=NULL,*iterator_name=NULL;
    head_budget=list_budget;
    head_name=list_name;
    for(int i=0;i<start;i++){
            head_budget=head_budget->next_budget;
            head_name=head_name->next_name;
    }
    current_budget=head_budget;
    current_name=head_name;
    iterator_budget=current_budget;
    iterator_name=current_name;
	for(i = start;i<=end;i++){
     	for(j = i;j<=end;j++){
            iterator_budget = iterator_budget->next_budget;
     		iterator_name = iterator_name->next_name;
     		if(column==1 && current_budget->budget < iterator_budget->budget){
                swap(current_budget,current_name,iterator_budget,iterator_name);
            }else if(column==2 && strncmp(current_name->genre,iterator_name->genre,strlen(current_name->genre)) > 0){
                swap(current_budget,current_name,iterator_budget,iterator_name);
            }else if(column==3 && strncmp(current_name->name,iterator_name->name,strlen(current_name->name)) > 0){
                swap(current_budget,current_name,iterator_budget,iterator_name);

            }else if(column==4 && current_name->score > iterator_name->score){
                swap(current_budget,current_name,iterator_budget,iterator_name);

            }else if(column==5 && current_budget->year > iterator_budget->year){
                swap(current_budget,current_name,iterator_budget,iterator_name);
            }
            count++;

		}
        iterator_budget=current_budget;
        iterator_name=current_name;
       current_budget=current_budget->next_budget;
        current_name=current_name->next_name;
	 }
    current_budget=head_budget;
    current_name=head_name;
    for(i=start;i<=end;i++){
            if(current_budget->budget==-1){
                printf("%s || %s || %.3lf || Unknown || %d\n",current_name->name,current_name->genre,current_name->score,current_budget->year);
            }else{
                printf("%s || %s || %.3lf || %d || %d\n",current_name->name,current_name->genre,current_name->score,current_budget->budget,current_budget->year);
            }
        current_budget = current_budget->next_budget;
        current_name = current_name->next_name;
    }

}
/*
void sortByBudget(int size,Movie_Budget *list_budget,Movie_Name* list_name,int start,int end){
	int i,j,z;
	int count=0;
		Movie_Budget * temp_2 = list_budget;
     	Movie_Name*    temp_3 = list_name;
	for(i = 0;i<size;i++){
     	Movie_Budget * temp = list_budget;
     	Movie_Name*    temp1 = list_name;
     	for(z=0;z<i;z++){
     		temp = temp->next_budget;
     		temp1 = temp1->next_name;
		}
     //	Movie_Budget * temp2 = list_budget;
     	//Movie_Name*    temp3 = list_name;
     	for(j = 0;j<size;j++){

			if(count>=start && count<=end){
     		if(temp->budget > temp2->budget ){
     			//printf("%d/%d ->",temp->year,temp2->year);
     			swap(temp,temp1,temp2,temp3);
                 printf("HereSwap");
     			//printf("%d/%d\n",temp->year,temp2->year);
			 }
             count++;
		    }
     	//	temp2 = temp2->next_budget;
     	//	temp3 = temp3->next_name;
		}
	 }
     printf("Here8");
	 i=0;
     size--;
	 while(size>i){
        if(i>=start&&i<=end){
            printf("%s %d\n",temp_3->name,temp_2->budget);
        }
        if(i==end){
            break;
        }
        temp_2 = temp_2->next_budget;
        temp_3 = temp_3->next_name;
		i++;
	 }
}*/
void frequence(Movie_Name *head,char **arr1,int size) {
    int i=0;
    int x =0;
    ++size;
    int *dizi=(int *)calloc(size,sizeof(int));
    int a=0;
    for(a=0;a<size;a++){
        dizi[a]=0;
    }
    int adventure,action,animation,drama,comedy,crime,horror,biography,musical=0;
    while ( head != NULL) {
            if(strncmp(head->genre,"adventure",9)==0){
                dizi[0]+=1;
            }
           else if(strncmp(head->genre,"action",6)==0){
                dizi[1]+=1;
            }
           else if(strncmp(head->genre,"animation",9)==0){
                dizi[2]+=1;
            }
           else if(strncmp(head->genre,"drama",5)==0){
                dizi[3]+=1;
            }
           else if(strncmp(head->genre,"comedy",6)==0){
                dizi[4]+=1;
            }
           else if(strncmp(head->genre,"crime",5)==0){
                dizi[5]+=1;
            }
           else if(strncmp(head->genre,"horror",6)==0){
                dizi[6]+=1;
            }
           else if(strncmp(head->genre,"biography",9)==0){
                dizi[7]+=1;
            }
           else if(strncmp(head->genre,"sci-fi",6)==0){
                dizi[8]+=1;
            }
           else if(strncmp(head->genre,"musical",7)==0){
                dizi[9]+=1;
            }
           else if(strncmp(head->genre,"mystery",7)==0){
                dizi[10]+=1;
            }
           else if(strncmp(head->genre,"romance",7)==0){
                dizi[11]+=1;
            }
           else if(strncmp(head->genre,"thriller",8)==0){
                dizi[12]+=1;
            }
           else if(strncmp(head->genre,"western",7)==0){
                dizi[13]+=1;
            }
           else if(strncmp(head->genre,"fantasy",7)==0){
                dizi[14]+=1;
            }
           else if(strncmp(head->genre,"war",3)==0){
                dizi[15]+=1;
            }
           else if(strncmp(head->genre,"family",6)==0){
                dizi[16]+=1;
            }else{

            }
        head = head->next_name;
    }
    printf("\n Action: %d",dizi[1]);
    printf("\n Adventure: %d",dizi[0]);
    printf("\n Animation: %d",dizi[2]);
    printf("\n Biography: %d",dizi[7]);
    printf("\n Comedy: %d",dizi[4]);
    printf("\n Crime: %d",dizi[5]);
    printf("\n Drama: %d",dizi[3]);
    printf("\n Family: %d",dizi[16]);
    printf("\n Fantasy: %d",dizi[14]);
    printf("\n Horror: %d",dizi[6]);
    printf("\n Musical: %d",dizi[9]);
    printf("\n Mystery: %d",dizi[10]);
    printf("\n Romance: %d",dizi[11]);
    printf("\n Sci-Fi: %d",dizi[8]);
    printf("\n Thriller: %d",dizi[12]);
    printf("\n War: %d",dizi[15]);
    printf("\n Western: %d\n",dizi[13]);
}
void average(Movie_Name *head) {
    double count = 0;
    double total = 0;
    while ( head != NULL) {
        total += head->score;
        count++;
        head = head->next_name;
    }
    printf("Average: %.3lf\n",total/count);
}
void display_list(Movie_Budget *head){
    while(head!=NULL){
            printf("%d\n",head->year);
            head=head->next_budget;
    }
}
void sorted_for_part1(Movie_Budget *list,Movie_Name *list1,int selection,int part1_first_val,int part1_second_val,int size){
    Movie_Budget *temp=list;
    Movie_Budget *temp1=list;
        int count=part1_first_val;
        switch(selection){
    case 1:
        printf("Sorted by Budget\n");
       // sortByBudget(size,list,list1,part1_first_val,part1_second_val);
       sortByColumn(size,list,list1,part1_first_val,part1_second_val,1);
        break;
    case 2:
        printf("Sorted by Genre\n");
        sortByColumn(size,list,list1,part1_first_val,part1_second_val,2);
        break;
    case 3:
        printf("Sorted by Name\n");
        sortByColumn(size,list,list1,part1_first_val,part1_second_val,3);
        break;
    case 4:
        printf("Sorted by Score\n");
        sortByColumn(size,list,list1,part1_first_val,part1_second_val,4);
        break;
    case 5:
        printf("Sorted by Year\n");
        sortByColumn(size,list,list1,part1_first_val,part1_second_val,5);
        break;
    }
}
void menu(char *filename){
Movie_Budget *list=NULL;
   Movie_Name *list1=NULL;
   int x,y,z,t,a,year,flag,size=0;
   int flag1;
    char *point=(char *)malloc(sizeof(char)*50);
    double score;
    int q=0;
    int ourmainflag;
     Movie_Budget *list_a;
    Movie_Budget *zz;
    int count_part3=0,count_part4=0;
    list_a=list;
    int size2;
  	insert_data_to_struct(&size,filename,&list,&list1);
  	edit_our_linked_list(size,list,list1);
  	 char  **array1;
    int ii;
    array1 = calloc(size, sizeof(char *));
        for(ii = 0; ii < size; ii++) {
        array1[ii] = calloc(30, sizeof(char));
        }
    int selection;
    int choice;
    int part1_first_val,part1_second_val;
    int temp_val=1;
    int decided_which;
    int true_1=1;
    printf("1. List of the Sorted Data\n");
    printf("2. List of the Genres\n");
    printf("3. List of the Movie Through the Years\n");
    printf("4. List of the Movie Through the Scores\n");
    printf("5. All Informations of a Single Movie\n");
    printf("6. Average of the IMDB Scores\n");
    printf("7. Frequence of the Genres\n");
    printf("8. Exit\n");
    do{
        printf("Please select an operation\n");
        scanf("%d",&choice);
        if(choice==1){
             printf("1. Budget\n");
            printf("2. Genre\n");
            printf("3. Name\n");
            printf("4. Score\n");
            printf("5. Year\n");
            while(temp_val){
                 printf("Please Select an operation\n");
            scanf("%d",&selection);
            if(selection>=1&&selection<=5){
                temp_val=0;
            }else{
                temp_val=1;
            }
            }
            printf("1. Single Selection\n");
            printf("2. Multiple Selection\n");
            printf("Enter your value\n");
            scanf("%d",&decided_which);
            printf("Enter first value\n");
            scanf("%d",&part1_first_val);
            if(decided_which==1){
                part1_second_val=part1_first_val;
            }else{
                printf("Enter second value\n");
                scanf("%d",&part1_second_val);
            }
            sorted_for_part1(list,list1,selection,part1_first_val,part1_second_val,size);

        }else if(choice==2){
           part3(list,list1,array1,&size2);
        }else if(choice==3){
         printf("Enter a year\n");
    scanf("%d",&year);
    printf("Until (0) or Since(1)\n");
    scanf("%d",&flag);
    part4(list,list1,year,flag,&count_part3);
     while(count_part3){
    getchar();
    printf("Enter a year\n");
    scanf("%d",&year);
    part4(list,list1,year,flag,&count_part3);
    }
        }else if(choice==4){
        printf("Enter a score\n");
    scanf("%lf",&score);

    printf("Until (0) or Since(1)\n");
    getchar();
    scanf(" %d",&flag1);
    part5(list,list1,score,flag1,&count_part4);
    while(count_part4){
    getchar();
    printf("Enter a score\n");
    scanf("%lf",&score);
    part5(list,list1,score,flag1,&count_part4);
    if(count_part4==0){
    }else{
        printf("Try Again\n");
    }
    }
        }else if(choice==5){
         printf("Please Enter the name of the movie:\n");
    getchar();
    gets(point);
    part6(list,list1,point,&ourmainflag);
    if(ourmainflag!=1){
        printf("TRY AGAIN\n");
    }
        }else if(choice==6){
           average(list1);
        }else if(choice==7){
         frequence(list1,array1,size);
        }else if(choice==8){
            printf("See you later\n");
            true_1=0;
        }else{
            printf("Enter between 1-8\n");
        }
    }while(true_1);
}
int main(){
   menu("Movies.txt");

    return 0;
}
