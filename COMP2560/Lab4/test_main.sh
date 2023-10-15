#!/bin/bash
echo "compiling to assembly lines..."
cc main.c -S
cc increment.c -S
echo "translating to opcodes..."
cc main.s -c
cc increment.s -c
echo "statically linking all required opcodes..."
cc main.o increment.o -o main
echo "build successfully done!"
#echo "running the main program"
#./main
#echo "running the main for input 4:"
#./main <<< 4
#echo "running the main for input 10:"
#./main <<< 10

passed=0
failed=0

while IFS=',' read input expected
do
#	echo "test for the main program for $input"	
	output=$(./main <<< $input)
	if [ $output == $expected ]; then
		#echo "true output = $output, expected = $expected"
		result="passed" 
		passed=$((passed + 1))
	else
		#echo "false output = $output, expected = $expected"
		result="failed"
		failed=$((failed + 1))
	fi
	
	echo "input: $input, main: $output, correct: $expected ==> $result"
done < "./test_inputs.txt"
echo "total passed: $passed"
echo "total failed: $failed"
