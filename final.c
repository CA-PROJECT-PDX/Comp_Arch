#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gpr_arr[32];
char mem_arr[65536];
//unsigned int pc=0xFFE8;
unsigned int pc;
int *pc_ptr;

char* params_final[3];

void params(char first_param[100],char sec_param[100],char third_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"ip_file="))
            for(int i=0;i<100;i++)
            fname[i]=first_param[i];
        else if(strstr(sec_param,"ip_file="))
            for(int i=0;i<100;i++)
            fname[i]=sec_param[i];
        else if(strstr(third_param,"ip_file="))
            for(int i=0;i<100;i++)
            fname[i]=third_param[i];

        if(strstr(first_param,"start_addr="))
            for(int i=0;i<100;i++)
            strt_addr[i]=first_param[i];
        else if(strstr(sec_param,"start_addr="))
            for(int i=0;i<100;i++)
            strt_addr[i]=sec_param[i];
        else if(strstr(third_param,"start_addr="))
            for(int i=0;i<100;i++)
            strt_addr[i]=third_param[i];

        if(strstr(first_param,"stack_addr="))
            for(int i=0;i<100;i++)
            stk_addr[i]=first_param[i];
        else if(strstr(sec_param,"stack_addr="))
            for(int i=0;i<100;i++)
            stk_addr[i]=sec_param[i];
        else if(strstr(third_param,"stack_addr="))
            for(int i=0;i<100;i++)
            stk_addr[i]=third_param[i];

        char* fname1=fname+8;
        //printf("fname1=%s\n",fname1);
                params_final[1]=fname1;

        char* strt_addr1=strt_addr+11;
        //printf("strt_addr1=%s\n",strt_addr1);
                params_final[2]=strt_addr1;

        char* stk_addr1=stk_addr+11;
        //printf("stk_addr1=%s\n",stk_addr1);
                params_final[3]=stk_addr1;

}

void one_params(char first_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"ip_file=")){
                                for(int i=0;i<100;i++)
                                fname[i]=first_param[i];
                        char* strt_addr1="0";
                        char* stk_addr1="65535";
                        char* fname1=fname+8;
                        params_final[1]=fname1;
                        params_final[2]=strt_addr1;
                        params_final[3]=stk_addr1;
                        }
        else if(strstr(first_param,"start_addr=")){
                for(int i=0;i<100;i++)
                                strt_addr[i]=first_param[i];
                        char* fname1="tracefile.txt";
                        char* stk_addr1="65535";
                        char* strt_addr1=strt_addr+11;
                        params_final[1]=fname1;
                        params_final[2]=strt_addr1;
                        params_final[3]=stk_addr1;
                        }
        else if(strstr(first_param,"stack_addr=")){
                for(int i=0;i<100;i++)
                                stk_addr[i]=first_param[i];
                        char* fname1="tracefile.txt";
                        char* strt_addr1="0";
                        char* stk_addr1=stk_addr+11;
                        params_final[1]=fname1;
                        params_final[2]=strt_addr1;
                        params_final[3]=stk_addr1;
                        }

}

