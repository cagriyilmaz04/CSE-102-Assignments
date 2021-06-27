#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_COUNT 1000
#define MAX 200
typedef struct{
    double budget;
    int genre;
    char *name;
    double score;
    int year;
}Movie;
int length_of_file(char *filename){
    FILE *input;
    input=fopen(filename,"r");
    int i=0;
    char *dizi=(char *)malloc(LINE_COUNT);
    fgets(dizi,LINE_COUNT,input);
    while(fgets(dizi,LINE_COUNT,input)){
        i++;
    }
    free(dizi);
    return i;
}
void parse_array(char *dizi,Movie *x,int budget,int genre,int name,int score,int year){
    char *column;
    int flag=0,length=0;
    int temp=0;
    column=strtok(dizi,",");
    while(column!=NULL){
       // printf("%s  ",column);
        if(flag==budget){
            if(strncmp(column,"unknown",7)==0){
                (*x).budget=-1;
            }else{
                (*x).budget=strtod(column,NULL);
            }
        }else if(flag==genre){
            if(strncmp(column,"action",6)==0){
                    (*x).genre=1;
                }else if(strncmp(column,"adventure",9)==0){
                    (*x).genre=2;
                }else if(strncmp(column,"animation",9)==0){
                (*x).genre=3;
                }else if(strncmp(column,"biography",9)==0){
                    (*x).genre=4;
                }
                else if(strncmp(column,"comedy",6)==0){
                    (*x).genre=5;
                }else if(strncmp(column,"crime",5)==0){
                    (*x).genre=6;
                } else if(strncmp(column,"drama",5)==0){
                    (*x).genre=7;
                }else if(strncmp(column,"family",6)==0){
                    (*x).genre=8;
                }
                else if(strncmp(column,"fantasy",7)==0){
                    (*x).genre=9;
                }else if(strncmp(column,"horror",6)==0){
                    (*x).genre=10;
                }
               else if(strncmp(column,"musical",7)==0){
                    (*x).genre=11;
                }else if(strncmp(column,"mystery",7)==0){
                    (*x).genre=12;
                }else if(strncmp(column,"romance",7)==0){
                    (*x).genre=13;
                }else if(strncmp(column,"sci-fi",6)==0){
                    (*x).genre=14;
                }
                else if(strncmp(column,"thriller",8)==0){
                    (*x).genre=15;
                }
                else if(strncmp(column,"war",3)==0){
                    (*x).genre=16;
                }else if(strncmp(column,"western",7)==0){
                    (*x).genre=17;
                }
        }else if(flag==name){
            length=strlen(column);
            length++;
            x->name=(char *)malloc(length);
            strncpy(x->name,column,length);
        }else if(flag==score){
            (*x).score=strtod(column,NULL);

        }else if(flag==year){
            (*x).year=(int)strtod(column,NULL);
        }
        column=strtok(NULL,",");
        flag++;
    }
}
void decided_to_index(char *dizi,int *budget,int *genre,int *name,int *score,int *year);
void insert_data_to_struct(Movie *movie1,int *size,char *filename){
    FILE *input;
    int q=0;
    input=fopen(filename,"r");
    int i=0;
    char *dizi;
    int budget=-1,genre=-1,name=-1,score=-1,year=-1;
    dizi=(char *)malloc(LINE_COUNT);
    fgets(dizi,LINE_COUNT,input);
    decided_to_index(dizi,&budget,&genre,&name,&score,&year);
     while(fgets(dizi,LINE_COUNT,input) ){
        parse_array(dizi,&movie1[i],budget,genre,name,score,year);
        q++;
        (*size)++;
        i++;
    }
        free(dizi);
        (*size)--;
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
void edit_for_the_same_movies(Movie *list,int *size,char *filename){
    int i,j;
    insert_data_to_struct(list,size,filename);
    for(i=0;i<*(size)-1;i++){
        for(j=i+1;j<*size;j++){
                //printf("yiii %d\n",j);
			int length=strlen(list[i].name);
           int length1=strlen(list[j].name);
           if(strncmp(list[i].name,list[j].name,length1)==0&&strncmp(list[i].name,list[j].name,length)==0 && list[i].score!=-1 && list[j].score!=-1&&length1==length){
                list[i].budget=list[j].budget;
                list[i].genre=list[j].genre;
                list[i].score=list[j].score;
                list[i].year=list[j].year;
                list[i].budget=list[j].budget;
                list[j].score=-1;
           }
        }
    }
}
void decided_which_one(Movie *list){
    if(list->score!=-1){
            if(list->genre==1){
            printf("Action ");
        }
        else if(list->genre==2){
            printf("Adventure ");
        }
        else if(list->genre==3){
            printf("Animation ");
        }else if(list->genre==4){
            printf("Biography ");
        }
        else if(list->genre==5){
            printf("Comedy ");
        }
        else if(list->genre==6){
            printf("Crime ");
        }
        else if(list->genre==7){
            printf("Drama ");
        }else if(list->genre==8){
            printf("Family ");
        }
        else if(list->genre==9){
            printf("Fantasy ");
        }
        else if(list->genre==10){
            printf("Horror ");
        }else if(list->genre==11){
            printf("Musical ");
        }else if(list->genre==12){
            printf("Mystery ");
        }
        else if(list->genre==13){
            printf("Romance ");
        }
        else if(list->genre==14){
            printf("Sci-fi ");
        }
        else if(list->genre==15){
            printf("Thriller ");

        }
        else if(list->genre==16){
            printf("War ");
        }else if(list->genre==17){
            printf("Western ");
        }
        else{
    }
    }
}
void list_of_genres(Movie *list,int size){
   Movie *newlist;
    int j;
    int i;
    newlist=(Movie *)calloc(size,sizeof(Movie));
   int count=0;
   for(i=0;i<size;i++){
      int flag = 0;
      for( j=0;j<size;j++){
         if( newlist[j].genre == list[i].genre){
            flag=1;
         }
      }
      if(flag== 0){
         newlist[count++].genre = list[i].genre;
         decided_which_one(&list[i]);
         printf("\n");
      }
   }
}
void list_through_the_score(Movie *list,int size,double score,int choice){
    int i;
    for(i=0;i<size;i++){
            if(list[i].score!=-1){
        if(choice==0){
            if(list[i].score<score){
                printf("%s\n",list[i].name);
            }else if(score==list[i].score){
                printf("TRY AGAIN\n");
            }
        }else if(choice==1){
            if(list[i].score>score){
                printf("%s\n",list[i].name);
            }else if(score==list[i].score){
               // printf("TRY AGAIN");
            }
    }
            }
    }
}
void  list_through_the_years(Movie *list,int size,int year,int choice){
    int i;
    for(i=0;i<size;i++){
            if(list[i].score!=-1){
        if(choice==0){
            if(list[i].year<=year){
                printf("%s\n",list[i].name);
            }
        }else if(choice==1){
        if(list[i].year>=year){
                printf("%s\n",list[i].name);
            }
        }
    }
    }
}
void all_informations_of_a_single_movie(Movie *list,char *movie_name,int size,int length_of_movie_name){
    int i;
    int flag=0;
    for(i=0;i<size;i++){

        if(strcmp(list[i].name,movie_name)==0){
           // printf("Yiiiiiiii %d\n",i);
            if(list[i].budget==-1){
                printf("Budget: Unknown\n");
            }else{
               printf("Budget: %.2lf\n",list[i].budget);
            }
            printf("Genre: ");
            decided_which_one(&list[i]);
            printf("\n");
            flag=0;
            printf("Name: %s\n",list[i].name);
            printf("Score: %.2lf\n",list[i].score);
            printf("Year: %d\n",list[i].year);
           i=size+1;
        }else{
                flag=1;
        }
    }
    if(flag==1){
        printf("There is no movie\n");
    }
}
double  average_of_imdb_scores(Movie *list,int size){
    int i;
    double count=0;
    double sum=0;
    for(i=0;i<size;i++){
            if(list[i].score!=-1){
            sum+=list[i].score;
            count++;
    }
    }
    sum=(double)sum/(double)count;
    return sum;
}
void frequence_of_the_genres(Movie *list,int size){
    int i;
    int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0,count12=0,count13=0,count14=0,count15=0,count16=0;
    for(i=0;i<size;i++){
        if(list[i].score!=-1){
        switch(list[i].genre){
        case 1:
            count0++;
            break;
        case 2:
            count1++;
            break;
       case 3:
            count2++;
            break;
        case 4:
            count3++;
            break;
        case 5:
            count4++;
            break;
        case 6:
            count5++;
            break;
         case 7:
            count6++;
            break;
          case 8:
            count7++;
            break;
           case 9:
            count8++;
            break;
           case 10:
            count9++;
            break;
           case 11:
            count10++;
            break;
           case 12:
            count11++;
            break;
           case 13:
            count12++;
            break;
           case 14:
            count13++;
            break;
           case 15:
            count14++;
            break;
           case 16:
            count15++;
            break;
           case 17:
            count16++;
            break;
            }
            }
    }
    printf("Action: %d\n",count0);
    printf("Adventure: %d\n",count1);
    printf("Animation: %d\n",count2);
    printf("Biography: %d\n",count3);
    printf("Comedy: %d\n",count4);
    printf("Crime: %d\n",count5);
    printf("Drama: %d\n",count6);
    printf("Fantasy: %d\n",count7);
    printf("Family: %d\n",count8);
    printf("Horror: %d\n",count9);
    printf("Musical: %d\n",count10);
    printf("Mystery: %d\n",count11);
    printf("Romance: %d\n",count12);
    printf("Sci-fi: %d\n",count13);
    printf("Thriller: %d\n",count14);
    printf("War: %d\n",count15);
    printf("Western: %d\n",count16);
}
void sorted_list_data(Movie *list,int under_choice,int other_choice,int size,int value,int value1){
    int i,j;
    Movie temp;
    for(i=value;i<=value1;i++){
           for(j=i+1;j<=value1;j++){
                if(list[i].score!=-1&&list[j].score!=-1){
        if(under_choice==1){
                if(list[i].budget>list[j].budget){
                    temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
        }else if(under_choice==2){
                if(list[i].genre>list[j].genre){
                    temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
        }else if(under_choice==3){
                if(strcmp(list[i].name,list[j].name)==1){
                    temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
        }else if(under_choice==4){
                if(list[i].score>list[j].score){
                    temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
        }else if(under_choice==5){
                if(list[i].year>list[j].year){
                    temp=list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
        }
           }
           }
    }
        if(value1!=value){
           switch(under_choice){
        case 1:
             printf("Movies between %d and %d sorted by Budget\n",value,value1);
            break;
        case 2:
                printf("Movies between %d and %d sorted by Genre\n",value,value1);
                break;
        case 3:
                printf("Movies between %d and %d sorted by Name\n",value,value1);
                break;
        case 4:
                printf("Movies between %d and %d sorted by Score\n",value,value1);
                break;
        case 5:
                printf("Movies between %d and %d sorted by Year\n",value,value1);
                break;
           }
            for(i=value;i<=value1;i++){
                if(list[i].budget!=-1){
            if(under_choice==1){
                decided_which_one(&list[i]);
               printf("%s %.2lf %d\n",list[i].name,list[i].score,list[i].year);
            }else if(under_choice==2){
                printf("%.2lf ",list[i].budget);
                printf("%s %.2lf %d\n",list[i].name,list[i].score,list[i].year);
            }else if(under_choice==3){
                printf("%.2lf ",list[i].budget);
                decided_which_one(&list[i]);
            printf("%.2lf %d\n",list[i].score,list[i].year);
            }else if(under_choice==4){
                //score
                  printf("%.2lf ",list[i].budget);
                decided_which_one(&list[i]);
                 printf("%s %d\n",list[i].name,list[i].year);
            }else if(under_choice==5){
                //year
                printf("%.2lf ",list[i].budget);
               decided_which_one(&list[i]);
                printf("%s %.2lf\n",list[i].name,list[i].score);
            }
                }
        }
           }else{

            if(list[value1].budget!=-1){
                    printf("Movie %d\n",value1);
            if(under_choice==1){
                     printf("Movie sorted by Budget\n");
                decided_which_one(&list[value1]);
               printf("%s %.2lf %d\n",list[value1].name,list[value1].score,list[value1].year);
            }else if(under_choice==2){
                printf("Movie sorted by Genre\n");
                printf("%.2lf ",list[value1].budget);
                printf("%s %.2lf %d\n",list[value1].name,list[value1].score,list[value1].year);
            }else if(under_choice==3){
                printf("Movie sorted by Name\n");
                printf("%.2lf ",list[value1].budget);
                decided_which_one(&list[value1]);
            printf("%.2lf %d\n",list[value1].score,list[value1].year);
            }else if(under_choice==4){
                printf("Movie sorted by Score\n");
                //score
                  printf("%.2lf ",list[value1].budget);
                decided_which_one(&list[value1]);
                 printf("%s %d\n",list[value1].name,list[value1].year);
            }else if(under_choice==5){
                //year
                printf("Movie sorted by Year\n");
                printf("%.2lf ",list[value1].budget);
               decided_which_one(&list[value1]);
                printf("%s %.2lf\n",list[value1].name,list[value1].score);
            }
                }else{
                    printf("This movie has unknown budget\n");
                }
            }
}
void menu(char *file_name){
     Movie *list;
    int x,year,choice,under_choice,start,finish,length_of_movie_name,other_choice,under_choice1;
    int size=length_of_file(file_name);
    //printf("Size:%d\n",size);
char *movie_name=(char *)malloc(MAX);
    int our_size=0;
    int flag=0;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    list=(Movie *)calloc(size,sizeof(Movie));
    edit_for_the_same_movies(&list[0],&our_size,file_name);
    double score;
    printf("1. List of the Sorted Data\n");
    printf("2. List of the Genres\n");
    printf("3. List of the Movie Through the Years\n");
    printf("4. List of the Movie Through the Scores\n");
    printf("5. List of the All information\n");
    printf("6. Average of the IMDB Scores\n");
    printf("7. Frequence of the Genres\n");
    printf("8. Exit\n");
    int value,value1;
    do{
       printf("Please Select an operation: ");
        scanf("%d",&choice);
        flag=0;
        flag1=0;
        switch(choice){
    case 1:
        printf("1. Budget\n");
        printf("2. Genre\n");
        printf("3. Name\n");
        printf("4. Score\n");
        printf("5. Year\n");
        printf("Please Select an operation : \n");
            while(flag==0){
                  scanf("%d",&under_choice);
                if(!(under_choice>=1&&under_choice<=5)){
                     printf("Enter a value between 1-5\n");
                }else{
                    flag=1;
                }
            }
        printf("1. Single Selection\n");
        printf("2. Multiple Selection\n");
        printf("Please Select an operation :\n");
                while(flag1==0){
                   scanf("%d",&other_choice);
                if(!(other_choice>=1&&other_choice<=2)){
                     printf("Error\n");
                }else{
                    flag1=1;
                }
            }
        printf("Enter value\n");
        scanf("%d",&value);
        if(other_choice==2){
        printf("Enter value\n");
        scanf("%d",&value1);
        }else if(other_choice==1){
            value1=value;
        }
        sorted_list_data(&list[0],under_choice,other_choice,size,value,value1);
        break;
    case 2:
          list_of_genres(&list[0],size);
        break;
    case 3:
        printf("Enter a year:\n");
        scanf("%d",&year);
        printf("Until (0) or Since(1): \n");
        list_through_the_years(&list[0],size,year,under_choice);
        break;
    case 4:
      printf("Enter a score\n");
        scanf("%lf",&score);
        printf("Less (0) or Greater (1) %lf :\n",score);
         getchar();
          scanf("%d",&under_choice1);
         list_through_the_score(&list[0],size,score,under_choice1);
        break;
    case 5:
        printf("Please Enter the name of the movie : \n");
        getchar();
       gets(movie_name);
        length_of_movie_name=strlen(movie_name);
        length_of_movie_name--;
        all_informations_of_a_single_movie(&list[0],movie_name,size,length_of_movie_name);
        break;
    case 6:
        printf("%.2lf\n",average_of_imdb_scores(list,size));
        break;
    case 7:
        frequence_of_the_genres(list,size);
        break;
    default:
        printf("TRY AGAIN.\n");
          flag1=0;
          flag=0;
    }
}while(choice!=8);
}
int main(){
    menu("Movies.txt");
    return 0;
}
