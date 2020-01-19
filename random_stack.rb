#!/usr/bin/ruby

if ARGV.length != 2
	puts "Usage: #{$PROGRAM_NAME} start end"
	exit
end

puts (ARGV[0]..ARGV[1]).to_a.shuffle.join(" ")
