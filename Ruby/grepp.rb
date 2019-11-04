#!usr/bin/env ruby
#
#
var = ARGV[0]
file = File.read(ARGV[1])
puts file.scan(/\w+#{var}/) 

