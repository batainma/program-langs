#!usr/bin/env ruby
#
#
className = ARGV[0]
className = className.scan(/\.*\/*(\w+)\.\w+/)
puts className
check = File.read(ARGV[0])
if check.match(/public\s?.*\s?class\s(#{className})/) #accepts anything with "public x class" but interpolating the var doesnt affect the regex
exit(0)							#i dont know how to make it register it
else
exit(1)
end

