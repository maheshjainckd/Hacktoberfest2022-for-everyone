var noOfDrums = document.querySelectorAll(".note").length;
for(var i = 0; i<noOfDrums; i++){
  document.querySelectorAll(".note")[i].addEventListener("click",function(){

   var buttonInnerHTML = this.innerHTML;
   makeSound(buttonInnerHTML);
   buttonAnimation(buttonInnerHTML);

    }
  );
}
function makeSound(key){
  switch (key) {
    case 'E':
    var tom1 = new Audio("sounds/chordE.mp3");
    tom1.play();
    break;
    case 'B':
    var tom2 = new Audio("sounds/chordB.mp3");
    tom2.play();
    break;
    case 'G':
    var tom3 = new Audio("sounds/chordG.mp3");
    tom3.play();
    break;
    case 'D':
    var tom4 = new Audio("sounds/chordD.mp3");
    tom4.play();
    break;
    case 'A':
    var snare = new Audio("sounds/chordA.mp3");
    snare.play();
    break;
    case 'F':
    var crash = new Audio("sounds/chordF.mp3");
    crash.play();
    break;
    case 'C':
    var kick = new Audio("sounds/chordC.mp3");
    kick.play();
    break;
    case 'Dm':
    var chord = new Audio("sounds/chordDm.mp3");
    kick.play();
    break;
  }
}
function buttonAnimation(currentKey){
  var presentKey = document.querySelector("."+ currentKey);
  presentKey.classList.add("pressed");

setTimeout(function(){
  presentKey.classList.remove("pressed");
}, 100);
}
