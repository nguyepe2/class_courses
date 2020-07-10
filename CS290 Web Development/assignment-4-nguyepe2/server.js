/*
 * Write your server code in this file.
 *
 * Author: Peter Nguyen
 * OSU email: nguyepe2@oregonstate.edu
 */

var fs = require('fs');
var http = require('http');

var twitDefault = fs.readFileSync('public/index.html', 'utf8');
var twitError = fs.readFileSync('public/404.html', 'utf8');
var twitStyle = fs.readFileSync('public/style.css', 'utf8');
var twitIndex = fs.readFileSync('public/index.js', 'utf8');

function requestHandler(req, res) {
   console.log("== Got a request");
   console.log("  -- method:", req.method);
   console.log("  -- url:", req.url);

   res.writeHead(200, {'Content-Type': 'text/html'});

   if(req.url === '/style.css') {
      res.writeHead(200, {'Content-Type': 'text/css'});
      res.statusCode = 200;
      console.log("requested style.css");
      req.url = 'public/style.css';
      res.write(twitStyle);
      res.end();
   }

   else if(req.url === '/index.js') {
      res.writeHead(200, {'Content-Type': 'text/css'});
      res.statusCode = 200;
      console.log("requested index.js");
      req.url = 'public/index.js';
      res.write(twitIndex);
      res.end();
   }
   else if(req.url === '/404.html') {
      res.statusCode = 200;
      console.log("requested 404.html");
      req.url = 'public/404.html';
      fs.readFileSync('public/style.css', 'utf8');
      fs.readFileSync('public/index.js', 'utf8');
      res.write(twitError);
      res.end();
   }

   else if(req.url === '/index.html') {
      res.statusCode = 200;
      console.log("requested index.html");
      fs.readFileSync('public/style.css', 'utf8');
      fs.readFileSync('public/index.js', 'utf8');
      res.write(twitDefault);
      res.end();
   }
   
   else if(req.url === '/') {
      res.statusCode = 200;
      console.log("requested /");
      res.write(twitIndex);
      res.write(twitStyle);
      res.write(twitDefault);
      res.end();
   }
   else {
      res.statusCode = 404;
      console.log("requested page doesn't exist");
      res.write(twitError);
      res.end();
   }
}
var server = http.createServer(requestHandler);
var newPort = 1324;

server.listen(newPort, function(){
   console.log("Server is listening on port 1324");
});

