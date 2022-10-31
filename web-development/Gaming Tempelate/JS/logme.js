function validate(){
    var username=document.getElementById("username");
    var password=document.getElementById("password");

    if(username.value.trim()=="" && password.value.trim()==""){
        username.style.border = "solid 2px red";
        username.style.borderRadius = "13px";
        document.getElementById("user").style.visibility="visible";
        password.style.border = "solid 2px red";
        password.style.borderRadius = "13px";
        document.getElementById("passw").style.visibility="visible";
        return false;
    }
    else if(password.value.trim()=="")
    {
        password.style.border = "solid 2px red";
        password.style.borderRadius = "13px";
        document.getElementById("passw").style.visibility="visible";
        return false;
    }
    else if(username.value.trim()==""){
        username.style.border = "solid 2px red";
        username.style.borderRadius = "13px";
        document.getElementById("user").style.visibility="visible";
        return false;
    }
    else
    {
        return true;
    }
}