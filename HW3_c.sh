#!/bin/bash
gcc -std=c99 -o activity activity.c 
./activity > my_results.txt
./activity
echo
echo "Solution"
echo
cat solution.txt
echo
diff -y -B -b --report-identical-files --suppress-common-lines my_results.txt solution.txt
echo

