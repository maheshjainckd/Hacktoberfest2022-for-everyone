const input = document.getElementById('input')

const submit = document.getElementById('submit')

const img = document.getElementById('img')

const main = document.getElementById('main')

submit.addEventListener("click", generate)

function generate() {
    main.style.height = "500px";
    input.style.height = "10%"
    submit.style.height = "10%"
    img.style.display = "block"

    let data = input.value;
    img.src = `https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=${data}`

}