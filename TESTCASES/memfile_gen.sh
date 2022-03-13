#!/bin/sh
filename=$1
. ~/.bashrc
echo "\nThe object file content is"
rvas -ahld ${1}.s -o ${1}.o
echo "\n\nThe mem file content is"
rvobjdump -d ${1}.o|sed '1,7d'|cut -d'	' -f1,2 > ${1}.mem
cat ${1}.mem
