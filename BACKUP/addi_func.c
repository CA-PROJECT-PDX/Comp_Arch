#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int gpr_arr[32];
char mem_arr[65536];

void addi_func(int rd,int rs1,int imm){
printf("\n contents in gpr are rd=%x,rs1=%x,imm=%x",gpr_arr[rd],gpr_arr[rs1],imm);

gpr_arr[rd]=gpr_arr[rs1]+imm;

printf("\n new contents in gpr are rd=%x,rs1=%x,imm=%x",gpr_arr[rd],gpr_arr[rs1],imm);
}

void load_func(int rd,int val){
printf("\n contents in gpr%d are rd=%x",rd,gpr_arr[rd]);

gpr_arr[rd]=val;

printf("\n new contents in gpr%d are rd=%x",rd,gpr_arr[rd]);
}

int main(){
int rs1=0,rs2=0,rd=0,imm=10;

printf("\n rs1=%d,rs2=%d,rd=%d,imm=%d",rs1,rs2,rd,imm);

load_func(1,12);
load_func(2,14);
load_func(3,18);

addi_func(3,1,imm);

}

