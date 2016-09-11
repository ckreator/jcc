#!/bin/bash

# run something for me
# remove temporary files
rm -rf bin/* tmp/*
# recompile and run
make && ./bin/jcc
