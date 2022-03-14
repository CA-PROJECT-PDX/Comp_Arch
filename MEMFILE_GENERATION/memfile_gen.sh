#!/bin/sh
#!/bin/bash
filepath=$1
. ~/.bashrc
echo "\nFiles present in given path are"
ls -ltr /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/${filepath}/
IFS=':'
for line in `ls /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/${filepath}/*s|xargs|sed 's/ /:/g'`
do
filename1=`basename $line|sed 's/.s$//g'`
echo "\nThe Object file content for ${filename1}.s is"
rvas -ahld /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/${filepath}/${filename1}.s -o /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/OBJ_FILES/${filename1}.o
echo "\nThe mem file content for ${filename1}.o is"
rvobjdump -d /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/OBJ_FILES/${filename1}.o|sed '1,7d'|cut -d'	' -f1,2 > /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/MEMFILES/${filename1}.mem
cat  /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/MEMFILE_GENERATION/MEMFILES/${filename1}.mem
done
