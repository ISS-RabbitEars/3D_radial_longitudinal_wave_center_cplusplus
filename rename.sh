#!/bin/bash

k=0
for i in {a..h}
do
	for j in {a..z}
	do
		echo x${i}${j}
		k=$((${k}+1))
		echo ${k}
		mv x${i}${j} points_${k}
	done
done

for i in {a..b}
do
	echo xi${i}
	k=$((${k}+1))
	echo ${k}
	mv xi${i} points_${k}
done

