#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *params_final[3]=0;

void params(char first_param[100],char sec_param[100],char third_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"f="))
            for(int i=0;i<100;i++)
            fname[i]=first_param[i];
        else if(strstr(sec_param,"f="))
            for(int i=0;i<100;i++)
            fname[i]=sec_param[i];
        else if(strstr(third_param,"f="))
            for(int i=0;i<100;i++)
            fname[i]=third_param[i];

        if(strstr(first_param,"a="))
            for(int i=0;i<100;i++)
            strt_addr[i]=first_param[i];
        else if(strstr(sec_param,"a="))
            for(int i=0;i<100;i++)
            strt_addr[i]=sec_param[i];
        else if(strstr(third_param,"a="))
            for(int i=0;i<100;i++)
            strt_addr[i]=third_param[i];

        if(strstr(first_param,"s="))
            for(int i=0;i<100;i++)
            stk_addr[i]=first_param[i];
        else if(strstr(sec_param,"s="))
            for(int i=0;i<100;i++)
            stk_addr[i]=sec_param[i];
        else if(strstr(third_param,"s="))
            for(int i=0;i<100;i++)
            stk_addr[i]=third_param[i];

        char* fname1=fname+2;
        //printf("fname1=%s\n",fname1);
		params_final[1]=fname1;

        char* strt_addr1=strt_addr+2;
        //printf("strt_addr1=%s\n",strt_addr1);
		params_final[2]=strt_addr1;

        char* stk_addr1=stk_addr+2;
        //printf("stk_addr1=%s\n",stk_addr1);
		params_final[3]=stk_addr1;

}

void one_params(char first_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"f=")){
				for(int i=0;i<100;i++)
				fname[i]=first_param[i];
			char* strt_addr1="0";
			char* stk_addr1="65535";
			char* fname1=fname+2;
			params_final[1]=fname1;
			params_final[2]=strt_addr1;
			params_final[3]=stk_addr1;
			}
        else if(strstr(first_param,"a=")){
                for(int i=0;i<100;i++)
				strt_addr[i]=first_param[i];
			char* fname1="tracefile.txt";
			char* stk_addr1="65535";
			char* strt_addr1=strt_addr+2;
			params_final[1]=fname1;
			params_final[2]=strt_addr1;
			params_final[3]=stk_addr1;
			}	
        else if(strstr(first_param,"s=")){
                for(int i=0;i<100;i++)
				stk_addr[i]=first_param[i];
			char* fname1="tracefile.txt";
			char* strt_addr1="0";
			char* stk_addr1=stk_addr+2;
			params_final[1]=fname1;
			params_final[2]=strt_addr1;
			params_final[3]=stk_addr1;
			}

}

void two_params(char first_param[100],char sec_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"f=")){
				for(int i=0;i<100;i++)
				fname[i]=first_param[i];
			if(strstr(sec_param,"a=")){
                for(int i=0;i<100;i++)
                strt_addr[i]=sec_param[i];
				char* stk_addr1="65535";
				char* fname1=fname+2;
				char* strt_addr1=strt_addr+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
            else if(strstr(sec_param,"s=")){
                for(int i=0;i<100;i++)
                stk_addr[i]=sec_param[i];
				char* strt_addr1="0";
				char* fname1=fname+2;
				char* stk_addr1=stk_addr+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
			}
			else if(strstr(first_param,"a=")){
				for(int i=0;i<100;i++)
				strt_addr[i]=first_param[i];
			if(strstr(sec_param,"f=")){
                for(int i=0;i<100;i++)
                fname[i]=sec_param[i];
				char* stk_addr1="65535";
				char* strt_addr1=strt_addr+2;
				char* fname1=fname+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
            else if(strstr(sec_param,"s=")){
                for(int i=0;i<100;i++)
                stk_addr[i]=sec_param[i];
				char* fname1="tracefile.txt";
				char* strt_addr1=strt_addr+2;
				char* stk_addr1=stk_addr+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
			}
			else if(strstr(first_param,"s=")){
				for(int i=0;i<100;i++)
				stk_addr[i]=first_param[i];
			if(strstr(sec_param,"f=")){
                for(int i=0;i<100;i++)
                fname[i]=sec_param[i];
				char* strt_addr1="0";
				char* fname1=fname+2;
				char* stk_addr1=stk_addr+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
            else if(strstr(sec_param,"a=")){
                for(int i=0;i<100;i++)
                strt_addr[i]=sec_param[i];
				char* fname1="tracefile.txt";
				char* stk_addr1=stk_addr+2;
				char* strt_addr1=strt_addr+2;
				params_final[1]=fname1;
				params_final[2]=strt_addr1;
				params_final[3]=stk_addr1;
				}
			}
}

int main(int argc, char* argv[]){

        if(argc==1){
                char* first_param="f=tracefile.txt";
                char* sec_param="a=0";
                char* third_param="s=65535";
                params(first_param,sec_param,third_param);
        }
        else if(argc==2){
                char* first_param=argv[1];
                one_params(first_param);
        }
        else if(argc==3){
                char* first_param=argv[1];
                char* sec_param=argv[2];
                two_params(first_param,sec_param);
        }
        else {
                char* first_param=argv[1];
                char* sec_param=argv[2];
                char* third_param=argv[3];
                params(first_param,sec_param,third_param);
        }
		
		printf("\nfilename=%s ,starting address=%d ,stack address=%d\n",params_final[1],atoi(params_final[2]),atoi(params_final[3]));
		
        return 0;
}

