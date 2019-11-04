#!usr/bin/env ruby
#
text = File.read(ARGV[0])
#text.scan(/\D+(0?[1-9]+0?)\D+/)
puts text.scan(/\D+(0*[1-9]*0*)\D/) #i can grab each number, but i couldnt figure out how to compare for < 32

