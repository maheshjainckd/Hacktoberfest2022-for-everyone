// Function to return reverse of a string passed as an argument.

function reverseString(string) {
    var revData = string.split('');
    for (var i = (revData.length) - 1; i >= 0; i--) {
        console.log(revData[i]);
    }
}

reverseString('This is a text string!');