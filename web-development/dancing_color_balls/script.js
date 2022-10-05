'use strict'
var balls=new Array()
var space=document.querySelector('.space')
var lineSpace=document.querySelector('.line-space')

function randCol(){
    return Math.trunc(Math.random()*255+1);
}
class Balls{
ball=document.createElement('div');
x;
y;
speedX=5;
speedY=5;
movingRight=true;
movingDown=true;
move(){
    this.x+=this.speedX;
    this.y+=this.speedY;
    if((this.movingRight==true)&&(this.x>visualViewport.width)){
        this.speedX*=-1;
        this.movingRight=false;
    }
    else if(this.x<0){
        this.speedX*=-1;
        this.movingRight=true;
    }
    if((this.movingDown==true)&&(this.y>visualViewport.height)){
        this.speedY*=-1;
        this.movingDown=false;
    }
    else if(this.y<0){
        this.speedY*=-1;
        this.movingDown=true;
    }
    this.ball.style.left=this.x-25+scrollX+'px';
    this.ball.style.top=this.y-25+scrollY+'px';
}
constructor(posX,posY,speedX,speedY){
    this.x=posX;
    this.y=posY;
    this.speedX=speedX;
    this.speedY=speedY;
    if(speedX<0)this.movingRight=false;
    if(speedY<0)this.movingDown=false;
    this.ball.style.width='50px';
    this.ball.style.height='50px';
    this.ball.style.backgroundColor=`rgb(${randCol()} ${randCol()} ${randCol()})`;
    this.ball.style.position='absolute';
    this.ball.style.borderRadius='25px';
    this.ball.style.left=this.x-25+scrollX+'px';
    this.ball.style.top=this.y-25+scrollY+'px';
}
getBall(){
    return this.ball;
}
}
function moveBalls(){
setTimeout(function(){
    for(var elem of balls){
        space.insertAdjacentElement('beforeend',elem.ball);
        elem.move();
    }
    moveBalls();
},10);
}
moveBalls();
function lineDraw(initPos,finalPos,width,angle){
clearLine();
var line=document.createElement('div');
line.style.position = 'absolute';
line.style.height='2px';
line.style.width=width+'px';
line.style.left = initPos[0] + scrollX + 'px';
line.style.top = initPos[1] + scrollY + 'px';
line.style.border = '1px solid #FFFFFF';
line.style.backgroundColor = '#FFAB66';
line.style.transformOrigin='top left';
line.style.transform = `rotate(${angle}deg)`;

lineSpace.insertAdjacentElement('beforeend',line);
drawArrowHead(angle,finalPos);
}
function drawArrowHead(angle,pos){
    var arrowhead=document.createElement('img');
    arrowhead.src='./arrow_new.png';
    arrowhead.style.position='absolute';
    arrowhead.style.width='40px';
    arrowhead.style.height='40px';
    arrowhead.style.transformOrigin='center';
    arrowhead.style.userSelect='none';
    arrowhead.style.transform=`rotate(${angle}deg)`;
    arrowhead.style.left=pos[0]+scrollX+'px';
    arrowhead.style.top=pos[1]+scrollY+'px';
    lineSpace.insertAdjacentElement('beforeend',arrowhead);
    
}
function clearLine(){
    lineSpace.innerHTML='';
}
function createBall(posX,posY,speedX,speedY){
let ball=new Balls(posX,posY,speedX,speedY);
balls.push(ball);
}
var initX=0,finalX=0,speedX=0;
var initY=0,finalY=0,speedY=0;
var angle=0;
var tapped=false;
space.addEventListener('mousedown',function(event){
    initX=event.clientX;
    initY=event.clientY;
    tapped=true;
})
space.addEventListener('mousemove',function(event){
    if(!tapped)return;
    finalX=event.clientX;
    finalY=event.clientY;
    var dy=finalY-initY;
    var dx=finalX-initX;
    angle=(Math.atan2(-dy,dx))*(180/Math.PI);
    lineDraw([initX,initY],[finalX,finalY],Math.sqrt(dy*dy+dx*dx),-angle);
    

})
space.addEventListener('mouseup',function(event){
tapped=false;
finalX=event.clientX;
finalY=event.clientY;
speedX=(finalX-initX)/20;
speedY=(finalY-initY)/20;
createBall(event.clientX,event.clientY,speedX,speedY);
clearLine();

},false);

