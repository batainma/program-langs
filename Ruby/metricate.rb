#!/usr/bin/env ruby
#
text = File.read(ARGV[0])
text.gsub!(/(\d+\.?(\d*))\s(pounds|pound|lbs)/){"%.#{$2.length}f kgs" % ($1.to_i*0.453592)}
text.gsub!(/(\d+\.?(\d*))\s(inches|inch|in)/){"%.#{$2.length}f cm" % ($1.to_i*2.54)}
text.gsub!(/(\d+\.?(\d*))\s(miles|mile)/) {"%.#{$2.length}f km" % ($1.to_i*1.60943)}
text.gsub!(/(\d+\.?(\d*))\s(yards|yard|yd)/) {"%.#{$2.length}f m" % ($1.to_i*0.9144)}
print text
