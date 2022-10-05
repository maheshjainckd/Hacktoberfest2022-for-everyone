//get the elements
var box1 = document.getElementById("box1");
var box2 = document.getElementById("box2");
var box3 = document.getElementById("box3");
var box4 = document.getElementById("box4");
var box5 = document.getElementById("box5");
var box6 = document.getElementById("box6");

var arr=[]; // array to hold the sequence
var i =0;

//function to add the green colour when event listener is triggered
function addColor(num){
    if(num == 1 ){
        box1.style.backgroundColor = "green"
        arr.push(num);
    }
    else if(num == 2){
        box2.style.backgroundColor = "green"
        arr.push(num);

    } 
    else if(num == 3){
        box3.style.backgroundColor = "green"
        arr.push(num);

    }
    else if(num == 4){
        box4.style.backgroundColor = "green"
        arr.push(num);

    }else if(num == 5){
        box5.style.backgroundColor = "green"
        arr.push(num);

    }else if(num == 6){
        box6.style.backgroundColor = "green"
        arr.push(num);
   
    }

    //check if all boxes have been clicked on
    if(arr.length == 6){

        //using the set interval method change the colours one after the other according the the sequence in the array
            const timer =  setInterval(changeColor, 1000);
            function changeColor() {
           
           if(i<arr.length){
             var boxname ="box"+arr[i]
             boxname = document.getElementById(boxname);
             boxname.style.backgroundColor="red";
            
            i++;
           }
           
           else{

           clearInterval(timer); //clear timer once all colors completes the change
           }

           
        }
    }
    

}
