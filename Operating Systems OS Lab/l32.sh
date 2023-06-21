#!/bin/sh
echo "ENter pattern"
read pattern
echo "Enter folder"
read folder
cd $folder
find . -name "*$pattern*"
