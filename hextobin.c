#include<stdio.h>
#include<string.h>

void hextobin(char hexvalue[8])
{
int i=0;
char binvalue[32]="";
	while(hexvalue[i])
	{
		switch(hexvalue[i])
		{
			case '0' : strcat(binvalue,"0000");
				break;
			case '1' : strcat(binvalue,"0001");
				break;
			case '2' : strcat(binvalue,"0010");
				break;
			case '3' : strcat(binvalue,"0011");
				break;
			case '4' : strcat(binvalue,"0100");
				break;
			case '5' : strcat(binvalue,"0101");
				break;
			case '6' : strcat(binvalue,"0110");
				break;
			case '7' : strcat(binvalue,"0111");
				break;
			case '8' : strcat(binvalue,"1000");
				break;
			case '9' : strcat(binvalue,"1001");
				break;
			case 'A' : strcat(binvalue,"1010");
				break;
			case 'B' : strcat(binvalue,"1011");
				break;
			case 'C' : strcat(binvalue,"1100");
				break;
			case 'D' : strcat(binvalue,"1101");
				break;
			case 'E' : strcat(binvalue,"1110");
				break;
			case 'F' : strcat(binvalue,"1111");
				break;
			case 'a' : strcat(binvalue,"1010");
				break;
			case 'b' : strcat(binvalue,"1011");
				break;
			case 'c' : strcat(binvalue,"1100");
				break;
			case 'd' : strcat(binvalue,"1101");
				break;
			case 'e' : strcat(binvalue,"1110");
				break;
			case 'f' : strcat(binvalue,"1111");
				break;
			default : printf("\nInvalid Entry, Please Try Again  %c",hexvalue[i]);
		}
		i++;
	}
	printf("%s",binvalue);
}

int main()
{
    char hexvalue[8];
	
	printf("Enter Hex value:");
        scanf("%s",hexvalue);
        printf("Binary value:");
        hextobin(hexvalue);
        printf("\n");
}
