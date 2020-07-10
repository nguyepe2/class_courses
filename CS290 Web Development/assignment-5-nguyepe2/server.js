/*
 * Write your routing code in this file.  Make sure to add your name and
 * @oregonstate.edu email address below.
 *
 * Name: Peter Nguyen
 * Email: nguyepe2@oregonstate.edu
 */

var path = require('path');
var express = require('express');
var exphbs = require('express-handlebars');
var twitData = require("./twitData");
var app = express();
var port = process.env.PORT || 4467;

app.engine('handlebars', exphbs({defaultLayout: 'main'}));
app.set('view engine', 'handlebars');

app.use(express.static('public'));

app.get('/', function(req, res) {
  res.status(200).render('twitPage', {
     showButton: true,
     data: twitData});
});

app.get('/twits/:n', function(req, res, next) {
   var n = req.params.n;
   if(n >-1 && n < 8) {
     res.status(200).render('twitPage', {
	showButton: false,
	data: [twitData[n]]})
   } else {
     next();
   }
});

app.get('*', function(req, res) {
  res.status(404).render('partials/404');
});

/*app.get('*', function (req, res) {
  res.status(404).sendFile(path.join(__dirname, 'public', '404.html'));
}); */ 

app.listen(port, function () {
  console.log("== Server is listening on port", port);
});
