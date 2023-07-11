#!/bin/bash
echo "Enter three numbers "
read a b c
larg=$a
if [ $b -gt $larg ]
then 
larg=$b
fi
if [ $c -gt $larg ]
then 
larg=$c
fi
echo "Largest : $larg"