#!/usr/bin/ruby

exit if ARGV.length < 1

class Stack
	attr_accessor :elements

	def initialize(elements)
		@elements = elements
	end

	def push(el)
		@elements.push el
	end

	def pop
		return if @elements.length < 1
		@elements.pop
	end

	def peek
		@elements[@elements.length - 1]
	end

	def swap
		return if @elements.length < 2
		first = pop
		second = pop
		push(first)
		push(second)
	end

	def rotate
		@elements.rotate! -1
	end

	def rotate_rev
		@elements.rotate! 1
	end

	def to_s
		@elements.map(&:to_s).join(" | ")
	end
end

def green(s)
	"\033[32m#{s}\033[0m"
end

def red(s)
	"\033[31m#{s}\033[0m"
end

def print_stacks(a, b)
	puts "       A             B\n"
	puts "------------------------------"

	a_str = ARGV.length.times.map { |i| ARGV.length - i }.map do |i|
		unless a.elements[i].nil?
			"| " + a.elements[i].to_s.ljust(2) + " " + green(("+" * a.elements[i]).ljust(10)) + "| "
		else
			"|    #{green(' ' * 10)}| "
		end
	end
	b_str = ARGV.length.times.map { |i| ARGV.length - i }.map do |i|
		unless b.elements[i].nil?
			b.elements[i].to_s.ljust(2) + " " + red(("+" * b.elements[i]).ljust(10)) + "|"
		else
			"   #{red(' ' * 10)}|"
		end
	end

	puts a_str.zip(b_str).map { |ab| ab[0] + ab[1] }.join("\n")
	puts "------------------------------"
	puts
end


a = Stack.new(ARGV.map(&:to_i))
b = Stack.new([])

# lines = $stdin.read.split("\n")

$stdin.each_line do |op|
	print_stacks(a, b)
	op.strip!
	puts "> #{op}"
	case op
	when "sa" then a.swap
	when "sb" then b.swap
	when "ss" then
		a.swap
		b.swap
	when "pa" then
		a.push b.peek
		b.pop
	when "pb" then
		b.push a.peek
		a.pop
	when "ra" then a.rotate
	when "rb" then b.rotate
	when "rr" then
		a.rotate
		b.rotate
	when "rra" then a.rotate_rev
	when "rrb" then b.rotate_rev
	when "rrr" then
		a.rotate_rev
		b.rotate_rev
	else
		puts "Error: wrong op"
		exit
	end
end

print_stacks(a, b)
