const shadowDisplay = document.querySelector(".shadow-display");
const cubeFaces = document.querySelector(".cube-faces");

const getImgs = () => {
	const is = prompt("Url for images");
	const time = prompt("Enter animation time in seconds");
	const bgcolor = prompt("Enter background color");
	let promptImages = [];
	promptImages = is.split("https");
	console.log(promptImages);
	const images = document.querySelectorAll("img");
	images.forEach((a, index) => {
		console.log(`https${promptImages[index + 1]}`);
		a.setAttribute("src", `https${promptImages[index + 1]}`);
	});
	shadowDisplay.style.animation = `spin ${+time}s infinite linear`;
	cubeFaces.style.animation = `spin ${+time}s infinite linear`;
	document.querySelector("body").style.backgroundColor = bgcolor;
};

getImgs();
