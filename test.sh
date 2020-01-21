#!/bin/sh

if [ $# -lt 1 ]; then
	echo "Usage $0 test_number [start] [end]"
	exit
fi

if [ $1 = "--error" ]; then
	echo -n "No arguments: "
	if [ $(./checker)="" ]; then
		echo -n "\033[32m[OK]\033[0m "
	else
		echo -n "\033[32m[KO]\033[0m "
	fi
	if [ $(./push_swap)="" ]; then
		echo "\033[32m[OK]\033[0m"
	else
		echo "\033[32m[KO]\033[0m"
	fi

	echo -n "Not digit character "
	if [ ! $(./checker 1 2 3 four)="Error\n" ]; then
		echo -n "\033[32m[OK]\033[0m "
	else
		echo -n "\033[32m[KO]\033[0m "
	fi
	if [ ! $(./checker -1 2 3-3)="Error\n" ]; then
		echo -n "\033[32m[OK]\033[0m "
	else
		echo -n "\033[32m[KO]\033[0m "
	fi
	if [ ! $(./checker 1_000 23 0 -1)="Error\n" ]; then
		echo -n "\033[32m[OK]\033[0m "
	else
		echo -n "\033[32m[KO]\033[0m "
	fi

	exit
fi

test_nb=$1

if [ -z $2 ]; then
	start=1
else
	start=$2
fi

if [ -z $3 ]; then
	end=100
else
	end=$3
fi

for i in $(seq 1 $test_nb); do
	arg=$(./random_stack.rb $start $end)
	echo $arg
	result=$(./push_swap $arg | ./checker $arg)

	case $result in
		OK)
			echo -n "\033[32m.\033[0m"
			;;
		KO)
			echo -n "\033[31m!\033[0m"
			echo "Test $i failed with: $arg" >> result.log
			;;
		Error)
			echo -n "\033[31m!\033[0m"
			echo "Test $i failed due to parsing error with: $arg" >> result.log
			;;
		*)
			echo "Unexpected output"
			exit
			;;
	esac
done
