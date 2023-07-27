#!/bin/sh
for i in $(find -name "Makefile"); do make clean -C ${i%/*}; done
