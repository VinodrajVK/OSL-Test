#!/bin/bash
echo "Enter the range M and N" 
read m n
echo "Prme numbers in the range $m to $n are"
for((i=m;i<=n;i++))
do
    flag=0
    for((j=2;j<=$((i/2));j++))
    do
        if [ $((i%j)) == 0 ]
        then 
        flag=1
        break
        fi
    done
    if [ $flag == 0 ]
        then echo -ne "$i "
    fi
done
