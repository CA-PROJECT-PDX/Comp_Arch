#!/bin/sh
#!/bin/bash
filepath=$1
. ~/.bashrc
echo "\nFiles present in given path are"
ls -ltr ${filepath}/
IFS=':'
for line in `ls ${filepath}/*s|xargs|sed 's/ /:/g'`
do
filename1=`basename $line|sed 's/.s$//g'`
echo "\nThe Object file content for ${filename1}.s is"
rvas -ahld -march=rv32i ${filepath}/${filename1}.s -o ${filepath}/../OBJ_FILES/${filename1}.o
echo "\nThe mem file content for ${filename1}.o is"
rvobjdump -d ${filepath}/../OBJ_FILES/${filename1}.o|sed '1,7d'|cut -d'	' -f1,2 > ${filepath}/../MEMFILES/${filename1}.mem
cat  ${filepath}/../MEMFILES/${filename1}.mem
done
