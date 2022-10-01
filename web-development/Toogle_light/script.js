const darkMode = document.querySelector("input[name=darkMode]");


darkMode.addEventListener('change', function () {
    document.body.classList.toggle('dark-mode')

})

const lightblueMode = document.querySelector("input[name=lightblueMode]");


lightblueMode.addEventListener('change', function () {
    document.body.classList.toggle('lightblue-mode')

})