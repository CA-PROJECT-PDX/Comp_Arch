#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int gpr_arr[32];
char mem_arr[65536];

void add_func(int rd,int rs1,int rs2){
printf("\n contents in gpr are rd=%x,rs1=%x,rs2=%x",gpr_arr[rd],gpr_arr[rs1],gpr_arr[rs2]);

gpr_arr[rd]=gpr_arr[rs1]+gpr_arr[rs2];

printf("\n new contents in gpr are rd=%x,rs1=%x,rs2=%x",gpr_arr[rd],gpr_arr[rs1],gpr_arr[rs2]);
}

void load_func(int rd,int val){
printf("\n contents in gpr%d are rd=%x",rd,gpr_arr[rd]);

gpr_arr[rd]=val;

printf("\n new contents in gpr%d are rd=%x",rd,gpr_arr[rd]);
}

int main(){
int rs1=0,rs2=0,rd=0;

printf("\n rs1=%d,rs2=%d,rd=%d",rs1,rs2,rd);

load_func(1,12);
load_func(2,14);
load_func(3,18);

add_func(3,1,2);

}

