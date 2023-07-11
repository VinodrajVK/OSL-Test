#!/bin/bash
read -p "Enter a number:" num
n=$num
while((num>0))
do
    r=$((num%10))
    rnum=$((rnum*10+r))
    num=$((num/10))
done
if [ $rnum == $n ]
then
echo "The number is Palindrome"
else
echo "The number is not Palindrome"
fi
