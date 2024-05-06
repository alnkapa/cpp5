#!/bin/bash

# mkdir -p build
#cd build
# rm -rf *
cmake .. -DCMAKE_INSTALL_PREFIX=~
cmake --build .
cmake --build . --target=test
cat ../ip_filter.tsv | ./ip_filter  | cat > ../rez.txt |  cat  ../rez.txt | md5sum | cat > ../hash.md5
