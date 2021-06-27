#include <stdio.h>
#include <math.h>
void prime_numbers(){
    int first_int,second_int;
    printf("Please Enter First Integer Number\n");
	 while(scanf("%d",&first_int)!=1||first_int<0.0000){
			while(getchar()!='\n');
        printf("Enter numeric number\n");
    }
    printf("Please Enter Second Integer Number\n");
	 while(scanf("%d",&second_int)!=1||second_int<0.0000){
			while(getchar()!='\n');
        printf("Enter numeric number\n");
    }

    int i,j,count=0;
    int result=0;
    int temp;
    if(first_int<=second_int){
        for(i=first_int;i<second_int;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                count++;
            }else{
                count++;
                count--;
            }
        }
        if(count==0&&i!=1){
            result+=i;
        }
        count=0;
    }
    printf("Sum of prime numbers between %d and %d:%d\n",first_int,second_int,result);
    }else{
        temp=first_int;
        first_int=second_int;
        second_int=temp;
           for(i=first_int;i<second_int;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                count++;
            }else{
                count++;
                count--;
            }
        }
        if(count==0&&i!=1){
            result+=i;
        }
        count=0;
    }
    printf("Sum of prime numbers between %d and %d:%d\n",first_int,second_int,result);

    }

}
int is_armstrong(int sayi){
    int count=0,temp,temp2,temp1,result=0;
    int numDigits=0;
    temp=sayi;
    temp2=sayi;
    do{
    ++numDigits;
    temp=temp/10;
} while(temp);

    while(sayi!=0){
        temp1=sayi%10;
        sayi=sayi/10;
        count+=pow(temp1,numDigits);
    }
    int flag=0;

    if(temp2==count){
        flag=1;
    }else{
    flag=0;
    }

    return flag;
}
int is_palindrome(int number){
int result=0,temp1,temp2,flag=0;
temp1=number;
while(number!=0){
    temp2=number%10;
    result=(result*10)+temp2;
    number=number/10;
}
if(temp1==result){
    flag=1;
}else{
    flag=0;
}
return flag;
}
void our_polindrom_armstrong(){
    int number;
    printf("Please enter an integer number\n");
	 while(scanf("%d",&number)!=1||number<0.0000){
			while(getchar()!='\n');
        printf("Enter numeric number\n");
    }
    int a,b;
    a=is_palindrome(number);
    b=is_armstrong(number);
    if(a==1&&b==1){
        printf("This number is both Palindrome and Armstrong number\n");
    }else if(a==1&&b==0){
        printf("This number is only Palindrome number\n");
    }else if(a==0&&b==1){
        printf("This number is only Armstrong number\n");
    }else{
        printf("This number does not satisfy any special cases\n");
    }
}
double module(double n){
	while(n>=1)n--;
	return n;
}
double round(double num){
	double temp = num;
	num = module(num);
	if(num >0.5)temp = ceil(temp);
	else temp = floor(temp);
	return temp;
}

void write_polynomial_equation(int coefficients){
int i,j;
double value,value1;
int value2;
int temp1;
printf("Enter your coefficients\n");
    for(j=coefficients;j>=0;j--){
        scanf(" %lf",&value);

        int flag = 0;
        if(value <=0){
        	flag = 1;
        	value*=-1;
		}
        value*=10;
        value = round(value);
        value/=10;
        if(flag == 1)
        	value*=-1;
        //printf("Yii %lf\t",value);
		if(value==0.0000){

		}else if(value==1.0000&&j>1){
				temp1=value;
				printf("+x^%d",j);
		}
		else if(value==-1.000000&&j>1){
				temp1=value;
				printf("-x^%d",j);
		}
		else if(value==1.000000&&j==1){
			temp1=value;
			printf("+x ");
		}
		else if(value==-1.0000&&j==1){
			temp1=value;
			printf("-x ");
		}
		else if(value==-1.0000&&j==0){
			temp1=value;
			printf("%+d ",temp1);
		}
		else if(value==-1.0000&&j==0){
			temp1=value;
			printf("%+d ",temp1);
		}

		else if(j==1&&(value!=1.000000||value!=-1.000000))
				printf("%+.1fx",value);
		else if(j==0&&(value==1.000000||value==-1.00000)){
		temp1=value;
		printf("%+d ",temp1);
		}
		else if(j==0&&(value!=1.000000||value==-1.00000)){
		printf("%+.1f ",value);
		}
		else if(j!=0){ //Diğer Kalanlar
			printf("%+.1fx^%d ",value,j);
		}
}
}
int main(){

	int katsayi;
   printf("Enter number\n");
    while(scanf("%d",&katsayi)!=1||katsayi<0.0000){

			while(getchar()!='\n');
        printf("Enter numeric number\n");
    }
    write_polynomial_equation(katsayi);
    printf("\n");
    our_polindrom_armstrong();
    prime_numbers();

    return 0;
}
