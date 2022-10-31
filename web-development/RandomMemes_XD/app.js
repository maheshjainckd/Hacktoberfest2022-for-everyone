
function next(){
    var random = Math.floor(Math.random()*7) + 1 ;

    var randomMeme = "/memes/" + random + ".jpg";

    var img = document.querySelectorAll("img")[0];
    img.setAttribute("src", randomMeme);

}

const nextButton = document.querySelector("next");

nextButton.addEventListener("click", next);

// var random = Math.floor(Math.random()*7) + 1 ;

// var randomMeme = "/memes/" + random + ".jpg";

// var img = document.querySelectorAll("img")[0];
// img.setAttribute("src", randomMeme);




// Reload Button :

// const reloadButton = document.querySelector("#reload");
// // Reload everything:
// function reload() {
//     reload = location.reload();
// }
// // Event listeners for reload
// reloadButton.addEventListener("click", reload, false);
