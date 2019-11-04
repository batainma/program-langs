#!usr/bin/env ruby
#
text = File.read(ARGV[0])
text.gsub!(/(\s{2,})/, " ")
puts text
