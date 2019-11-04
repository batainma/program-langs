#!usr/bin/env ruby
require 'net/http'
#
#
url = ARGV[0]
uri = URI.parse(url)
request = Net::HTTP.new(uri.host, uri.port)
response = request.request_head(uri.path)

if reponse.code.to_i < 400
	print url + ":)\n"
else
	print url + ":(\n"
end
