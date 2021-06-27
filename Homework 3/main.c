#include <stdio.h>

void calculate_fibonacci_sequence(){
	int n,number1=1,number2=1,result=0;
	int temp=0;
	int temp1=1;
	char karakter='*',tc;
	int result1=0;
	   
    while(temp1){
		printf("Please enter term(s) number: ");
        if(scanf("%d",&n)!=1){
            
            scanf(" %c",&tc);
           
            if(tc == '*'){
				break;
			}
            	
            else if(tc == '+'){
			printf("See youu \n");
            	continue;
			}
            	
            else{
            	printf("Please Enter ""numeric"" value\n");
            	continue;
			}
        }
		else if(n>0){
	        printf("You entered: %d\n",n);
    		printf("Fibonacci Sequence:\n");   
    		while(temp<n){
        		result1=number1+result;
        		printf("%d\n",result1);
        		number1=result;
        		result=result1;
        		temp++;
    		}
		
	    }
		else if(n<0){
	        printf("Please enter ""positive"" term(s) number\n");
	    }
	    n=0;
		result1=0;
		number1=1;
		result=0;
		temp=0;
        while(getchar() != '\n');
		
    }
   
}

void decide_perfect_harmonic_number(){
int number;
int i=0;
int result=0;
int count=0;
int count1=0;
printf("Please enter input number\n");
scanf("%d",&number);
if(number<0){
    printf("Please positive\n");
}else{
    //This for is useful to find perfect number
    printf("Natural Number Divisors ");
    for(i=1;i<=number;i++){
        if(i!=number&&number%i==0){
            result+=i;
            count++;
            printf("%d,",i);
        }
        if(i==number){
            count++;
            printf("%d",i);
        }
    }
    printf("\n");
    printf("Is Perfect Number? :");
    if(result==number){
        printf("Yes");
    }else{
    printf("No");
    }
    printf("\n");
    i=1;
   double result1=0;
    while(i<=number){
        if(number%i==0){
            result1+=(double)1/i;
            count1++;
        }
        i++;
    }
    double result3=(double)count1/result1;
    int result2=(int)((double)count1/result1);
    printf("Is Harmonic Divisor Number? :");
    double subtract=result3-(double)result2;
    //printf("Fark %lf\n",subtract);
    if(subtract<0.00001){
        printf("Yes\n");
    }else if(subtract>=0.0000001){
        printf("No");
    }
    printf("\n");

}


}
void difference_max_min (){
    int temp=0;
    double max,min;
    double numbers;
    printf("Please Enter 5 numbers\n");
    scanf("%lf",&numbers);
    max=numbers;
    min=numbers;
    
    while(temp<4){
        scanf("%lf",&numbers);
        if(numbers>max){
            max=numbers;
        }if(min>numbers){
            min=numbers;
        }
        temp++;
    }
    printf("Max %.3lf\n",max);
printf("Min %.3lf\n",min);
printf("%.3lf\n",max-min);
}
void bmi_calculation (){
printf("Please enter height\n");
double height,weight;
double Bmi;
int status=scanf("%lf",&height);
if(height<0){
    printf("Please Positive\n");
}else{
    printf("Please enter weight\n");
    scanf("%lf",&weight);
    if(weight<0){
        printf("Please positive\n");
    }else{
    Bmi=weight/(height*height);
    }
}
printf("%.2lf\n",Bmi);
if(Bmi<16.0){
    printf("Your category : Severely Underweight\n");
}else if(Bmi>16&&Bmi<18.49999){
   printf("Your category : Underweight\n");
}else if(Bmi>18.5&&Bmi<=24.9999){
   printf("Your category : Normal\n");
}else if(Bmi>25&&Bmi<=29.99999){
   printf("Your category : Owerweight\n");
}else{
   printf("Your category : Obese\n");
}
}
int main()
{
calculate_fibonacci_sequence();	//Part 1
decide_perfect_harmonic_number();//Part 2	
difference_max_min (); //Part 3
bmi_calculation ();//Part 4
    return 0;
}
