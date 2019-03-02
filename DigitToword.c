#include<stdio.h>
#include<string.h>

int main(){

	const char *strings[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen"
			"eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand"};
	int number=310,digit;
	printf("Enter the number ==\n");
	scanf("%d",&number);
	int sum=0;
	int temp=number,length=0,oldlenght=0;
	while(temp>0){
		temp=temp/10;
		length++;
	}
	oldlenght=length;
	while(length>0){
		//       printf("%d\n",length);
		switch (length){

		case 1:
			if(number>0)
				printf("%s\n",strings[number]);

			break;
		case 2:
			if(number>0){
				digit=number/10;
				//			printf("digit deci== %d\n",digit);
				if(digit>1){
					sum+=strlen(strings[digit-1])+strlen(strings[digit+18]);
					printf("%s",strings[digit-1+18]);
					;
				}else{
                    if(number%10>0){
                    	printf(" %s\n",strings[digit-1+(number%10)+10]);
                    }else{
                    	printf("%s\n",strings[digit-1+10]);
                    }

					length=0;
				}
				number=number%10;
			}
			break;
		case 3:
			digit=number/100;
			//			printf("digit +++ %d\n",digit);
			sum+=strlen("hundred")+strlen(strings[digit]);
			printf("%s hundred ",strings[digit]);
			number=number%100;
			if(number>0)
			  printf(" and ");

			break;
		case 4:
			digit=number/1000;
			//			printf("digit== %d\n",digit);
			sum+=strlen("thousand")+strlen(strings[digit]);
			printf("%s thousand ",strings[digit]);
			number=number%1000;
			break;
		}
		length--;
	}
	printf("\n");
	//	printf("%s,%d ,%d\n",strings[15],length,digit);
}
