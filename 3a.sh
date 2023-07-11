#!/bin/bash
echo "Enter array elements"
read -a arr
echo ${arr[*]}
max=0
for i in ${arr[*]}
do
if [ $i -gt $max ]
then
max=$i
fi
done
echo "Max: $max"