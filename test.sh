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
	echo "$(tput setaf 1)$1$(tput sgr 0)\c"
	test_status=1
}

green() {
	echo "$(tput setaf 2)$1$(tput sgr 0)\c"
}

assert() {
	if [ $# -ne 2 ]; then
		red "[KO] "
		return 0
	fi
	if [ -z $1 ]; then
		red "[KO] "
		return 0
	fi
	if [ -z $2 ]; then
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
	echo "No arguments:       \c"
	if [ -z `./checker` ]
   	then green "[OK] "
	else red "[KO] "
	fi
	if [ -z `./push_swap` ]
   	then green "[OK] "
	else red "[KO] "
	fi

	echo "\nNot digit character \c"
	assert_error `./checker 1 2 3 four 2>&1`
	assert_error `./checker -1 2 3-3 2>&1`
	assert_error `./checker 1_000 23 0 -1 2>&1`
	assert_error `./push_swap 1 2 3 four 2>&1`
	assert_error `./push_swap -1 2 3-3 2>&1`
	assert_error `./push_swap 1_000 23 0 -1 2>&1`

	echo "\nDuplicates          \c"
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

	echo "\nMax/min int         \c"
	assert_ok `echo "\c" | ./checker $MIN_INT 2>&1`
	assert_ok `echo "\c" | ./checker $MAX_INT 2>&1`
	assert_error `echo "\c" | ./checker $MIN_INT1 2>&1`
	assert_error `echo "\c" | ./checker $MAX_INT1 2>&1`
	if [ -z `./push_swap $MIN_INT 2>&1` ]
	then green "[OK] "
	else red "[KO] "
	fi
	if [ -z  `./push_swap $MAX_INT 2>&1` ]
	then green "[OK] "
	else red "[KO] "
	fi
	assert_error `./push_swap $MIN_INT1 2>&1`
	assert_error `./push_swap $MAX_INT1 2>&1`


	echo "\nMax/min long        \c"
	assert_error `echo "\c" | ./checker $MIN_LONG 2>&1`
	assert_error `echo "\c" | ./checker $MAX_LONG 2>&1`
	assert_error `echo "\c" | ./checker $MIN_LONG1 2>&1`
	assert_error `echo "\c" | ./checker $MAX_LONG1 2>&1`
	assert_error `./push_swap $MIN_LONG 2>&1`
	assert_error `./push_swap $MAX_LONG 2>&1`
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
			green "."
			;;
		"KO")
			red  "!"
			echo "Test $i failed with: $arg" >> result.log
			;;
		"Error")
			red "!"
			echo "Test $i failed due to parsing error with: $arg" >> result.log
			;;
		*)
			red "Unexpected output"
			exit
			;;
	esac
done

exit $test_status
