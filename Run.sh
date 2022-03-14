#!/bin/sh
filepath=$1
. ~/.bashrc
echo "\nFiles present in given path are"
ls -ltr /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/${filepath}/
IFS=':'
for line in `ls /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/${filepath}/*mem|xargs|sed 's/ /:/g'`
do
filename1=`basename $line|sed 's/.mem$//g'`
echo"Triggering mem file ${filename1}.mem"
./main ip_file=/u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/${filepath}/${filename1}.mem |tee /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/OUTPUT_FILES/${filename1}.out
done

