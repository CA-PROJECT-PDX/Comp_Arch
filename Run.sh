#!/bin/sh
filepath=$1
obj_file=$2
. ~/.bashrc
#echo "\nFiles present in given path are"
#ls -ltr /u/pmanthu/CA_PROJECT/BASE_CODE/Comp_Arch/${filepath}/
IFS=':'
for line in `ls ${filepath}/*mem|xargs|sed 's/ /:/g'`
do
filename1=`basename $line|sed 's/.mem$//g'`
echo "Triggering Mem file ${filename1}.mem"
./${obj_file} ip_file=${filepath}/${filename1}.mem |tee ${filepath}/../../OUTPUT_FILES/${filename1}_${obj_file}.out
done

