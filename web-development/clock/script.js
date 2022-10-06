function time()
{
var val=new Date();
var h=val.getHours();
var m=val.getMinutes();
var s=val.getSeconds();
var ap="am";
    if(h>12)
    {
        h=h-12;
        ap="pm";
    }
    if(h<10)
    {
        h='0'+h;
    } 
    if(m<10)
    {
        m='0'+m;
    }
    if(s<10)
    {
        s='0'+s;
    }
document.getElementById("clock").innerHTML=h+":"+m+":"+s+" "+ap;

const months=["January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"];
const days=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];
document.getElementById("date").innerHTML=days[val.getDay()]+", "+val.getDate()+" "+months[val.getMonth()]+" "+val.getFullYear()+".";
};
setInterval(time,1000);

