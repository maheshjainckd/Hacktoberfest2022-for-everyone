

setInterval(() =>{
    let time = document.getElementById('date');
    let date = new Date();
    let hour = date.getHours();
    let minutes = date.getMinutes();
    let second = date.getSeconds();
    

    time.style.color = "blue";
    time.style.fontSize = "40px";
    time.style.fontWeight = "800";
    time.innerText = `${hour}h. ${minutes}m. ${second}s .`;
},1000);
