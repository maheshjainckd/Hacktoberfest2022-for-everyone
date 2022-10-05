let celsius = document.getElementById("celsius");
let fehrenheit = document.getElementById("fehrenheit");

function celToFar() {
    let output = (parseFloat(celsius.value) * 9 / 5) + 32;
    fehrenheit.value = parseFloat(output.toFixed(2));
}
function FarToCel() {
    let output = (parseFloat(fehrenheit.value) - 32) * 5 / 9;
    celsius.value = parseFloat(output.toFixed(2));
    console.log(output);
}