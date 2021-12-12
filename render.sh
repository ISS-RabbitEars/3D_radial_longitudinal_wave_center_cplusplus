#!/bin/sh

for i in {1..210}
do
	mv points_${i} temp.dat
	cp points_template.pov frame_${i}.pov
   	povray -V +A0.0 +H1200 -J +R5 +W1600 frame_${i}.pov
   	rm -f frame_${i}.pov
   	rm -f temp.dat
done
