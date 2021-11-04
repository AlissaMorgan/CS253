#!/bin/sh
echo "Directory of file?"
read inputDirectory
echo "file name?"
read fileName
echo "command to test?"
read commands
cd $inputDirectory
rm -rf testdir
mkdir testdir
cd testdir
tar -xvf ../$fileName.tar
rm -f $fileName
cmake . && make
echo "$($commands)"
cd ..

