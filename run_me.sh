#!/bin/bash

g++ sw.cpp -o test
./test
mkdir points
mv points.dat points/
cd points
split -l 100000 points.dat
cp ../rename.sh ./
cp ../render.sh ./
cp ../points_template.pov ./
