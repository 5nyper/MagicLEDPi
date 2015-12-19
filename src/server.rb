require 'sinatra'

get '/' do
	"Success."
end

get '/app' do
	"done"
	response["Connection"] = "Close"
	`sudo pkill blink` 
	pid = fork do
		`sudo ./blink #{params["patt"]} #{params["color"]}`
	end
	Process.detach(pid)
	"Done"
end
