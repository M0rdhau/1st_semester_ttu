#!/bin/bash

somepath=http://upload.itcollege.ee/~aleksei/random_files_without_extension.zip
somefile=random_files_without_extension.zip

echo "this will download Aleksei's files and unzip them"
read -p "download from default location? type yes for yes: " yesno
if [[ $yesno =~ ^y|yes|YES|Y ]]; then
	echo "alrighty then"
else
	echo "Seeing as this is a very narrow program, we should continue to use our proprietary locations"
	echo "we will assume that you pressed yes"
	sleep 2
fi
	


wget $somepath

unzip $somefile

cd random_files


FILES=./*

mkdir JPEGs

for f in $FILES

do
	VAR1=$(file $f)
	if [[ $VAR1 == *": JPEG"* ]]; then
		cp $f JPEGs${f:1}.jpeg
	fi
done