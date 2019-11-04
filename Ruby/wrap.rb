#!usr/bin/env ruby
#
#
num = ARGV[1]

text = File.read(ARGV[0])
puts text.gsub!(/\d{#{num},}\s?\b?\n?/, "#{$1}\n") #$1 does not save the regex i catch. it prints out nothing ?

