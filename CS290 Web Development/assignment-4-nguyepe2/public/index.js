/*
 * Add the contents of your index.js file from Assignment 3 here to see the
 * interactions you implemented.
 */

//alert('Add the content of your index.js from Assignment 3 to public/index.js.');

var activate = document.getElementById('create-twit-button');
activate.addEventListener('click', unhideModal);

content = document.getElementById('twit-text-input');
user = document.getElementById('twit-attribution-input');

var modal = document.getElementById('create-twit-modal');
var backdrop = document.getElementById('modal-backdrop');

function unhideModal(event) {
   modal.style.display = 'block';
   backdrop.style.display = 'block';
}

function closeStuff(event) {
  content.value = '';
  user.value = '';
  modal.style.display = '';
  backdrop.style.display = '';
}



function submitTwit(event) {
content = document.getElementById('twit-text-input');
user = document.getElementById('twit-attribution-input');
  if(content.value == "") {
    alert("The twit text input field is empty!");
  }
  else if(user.value == "") {
    alert("The author input field is empty!");
  }

  else {
    oldTwit = document.getElementsByClassName('twit')[0];
    newTwit = oldTwit.cloneNode();

    

    var div = document.createElement('div');
    var div2 = document.createElement('div');
    var div3 = document.createElement('div');
    
    newTwit.append(div);
    newTwit.append(div2);
    newTwit.append(div3);

    div.classList.add('twit-icon');
    var bullhorn = document.createElement('i');
    bullhorn.classList.add('fas', 'fa-bullhorn');
    div.appendChild(bullhorn);
    
    div2.classList.add('twit-content');
    var newText = document.createElement('p');
    newText.classList.add('twit-text');
    newContent = document.getElementById('twit-text-input').value;
    newText.innerText = newContent;
    div2.appendChild(newText);

    var author = document.createElement('p');
    var link = document.createElement('a');
    author.classList.add('twit-attribution');
    newUser = document.getElementById('twit-attribution-input').value;
    link.innerText = newUser;
    author.appendChild(link);
    div2.appendChild(author);
    
    twitContainer.append(newTwit);
    user.value = "";
    content.value = "";
    modal.style.display = '';
    backdrop.style.display = '';
    }

}

var xbutton = document.getElementsByClassName('modal-close-button')[0];
xbutton.addEventListener('click', closeStuff);

var cancelButton = document.getElementsByClassName('modal-cancel-button')[0];
cancelButton.addEventListener('click', closeStuff);

var acceptButton = document.getElementsByClassName('modal-accept-button')[0];
acceptButton.addEventListener('click', submitTwit);



var searchInput = document.getElementById('navbar-search-input');
var twits = document.getElementsByClassName('twit');
var twitTextArray = document.getElementsByClassName('twit-text');
var author = document.getElementsByClassName('twit-attribution');
var searchButton = document.querySelector('#navbar-search-button');
var twitContainer = document.getElementsByClassName('twit-container')[0];
var allTwitElems = [];

function searching(event) {
  for(var i = 0; i < twits.length; i++) {
    allTwitElems.push(twits[i]);
    console.log(twits[i]);
}
for(var i=0; i<twits.length; i++) {
  if(twits[i].innerText.indexOf(searchInput.value) <0) {
    twitContainer.removeChild(twits[i]);
    var i = i-1;
  }
}
}

searchButton.addEventListener('click', searching);