void two_params(char first_param[100],char sec_param[100]){
        char fname[100],strt_addr[100],stk_addr[100];
        if(strstr(first_param,"ip_file=")){
                                for(int i=0;i<100;i++)
                                fname[i]=first_param[i];
                        if(strstr(sec_param,"start_addr=")){
                for(int i=0;i<100;i++)
                strt_addr[i]=sec_param[i];
                                char* stk_addr1="65535";
                                char* fname1=fname+8;
                                char* strt_addr1=strt_addr+11;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
            else if(strstr(sec_param,"stack_addr=")){
                for(int i=0;i<100;i++)
                stk_addr[i]=sec_param[i];
                                char* strt_addr1="0";
                                char* fname1=fname+8;
                                char* stk_addr1=stk_addr+11;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
                        }
                        else if(strstr(first_param,"start_addr=")){
                                for(int i=0;i<100;i++)
                                strt_addr[i]=first_param[i];
                        if(strstr(sec_param,"ip_file=")){
                for(int i=0;i<100;i++)
                fname[i]=sec_param[i];
                                char* stk_addr1="65535";
                                char* strt_addr1=strt_addr+11;
                                char* fname1=fname+8;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
            else if(strstr(sec_param,"stack_addr=")){
                for(int i=0;i<100;i++)
                stk_addr[i]=sec_param[i];
                                char* fname1="tracefile.txt";
                                char* strt_addr1=strt_addr+11;
                                char* stk_addr1=stk_addr+11;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
                        }
                        else if(strstr(first_param,"stack_addr=")){
                                for(int i=0;i<100;i++)
                                stk_addr[i]=first_param[i];
                        if(strstr(sec_param,"ip_file=")){
                for(int i=0;i<100;i++)
                fname[i]=sec_param[i];
                                char* strt_addr1="0";
                                char* fname1=fname+8;
                                char* stk_addr1=stk_addr+11;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
            else if(strstr(sec_param,"start_addr=")){
                for(int i=0;i<100;i++)
                strt_addr[i]=sec_param[i];
                                char* fname1="tracefile.txt";
                                char* stk_addr1=stk_addr+11;
                                char* strt_addr1=strt_addr+11;
                                params_final[1]=fname1;
                                params_final[2]=strt_addr1;
                                params_final[3]=stk_addr1;
                                }
                        }
}


void BEQ(int imm,int rs1,int rs2){
        if(gpr_arr[rs1] == gpr_arr[rs2]){
                if(imm>>12 == 0) pc += (imm & 4095);
                else pc -= (imm & 4095);
        }
        else
                pc += 4;
}

void BNE(int imm,int rs1,int rs2){
        if(gpr_arr[rs1] != gpr_arr[rs2]){
                if(imm>>12 == 0) pc += (imm & 4095);
                else pc -= (imm & 4095);
        }
        else
                pc += 4;
}

void ADD (int rd,int rs1,int rs2){
printf("\n old contents in gpr are rd=%x,rs1=%x,rs2=%x",gpr_arr[rd],gpr_arr[rs1],gpr_arr[rs2]);

gpr_arr[rd]=gpr_arr[rs1]+gpr_arr[rs2];

printf("\n new contents in gpr are rd=%x,rs1=%x,rs2=%x",gpr_arr[rd],gpr_arr[rs1],gpr_arr[rs2]);
}

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

void parse_inst_1(char unsigned inst[32])
{
    unsigned long int i,a,b;
    int unsigned arr[7];
    printf("Inside parse_inst function for inst: %s",inst);
    for(i=0; i<32; i++)
    {
        printf("%d",inst[i]);
    }
    printf("\n");

    if(inst[1]==1)
    {
        printf("ONE");
    }

    //a = 11111111111111111111111111111111;
    a = 4294967295;
    printf("a = %lu", a);
    b = 3;
    printf("b = %lu", b<<2);
    b = 3;
    b = b+b;
    printf("b = %lu", b);
}

void parse_inst_2(unsigned long int addr, unsigned long int inst)
{
    unsigned long int mask, opcode, funct3, funct7, rs1, rs2, rd, shamt, imm, imm1, imm2;
    unsigned long int im1, im2, im3;
    int pc_flag=0;
    if(addr%4 != 0) //TODO remove this check
    {
        printf("\nINVALID ADDRESS\n");
    } else {
        mask = 127; //7'b111_1111 --> Checking opcode
        opcode = mask & inst;
        printf("\ninst = %lu", inst);
        //printf("\ninst = %lu, mask = %lu, opcode = %lu", inst, mask, opcode);
        printf("\n");

        switch(opcode) {
            case 51 : //OPCODE == 0110011
                printf("R type instruction\n" );

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 32505856; //    --> Checking rs2
            rs2 = mask & inst;
            rs2 = rs2>>20;

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4261412864; //32'b1111111000000..00 --> checking funct7
            funct7 = mask & inst;
            funct7 = funct7 >> 25;

            printf("rs1 = %lu, rs2 = %lu, rd = %lu", rs1, rs2, rd);
            printf("funct3 = %lu\n", funct3);
            printf("funct7 = %lu\n", funct7);

            switch(funct3){

                case 0: // ADD or SUB
                    if(funct7 == 0)
                    {
                        printf("Calling ADD function");
                        ADD(rd, rs1, rs2);
                    } else if (funct7 == 32)
                    {
                        printf("Calling SUB function");
                    } else
                    {
                        printf("Invalid instruction");
                    }
                    break;

                case 1: // SLL
                    printf("Calling SLL function");
                    break;

                case 2: // SLT
                    printf("Calling SLT function");
                    break;

                case 3: // SLTU
                    printf("Calling SLTU function");
                    break;

                case 4: // XOR
                    printf("Calling SLL function");
                    break;

                case 5: // SRL / SRA
                    if(funct7 == 0)
                    {
                        printf("Calling SRL function");
                    } else if (funct7 == 32)
                    {
                        printf("Calling SRA function");
                    } else
                    {
                        printf("Invalid instruction");
                    }
                    break;

                case 6: // OR
                    printf("Calling SLL function");
                    break;

                case 7: // AND
                    printf("Calling SLL function");
                    break;

                default:
                    printf("Invalid Instruction");
                                exit(0);
            }
                break;

            case 19 : //OPCODE == 0010011  // I-Type instruction

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 32505856; //    --> Checking shamt
            shamt = mask & inst;
            shamt = shamt >> 20;

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4261412864; //32'b1111111000000..00 --> checking funct7
            funct7 = mask & inst;
            funct7 = funct7 >> 25;

            mask = 4293918720; //32'b111111111111000..00 --> checking imm
            imm = mask & inst;
            imm = imm >> 20;

            printf("rs1 = %lu, shamt = %lu, rd = %lu", rs1, shamt, rd);
            printf("funct3 = %lu\n", funct3);
            printf("funct7 = %lu\n", funct7);
            printf("imm = %lu\n", imm);

            switch(funct3){

                case 0: //ADDI
                    printf("Calling ADDI function");
                    break;

                case 1: //SLLI
                    printf("Calling SLLI function");
                    break;

                case 2: //SLTI
                    printf("Calling SLTI function");
                    break;

                case 3: //SLTIU
                    printf("Calling SLTIU function");
                    break;

                case 4: //XORI
                    printf("Calling XORI function");
                    break;

                case 5: //SRLI or SRAI
                    if(funct7 == 0)
                    {
                        printf("Calling SRLI function");
                    } else if (funct7 == 32)
                    {
                        printf("Calling SRAI function");
                    } else
                    {
                        printf("Invalid instruction");
                    }
                    break;

                case 6: //ORI
                    printf("Calling ORI function");
                    break;

                case 7: //ANDI
                    printf("Calling ANDI function");
                    break;

                default:
                    printf("Invalid Instruction");
            }
                break;

            case 35 : //OPCODE == 0100011

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 32505856; //    --> Checking rs2
            rs2 = mask & inst;
            rs2 = rs2 >> 20;

            mask = 3968; //    --> Checking imm1
            imm1 = mask & inst;
            imm1 = imm1>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4261412864; //32'b1111111000000..00 --> checking imm2
            imm2 = mask & inst;
            imm2 = imm2 >> 25;

            imm2 = imm2<<5;
            imm = imm2 | imm1;

            printf("rs1 = %lu, rs2 = %lu, rd = %lu", rs1, rs2, rd);
            printf("funct3 = %lu\n", funct3);
            printf("funct7 = %lu\n", funct7);
            printf("imm = %lu\n", imm);

            switch(funct3){

                case 0: //SB
                    printf("Calling SB function");
                    break;

                case 1: //SH
                    printf("Calling SH function");
                    break;

                case 2: //SW
                    printf("Calling SW function");
                    break;

                default:
                    printf("Invalid Instruction");
            }
                break;

            case 3 : //OPCODE == 0000011

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4293918720; //32'b111111111111000..00 --> checking imm
            imm = mask & inst;
            imm = imm >> 20;

            //printf("rs1 = %lu, shamt = %lu, rd = %lu", rs1, shamt, rd);
            printf("funct3 = %lu\n", funct3);
            //printf("funct7 = %lu\n", funct7);
            printf("imm = %lu\n", imm);

            switch(funct3){

                case 0: //LB
                    printf("Calling LB function");
                    break;

                case 1: //LH
                    printf("Calling LH function");
                    break;

                case 2: //LW
                    printf("Calling LW function");
                    break;

                case 4: //LBU
                    printf("Calling LBU function");
                    break;

                case 5: //LHU
                    printf("Calling LHU function");
                    break;

                default:
                    printf("Invalid Instruction");
            }
                break;

            case 99 : //OPCODE == 1100011

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 32505856; //    --> Checking rs2
            rs2 = mask & inst;
            rs2 = rs2 >> 20;

            mask = 3968; //    --> Checking imm1
            imm1 = mask & inst;
            imm1 = imm1>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4261412864; //32'b1111111000000..00 --> checking imm2
            imm2 = mask & inst;
            imm2 = imm2 >> 25;

            im2 = imm2>>6; //12th bit
            im1 = imm1 & 1; //7th bit
            im3 = (im2 << 11) | (im1<<10) | ((imm2 & 63)<<4) | (imm1>>1);


            //imm2 = imm2<<5;
            imm = im3<<1;

            printf("rs1 = %lu, rs2 = %lu, rd = %lu", rs1, rs2, rd);
            printf("funct3 = %lu\n", funct3);
            printf("funct7 = %lu\n", funct7);
            printf("imm = %lu\n", imm);

            switch(funct3){

                case 0: //BEQ
                    printf("Calling BEQ function");
                                BEQ(imm, rs1, rs2);
                                pc_flag = 1;
                    break;

                case 1: //BNE
                    printf("Calling BNE function");
                    break;

                case 4: //BLT
                    printf("Calling BLT function");
                    break;

                case 5: //BGE
                    printf("Calling BGE function");
                    break;

                case 6: //BLTU
                    printf("Calling BLTU function");
                    break;

                case 7: //BGEU
                    printf("Calling BGEU function");
                    break;

                default:
                    printf("Invalid Instruction");
            }
                break;

            case 103 : //OPCODE == 1100111

            mask = 1015808; //    --> Checking rs1
            rs1 = mask & inst;
            rs1 = rs1>>15;

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 28672; //15'b111000000000000 --> checking funct3
            funct3 = mask & inst;
            funct3 = funct3>>12;

            mask = 4293918720; //32'b111111111111000..00 --> checking imm
            imm = mask & inst;
            imm = imm >> 20;

            //printf("rs1 = %lu, shamt = %lu, rd = %lu", rs1, shamt, rd);
            printf("funct3 = %lu\n", funct3);
            //printf("funct7 = %lu\n", funct7);
            printf("imm = %lu\n", imm);

            if(funct3 == 0)
            {
                printf("Calling JALR function");
            } else
            {
                printf("Invalid instruction");
            }
                break;

            case 111 : //OPCODE == 1101111

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 4294963200; //32'b11111111111111111111000000000000--> checking imm
            imm = mask & inst;
            imm = imm >> 12;

            im1 = imm >> 19; //20th bit
            im2 = (im1<<19) | ((imm & 255)<<11) | ((imm & 256)<<3) | ((imm & 523776)>>8);
            imm = im2<<1;
            printf("imm = %lu\n", imm);

            printf("Calling JAL instruction");
            break;

        case 23: //OPCODE == 0010111

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 4294963200; //32'b11111111111111111111000000000000--> checking imm
            imm = mask & inst;
            imm = imm >> 12;
            printf("imm = %lu\n", imm);

            printf("Calling AUIPC instruction");
            break;

        case 55: //OPCODE == 0110111

            mask = 3968; //    --> Checking rd
            rd = mask & inst;
            rd = rd>>7;

            mask = 4294963200; //32'b11111111111111111111000000000000--> checking imm
            imm = mask & inst;
            imm = imm >> 12;
            printf("imm = %lu\n", imm);

            printf("Calling LUI instruction");
            break;



            default :
                printf("Not R type instruction\n" );
        }
    }
    if(pc_flag==0)
    {
                pc += 4;
                pc_ptr = &pc;
                printf("\n\nPC incremented to %d  pc_ptr = %d\n\n", pc, *pc_ptr);
    }
        else
        {
                printf("\n\n New PC = %d", pc);
        }
}

int main(int argc, char *argv[])
{
    char unsigned instr[32];
    unsigned long int instr1;

                if(argc==1){
                char* first_param="ip_file=tracefile.txt";
                char* sec_param="start_addr=0";
                char* third_param="stack_addr=65535";
                params(first_param,sec_param,third_param);
        }
        else if(argc==2){
                char* first_param=argv[1];
				if(strstr(first_param,"ip_file=")){
					char* sec_param="start_addr=0";
					two_params(first_param,sec_param);
				}
				else
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
                char* fname;
        fname=params_final[1];
                pc=atoi(params_final[2]);
                gpr_arr[2]=atoi(params_final[3]);
                printf("\nfilename=%s ,starting address=%d ,stack address=%d\n",fname,pc,gpr_arr[2]);
        FILE *fp = fopen(fname, "r");
        char cr;
        size_t lines = 0;

                pc_ptr = &pc;
        while( cr != EOF ) {
        if ( cr == '\n' ) {
                lines++;
        }
        cr = getc(fp);
        }
        rewind(fp);

       // {
    char *data[lines];
    size_t n;
    char* addr[lines];
    char* inst[lines];
        //char hexvalue[8];
        char* inst_bin[lines];
        unsigned  int inst_dec[lines];
        unsigned  int addr_dec[lines];
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
        remove_extra_char(addr[i]);
         unsigned int decvalue=0;
        //inst_bin[i]=hextobin(inst[i],binvalue);
        inst_dec[i]=hextodec(inst[i],decvalue);
        addr_dec[i]=hextodec(addr[i],decvalue);
        printf("addr=%s, addr_dec=%u, inst=%s, inst_dec=%u \n",addr[i],addr_dec[i],inst[i],inst_dec[i]);
                //parse_inst_2(addr_dec[i], inst_dec[i]);
                printf("\n-------------------------------------------------------------------------------\n");
    }

        while(1){
                for(size_t i=0; i<lines; i++)
                {
                        if(addr_dec[i]%4 !=0 || addr_dec[i]>65535){
                        //Instruction address should always be word addressable, because each instruction is 4 bytes.
                        //Also, the maximum value the address can hold is 2^16 - 1 = 65535
                                printf("\nInvalid Address = %s\n", addr[i]);
                                exit(0);
                        }
                        if(pc%4 != 0 || pc > 65535){ //Same as above condition for pc (As PC is updated by the instructions)
                                printf("Invalid pc = %d", pc);
                                exit(0);
                        }
                        if(pc == addr_dec[i] && inst_dec[i]!=0x8067) //0x8067 represents "jr ra", which returns 0 --> Indicating end of the instruction set
                        {
                                parse_inst_2(addr_dec[i], inst_dec[i]);
                                printf("\n-------------------------------------------------------------------------------\n");
                        }
                        else if(pc == addr_dec[i] && inst_dec[i]==0x8067)
                        {
                                printf("\n End of Instructions\n");
                                exit(0);
                        }
                        else if(i == lines-1) //pc updated by instruction and the updated pc not found in instruction file
                        {
                                int pc_found = 0;
                                for(size_t i1=0; i1<lines; i1++)
                                {
                                        if(pc == addr_dec[i1]) pc_found = 1;
                                }
                                if(pc_found == 0)
                                {
                                        printf("\nPC = %d - not found in instruction address\n", pc); //TODO - print pc in hex
                                        exit(0);
                                }
                        }
                }
        }
        printf("Debug print 2");
  //}

        fclose(fp);
     return 0;
}

