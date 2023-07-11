#!/bin/bash
declare -A X
declare -A Y
declare -A Z
echo "Enter X:"
for((i=0;i<2;i++))
do
for((j=0;j<2;j++))
do
read X[$i,$j]
done
done
echo "Enter Y:"
for((i=0;i<2;i++))
do
for((j=0;j<2;j++))
do
read Y[$i,$j]
done
done
echo "X is:"
for((i=0;i<2;i++))
do
for((j=0;j<2;j++))
do
echo -ne "${X[$i,$j]}  "
done
echo
done
echo "Y is:"
for((i=0;i<2;i++))
do
for((j=0;j<2;j++))
do
echo -ne "${Y[$i,$j]}  "
done
echo
done
echo "Sum:"
for((i=0;i<2;i++))
do
for((j=0;j<2;j++))
do
Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
echo -ne "${Z[$i,$j]}  "
done
echo
done