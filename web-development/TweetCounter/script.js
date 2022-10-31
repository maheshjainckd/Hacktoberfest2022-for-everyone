function ShowCount(){
    var tweet = document.getElementById("tweet").value;
    console.log(tweet);
    var tweetLength = tweet.length;
    var tweetCount = document.getElementById("counter");
    tweetCount.innerHTML = tweetLength;
    var rem = document.getElementById("rem");
    rem.innerHTML = 280 - tweetLength;

    if(tweetLength > 280){
        tweetCount.style.color = "red";
        rem.style.color = "red";
        rem.innerHTML = "You have exceeded the limit by " + (tweetLength - 280);
    }
    else{
        tweetCount.style.color = "black";
        rem.style.color = "black";
    }
}

function ClearTweet(){
    var tweet = document.getElementById("tweet");
    tweet.value = "";
    tweet.focus();
    ShowCount();
}

function ShowTweet(){
    var tweet = document.getElementById("tweet").value;
    var final = document.getElementById("final");
    var msg = tweet.slice(0,280);
    final.innerHTML = msg;
    return msg;
}

function CopyTweet(){
    var final = document.getElementById("final").value;
    final.select();
    console.log(final.value);
    navigator.clipboard.writeText(final.value);
    alert("Copied to clipboard");
}