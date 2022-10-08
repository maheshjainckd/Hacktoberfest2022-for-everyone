const calcLuminosityOfColor = ([r, g, b] =  colorRGB) => ((r * 299) + (g * 587) + (b * 114)) / 1000;

const hexToRgb = hex => {
  return hex.replace(/^#?([a-f\d])([a-f\d])([a-f\d])$/i
             ,(m, r, g, b) => '#' + r + r + g + g + b + b)
    .substring(1).match(/.{2}/g)
    .map(x => parseInt(x, 16))
}

function brightestColor(colors){
    return colors.reduce(function(firstColor, secondColor){
        let luminosityOfFirstColor = calcLuminosityOfColor(hexToRgb(firstColor));
        let luminosityOfSecondColor = calcLuminosityOfColor(hexToRgb(secondColor));
        return (luminosityOfFirstColor > luminosityOfSecondColor) ? firstColor : secondColor;
    })
}
 
console.log(brightestColor(["#001000", "#000000"]));
console.log(brightestColor(["#ABCDEF", "#123456"]));
console.log(brightestColor(["#00FF00", "#FFFF00"]));