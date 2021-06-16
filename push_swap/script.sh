#!/bin/bash
C="0"
while [[ $C -lt 13 ]]; do
	echo nope
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	C=$(./push_swap $ARG | wc -l)
done
echo $C
echo $ARG

