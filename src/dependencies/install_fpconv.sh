#!/bin/bash
for f in ./fpconv/src/*
do
    cp ./fpconv/license copyright
    sed -i '1s/^/\/*\n\n/' copyright
    echo $'\n*/\n' >> copyright
    cat $f >> copyright
    rm $f
    mv copyright $f
done
mv ./fpconv/src ./tmp
rm -R -f ./fpconv
mv ./tmp ./fpconv
