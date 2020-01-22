#!/bin/sh

if [ $# -lt 1 ]; then
	echo "Usage $0 test_number [start] [end]"
	exit
fi

MAX_INT=2147483647
MIN_INT=-2147483648
MAX_INT1=2147483648
MIN_INT1=-2147483649

MAX_LONG=9223372036854775807
MIN_LONG=-9223372036854775808
MAX_LONG1=9223372036854775808
MIN_LONG1=-9223372036854775809

test_status=0

red() {
	echo -n "\033[31m$1\033[0m "
	test_status=1
}

green() {
	echo -n "\033[32m$1\033[0m "
}

assert() {
	if [ $# -ne 2 ]; then
		red "[KO] "
		return 0
	fi
	if [ -z $1 -o -z $2 ]; then
		red "[KO] "
		return 0
	fi
	if [ $1 = $2 ]; then
		green "[OK] "
	else
		red "[KO] "
	fi
}

assert_ok() {
	assert $1 "OK"
}

assert_error() {
	assert $1 "Error"
}

if [ $1 = "--error" ]; then
	echo -n "No arguments:       "
	if [ -z `./checker` ]; then
		green "[OK] "
	else
		red "[KO] "
	fi
	if [ -z `./push_swap` ]; then
		green "[OK] "
	else
		red "[KO] "
	fi

	echo -n "\nNot digit character "
	assert_error `checker 1 2 3 four 2>&1`
	assert_error `./checker -1 2 3-3 2>&1`
	assert_error `./checker 1_000 23 0 -1 2>&1`
	assert_error `./push_swap 1 2 3 four 2>&1`
	assert_error `./push_swap -1 2 3-3 2>&1`
	assert_error `./push_swap 1_000 23 0 -1 2>&1`

	echo -n "\nDuplicates          "
	assert_error `./checker 1 1 2 3 2>&1`
	assert_error `./checker 1 2 3 3 2>&1`
	assert_error `./checker -1 0 2 0 2>&1`
	assert_error `./checker -100 2 -100 2>&1`
	assert_error `./checker 1 1 2>&1`
	assert_error `./push_swap 1 1 2 3 2>&1`
	assert_error `./push_swap 1 2 3 3 2>&1`
	assert_error `./push_swap -1 0 2 0 2>&1`
	assert_error `./push_swap -100 2 -100 2>&1`
	assert_error `./push_swap 1 1 2>&1`

	echo -n "\nMax/min int         "
	assert_ok `echo -n "" | ./checker $MIN_INT 2>&1`
	assert_ok `echo -n "" | ./checker $MAX_INT 2>&1`
	assert_error `echo -n "" | ./checker $MIN_INT1 2>&1`
	assert_error `echo -n "" | ./checker $MAX_INT1 2>&1`
	assert `push_swap $MIN_INT 2>&1` ""
	assert `push_swap $MAX_INT 2>&1` ""
	assert_error `push_swap $MIN_INT1 2>&1`
	assert_error `push_swap $MAX_INT1 2>&1`


	echo
	red "Undefined behavior with > MAX_INT values, strtol not working properly"
	echo -n "\nMax/min long        "
	assert_ok `echo -n "" | ./checker $MIN_LONG 2>&1`
	assert_ok `echo -n "" | ./checker $MAX_LONG 2>&1`
	assert_error `echo -n "" | ./checker $MIN_LONG1 2>&1`
	assert_error `echo -n "" | ./checker $MAX_LONG1 2>&1`
	assert `./push_swap $MIN_LONG 2>&1` ""
	assert `./push_swap $MAX_LONG 2>&1` ""
	assert_error `./push_swap $MIN_LONG1 2>&1`
	assert_error `./push_swap $MAX_LONG1 2>&1`

	exit $test_status
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

for i in `seq 1 $test_nb`; do
	arg=`./random_stack.rb $start $end`
	result=`./push_swap $arg | ./checker $arg`

	case $result in
		"OK")
			green "\033[32m.\033[0m"
			;;
		"KO")
			red  "\033[31m!\033[0m"
			echo "Test $i failed with: $arg" >> result.log
			;;
		"Error")
			red "\033[31m!\033[0m"
			echo "Test $i failed due to parsing error with: $arg" >> result.log
			;;
		*)
			red "Unexpected output"
			exit
			;;
	esac
done

exit $test_status
