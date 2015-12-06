require 'sinatra'

get '/' do
	"Success."
end

get '/app' do
	"done"
	response["Connection"] = "Close"
	`sudo pkill blink` 
	`gpio write 0 0` 
	pid = fork do
		`sudo ./blink #{params["func"]}`
	end
	Process.detach(pid)
	"Done"
end
