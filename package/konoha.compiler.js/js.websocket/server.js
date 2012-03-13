var WebSocketServer = require('websocket').server;
var http = require('http');

var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8080, function() {
    console.log((new Date()) + ' Server is listening on port 8080');
});

wsServer = new WebSocketServer({
    httpServer: server,
    // You should not use autoAcceptConnections for production
    // applications, as it defeats all standard cross-origin protection
    // facilities built into the protocol and the browser.  You should
    // *always* verify the connection's origin and decide whether or not
    // to accept it.
    autoAcceptConnections: false
});

function originIsAllowed(origin) {
  // put logic here to detect whether the specified origin is allowed.
  return true;
}
var connections = [];
wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin) || connections.length == 2) {
      // Make sure we only accept requests from an allowed origin
      request.reject();
      console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
      return;
    }

    var connection = request.accept('othello-protocol', request.origin);
	connection.sendUTF("id:" + connections.length);
	connections.push(connection);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', function(message) {
		/* message = "[01]:x, y" */
		var num = parseInt(message.utf8Data.slice(0, 1));
        console.log('Received Message: ' + message.utf8Data);
        connections[1 - num].sendUTF(message.utf8Data.slice(2));
    });
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
		connections[0].sendUTF("end");
		connections[1].sendUTF("end");
    });
	if (connections.length == 2) {
		connections[0].sendUTF("start");
		connections[1].sendUTF("start");
	}
});
