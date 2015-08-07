#!/bin/bash
#result=0
yes 5 | qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq > result
cat result
answer=`awk -F': ' '{ print $2 }' result`
if [ $answer -eq 5 ]
then
	echo "correct!!"
else
	echo "not correct."
fi

yes 9 | qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq > result
cat result
answer=`awk -F': ' '{ print $2 }' result`
if [ $answer -eq 34 ]
then
	echo "correct!!"
else
	echo "not correct."
fi

yes 25 | qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq > result
cat result
answer=`awk -F': ' '{ print $2 }' result`
if [ $answer -eq 75025 ]
then
	echo "correct!!"
else
	echo "overflow!!"
fi


yes 46 | qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq > result
cat result
answer=`awk -F': ' '{ print $2 }' result`
if [ $answer -eq 1836311903 ]
then
	echo "correct!!"
else
	echo "overflow!!"
fi

