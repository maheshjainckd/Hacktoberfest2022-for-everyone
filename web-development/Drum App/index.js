var doc=document.querySelectorAll(".drum");
for(var i=0;u=i<doc.length;i++)
doc[i].addEventListener("click",handleClick);
function handleClick()
{
    var buttonHTML= this.innerHTML;
    soundMaker(buttonHTML);
    buttonAnimation(buttonHTML);
    
}
document.addEventListener("keydown", function(event){
   soundMaker(event.key); 
   buttonAnimation(event.key);
});

function soundMaker(key)
{
    switch(key)
    {
        case 'w':
            new Audio('sounds/tom-1.mp3').play();
            break;
        
        case 'a':
            new Audio('sounds/tom-2.mp3').play();
            break;
        
        case 's':
            new Audio('sounds/tom-3.mp3').play();
            break;
        
        case 'd':
            new Audio('sounds/tom-4.mp3').play();
            break;
            
        case 'j':
            new Audio('sounds/snare.mp3').play();
            break;

        case 'k':
            new Audio('sounds/kick-bass.mp3').play();
            break;

        case 'l':
            new Audio('sounds/crash.mp3').play();
            break;

        default: 
        console.log(key);
    }
}


function buttonAnimation(currentKey){
    var activeButton=document.querySelector("."+currentKey);
    activeButton.classList.add("pressed");
    setTimeout(function(){
        activeButton.classList.remove("pressed");
    },200);
}




