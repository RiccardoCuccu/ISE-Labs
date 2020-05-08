#!/bin/bash

n=`grep "VERSION " version.h | cut -d " " -f 3`
# n=$(grep "VERSION " version.h | cut -d " " -f 3)
n=$((n+1))
sed -i "s/VERSION .*/VERSION $n/" version.h
