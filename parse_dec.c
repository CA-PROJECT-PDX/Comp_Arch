#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <math.h>

 unsigned int hextodec(char hexvalue[8], unsigned int decvalue){

    int place;
    int i = 0, val, len;

    decvalue = 0;
    place = 1;

    len = strlen(hexvalue);
    len--;

    for(i=0; hexvalue[i]!='\0'; i++)
    {
 
        if(hexvalue[i]>='0' && hexvalue[i]<='9')
        {
            val = hexvalue[i] - 48;
        }
        else if(hexvalue[i]>='a' && hexvalue[i]<='f')
        {
            val = hexvalue[i] - 97 + 10;
        }
        else if(hexvalue[i]>='A' && hexvalue[i]<='F')
        {
            val = hexvalue[i] - 65 + 10;
        }

        decvalue += val * pow(16, len);
        len--;
    }
	return decvalue;

}

char *hextobin(char hexvalue[8],char binvalue[32])
{
int i=0;

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
        //printf("%s",binvalue);
                return binvalue;
}

char *remove_white_spaces(char *str)
{
        int i = 0, j = 0;
        while (str[i])
        {
                if (str[i] != ' ')
          str[j++] = str[i];
                i++;
        }
        str[j] = '\0';
        return str;
}

char *remove_extra_char(char *str)
{
        int i = 0, j = 0;
        while (str[i])
        {
                if (str[i] != '\n')
          str[j++] = str[i];
                i++;
        }
        str[j] = '\0';
        return str;
}


int main(int argc, char *argv[])
{
        char* fname;
        fname=argv[1];
        FILE *fp = fopen(fname, "r");
        char cr;
        size_t lines = 0;

        while( cr != EOF ) {
        if ( cr == '\n' ) {
                lines++;
        }
        cr = getc(fp);
        }
        rewind(fp);

        {
    char *data[lines];
    size_t n;
    char* addr[lines];
    char* inst[lines];
        //char hexvalue[8];
        char* inst_bin[lines];
	unsigned  int inst_dec[lines];
    char* token;
    for (size_t i = 0; i < lines; i++) {
      data[i] = NULL;
      size_t n = 0;

      getline(&data[i], &n, fp);
    }

    for (size_t i = 0; i < lines; i++) {
        remove_white_spaces(data[i]);
         //printf("%s", data[i]);
        addr[i] = strtok(data[i],":");

        inst[i] = strtok(NULL,":");
        remove_extra_char(inst[i]);
         unsigned int decvalue=0;
        //inst_bin[i]=hextobin(inst[i],binvalue);
		inst_dec[i]=hextodec(inst[i],decvalue);
        printf("addr=%s,inst=%s,inst_dec=%u \n",addr[i],inst[i],inst_dec[i]);
    }
        }

        fclose(fp);

        return 0;

}

