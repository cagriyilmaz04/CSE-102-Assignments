#include <stdio.h>
#include <stdlib.h>
#define size 4
#define max 99
typedef enum {right,left,up,down}Direction;
void print_table(int dizi2[size][size]){
 int i,j,x;
 int b;
 for(i=0;i<size;i++){
        for(b=0;b<size;b++){
            printf("*********");
        }
        printf("*\n");
		printf("*");

        for(j=0;j<size;j++){
            if(dizi2[i][j]!=-1){
                 printf("%5d   *",dizi2[i][j]);
            }else{
                printf("   __   *");
            }
			
        }
            printf("\n");
		
         if(i==size-1){
			for(x=0;x<size;x++){
				 printf("*********");
			}
			printf("*");
		 }
		 
		 
    }
	printf("\n");
	}
int is_it_suitable(int sayi1[size][size],int sayi,int x,int y){
    int i,j,k=0;
    int count=0;
    int count1=0;
    int sayi2[size*size];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            sayi2[k]=sayi1[i][j];
            k++;
        }
    }
    int temp;
    temp=(k-1);
    while(temp>=0){
        if(sayi2[temp]==sayi){
            count++;
        }
        temp--;
    }
    int flag=0;
    if(count==0&&sayi1[x][y]==-1){
            sayi1[x][y]=sayi;
        flag=1;
    }
    return flag;
}

void fiil_array(int sayi[size][size]){
    int i,j;
    int count3=0;
    int b;
    int result;
    int x,y;
    int count1=0,count2=0;
    int number;
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
      sayi[i][j]=-1;
      }
    }
    while(count3<(size*size)-1){
        x=rand()%size;
        y=rand()%size;
        b=rand()%max;
           result=is_it_suitable(sayi,b,x,y);
            if(result==1){
                sayi[x][y]=b;
                count3++;
            }

    }
    print_table(sayi);
}
int check_right_side(int dizi2[size][size],int x,int y){
   int j;
   int flag=0;
   for(j=y;j<size;j++){
    if(dizi2[x][j]==-1){
        flag=1;
    }
   }

    return flag;
}
int check_left_side(int dizi2[size][size],int x,int y){
   int flag=0;
    int j;
    for(j=y;j>=0;j--){

        if(dizi2[x][j]==-1){
            flag=1;
        }
    }

    return flag;
}
int check_down_side(int dizi2[size][size],int x,int y){
   int flag=0;
   int i;
   for(i=x;i<=size;i++){
        if(dizi2[i][y]==-1){
                    flag=1;

               }
   }

    return flag;
}
int check_upper_side(int dizi2[size][size],int x,int y){
   int j;
   int flag=0;
   for(j=x;j>=0;j--){
     if(dizi2[j][y]==-1){
                    flag=1;
               }
   }
    return flag;
}
int can_I_move(int dizi2[size][size],Direction whichone,int x,int y){
    int result;
    int flag=0;

    switch(whichone){
    case right:
       result=check_right_side(dizi2,x,y);

        if(result==1){
            flag=1;
        }
        break;
    case left:
        result=check_left_side(dizi2,x,y);
    if(result==1){

            flag=1;
        }
        break;
        case up:
        result=check_upper_side(dizi2,x,y);
        if(result==1){

            flag=1;
        }
        break;
    case down:
           result=check_down_side(dizi2,x,y);
    if(result==1){

            flag=1;
        }
        break;

    default:
        printf("You cannot move\n");

    }
    return flag;
}


