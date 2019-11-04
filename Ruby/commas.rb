#!usr/bin/env ruby
#
num = ARGV[0]
num.gsub!(/((\d{3})\d)$/, ",#{$1}")
puts num
