#!/bin/bash
if [ $# -eq 0 ]; then
echo "Usage:"
  echo "$0 filename.c -> Compiles/Creates Bin Files & Runs the Program"
  echo "$0 clean -> Cleans Bin Files"
  echo "$0 gen_test -> Generates Test Cases"
  exit 1
fi
if [ "$1" == "-h" ]; then
  echo "Usage:"
  echo "$0 filename.c -> Compiles/Creates Bin Files & Runs the Program"
  echo "$0 clean -> Cleans Bin Files"
    echo "$0 gen_test -> Generates Test Cases"
  exit 1
elif [ "$1" == "--help" ]; then
  echo "Usage:"
  echo "$0 filename.c -> Compiles/Creates Bin Files & Runs the Program"
  echo "$0 clean -> Cleans Bin Files"
    echo "$0 gen_test -> Generates Test Cases"
  exit 1
elif [ "$1" == "clean" ]; then
  echo "Cleaning up..."
  rm -rf bin
  exit 0
  elif [ "$1" == "gen_test" ]; then
gcc "/Users/n00bie/Learning/DAA_Lab_Report/.test/test_case_generator.c" -o "test_case_generator" && ./test_case_generator && rm -rf test_case_generator
  exit 0
elif [ ! -f "$1" ]; then
  echo "Error: File '$1' not found"
  exit 1
fi
if [ ! -d "bin" ]; then
echo "Creating bin Directory.."
mkdir bin
fi
gcc  "$1" -o "bin/${1%.c}" 

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
else
  echo "-----------------------------"
  echo "Compilation Successful"
  echo "-----------------------------"
  ./bin/"${1%.c}"
  echo "-----------------------------"
fi