void move_to_the_right(int dizi[size][size],int x,int y,int *x1,int *y1){
    int temp1,temp2;
    int i,j;
    int sayi=dizi[x][y];
    if(check_right_side(dizi,x,y)){
        *x1=x;
       *y1=y;
       for(j=0;j<size;j++){
            if(dizi[x][j]==-1){
				
                   while(j>y){					
                dizi[x][j]=dizi[x][j-1];
                    j--;
                    }
					
            }
        }
        dizi[*x1][*y1]=-1;



    print_table(dizi);
	
}

}
void move_to_the_left(int dizi[size][size],int x,int y,int *x1,int *y1){
     int temp1,temp2;
    int i,j;
    int sayi=dizi[x][y];
 if(check_left_side(dizi,x,y)==1){
        *x1=x;
        *y1=y;
        for(j=0;j<size;j++){
            if(dizi[x][j]==-1){
                    while(y>j){
                        dizi[x][j]=dizi[x][j+1];
                        j++;
                    }

            }

    }
    dizi[*x1][*y1]=-1;
    print_table(dizi);
}
}
void move_to_the_down(int dizi[size][size],int x,int y,int *x1,int *y1){
   int temp1,temp2;
    int i,j;
    int sayi=dizi[x][y];
 if(check_down_side(dizi,x,y)==1){
		*x1=x;
		*y1=y;
    for(i=(size-1);i>=0;i--){
       if(dizi[i][y]==-1){
            while(x<=i){
                    *x1=i;
                dizi[*x1][y]=dizi[*x1-1][y];
                i--;
            }
       }
    }
    dizi[*x1][*y1]=-1;
    print_table(dizi);
}
}
void move_to_the_up(int dizi[size][size],int x,int y,int *x1,int *y1){
   int temp1,temp2;
    int i,j;
    int temp3;
    int sayi=dizi[x][y];
 if(check_upper_side(dizi,x,y)==1){
       
        (*x1)=x;
        (*y1)=y;
       for(i=0;i<size;i++){
            if(dizi[i][y]==-1){
                    while(i<x){
                          dizi[i][y]=dizi[i+1][y];
                          i++;
                    }
                    if(i==x){
                            dizi[*x1][*y1]=-1;
                        break;

                    }

            }
       }



   /* for(i=0;i<size;i++){
            temp3=i;
        for(j=0;j<size;j++){
            while(dizi[i][j]!=-1){
                    *x1=i;
                    *y1=j;
                dizi[*x1][*y1]=sayi;
               // dizi[x][y]=-1;
                dizi[temp1][temp2]=-1;
            }

        }
    }*/
    print_table(dizi);
}
}
int is_it_done(int dizi[size][size]){
int i=0,j=0;
int count=0;
int flag=1;
int temp;
int dizi2[(size*size)-1];
int count2=0;
int x=0;
  while(i!=size){
        while(j!=size){
                if(dizi[i][j]!=-1){
                     dizi2[count]=dizi[i][j];

                }else{
                    j++;
                    j--;
                }

             count++;
            j++;
        }
        j=0;
i++;
    }

   // printf("\n");

    for(i=0;i<(size*size)-1;i++){
        for(j=i;j<((size*size)-2);j++){
            if(dizi2[i]>dizi2[j+1]){
                temp=dizi2[i];
                dizi2[i]=dizi2[j+1];
                dizi2[j+1]=temp;
            }

        }
    }
    count=0;
    i=0;
    j=0;
    count2=0;
    x=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){

                if(dizi2[x]==dizi[i][j]&&x!=(size*size)&&dizi[i][j]!=-1){
                    count++;
                }
        x++;

        }
    }
 
 
     if(count==(size*size)-1){
        printf("You are Done !!\n");
        flag=1;
    }else{
        flag=0;
    }
    return flag;
}
void menu(){
    printf("Welcome to our game\n");
    printf("There is an under line You can assume that the under line is empty space\n");
    printf("0 RIGHT\n");
    printf("1 LEFT\n");
    printf("2 UP\n");
    printf("3 DOWN\n");
}
void play_game_and_choose_direction(){
  int dizi[size][size];
    int i,j;
    int x,y;
    int temp=1;
    menu();
    int direction;
    int result1;
    int finish=0;
    int x1,x2;
    fiil_array(dizi);
    while(temp){
    printf("Enter x coordinate\n");

    while(scanf("%d",&x)!=1||x<0.000||x>=size){
        printf("Enter Correct number\n");
    }
    printf("Enter y coordinate\n");
     while(scanf("%d",&y)!=1||y<-1||y>=size){
			while(getchar()!='\n');
        printf("Enter Correct number\n");
    }
    Direction moving;
    printf("Enter your direction\n");
    
	while(scanf("%d",&direction)!=1||direction<0.0000||direction>4){
			while(getchar()!='\n');
        printf("Enter Correct direction\n");
    }
    moving=direction;
	


   int result= can_I_move(dizi,moving,x,y);


    if(result==1){
        switch(moving){
            case right:

            move_to_the_right(dizi,x,y,&x1,&x2);
            finish=is_it_done(dizi);

             if(finish==1){
                    printf("Congrats\n");
                temp=0;
                break;
            }

        break;
    case left:
        move_to_the_left(dizi,x,y,&x1,&x2);
        finish=is_it_done(dizi);

        if(finish==1){

                printf("Congrats\n");
                temp=0;
                break;
            }
        break;

    case down:
        move_to_the_down(dizi,x,y,&x1,&x2);
        finish=is_it_done(dizi);

        if(finish==1){

                printf("Congrats\n");
                temp=0;
                break;
            }
        break;
    case up:
        move_to_the_up(dizi,x,y,&x1,&x2);
        finish=is_it_done(dizi);

        if(finish==1){
                printf("Congrats\n");
                temp=0;
                break;
            }
        break;
    default:
        printf("You have to enter from DOWN to UP\n");
    }

        }else{
        printf("You cannot move\n");
        }
    }
}
int main()
{
    play_game_and_choose_direction();



    return 0;
}
