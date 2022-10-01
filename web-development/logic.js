const updateCount = () => {
    let message = document.getElementById("message").value;

    let wordCount = (message).split(' ').length

    document.getElementById("word-count").innerText = wordCount;
    document.getElementById("character-count").innerText = message.length;
};