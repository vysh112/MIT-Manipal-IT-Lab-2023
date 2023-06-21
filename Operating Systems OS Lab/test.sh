#!/bin/sh
#Using -d option we are checking whether the first argument is a directory or not.
#$1 refers to the first argument
if [ -d $1 ]
then
        echo "The provided argument is the directory."
#Using -f option we are checking whether the first argument is a file or not.
elif [ -f $1 ]
then
        echo "The provided argument is the file."
#if the provided argument is not file and directory then it does not exist on the system.   
else
        echo "The given argument does not exist on the file system."
fi
