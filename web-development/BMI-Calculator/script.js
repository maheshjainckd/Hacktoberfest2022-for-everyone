const errorWeight = document.getElementById("error-weight");
const errorHeight = document.getElementById("error-height");

function calculate() {
	// for clearing
	errorWeight.style.visibility = "hidden";
	errorHeight.style.visibility = "hidden";
	const result = document.getElementById("result");
	result.innerHTML = "";

	let weight = document.getElementById("weight").value;
	let height = document.getElementById("height").value;

	// for checking if any blank field
	if (weight == "" && height == "") {
		errorWeight.style.visibility = "visible";
		errorHeight.style.visibility = "visible";
		return;
	}

	if (weight == "") {
		errorWeight.style.visibility = "visible";
		return;
	}

	if (height == "") {
		errorHeight.style.visibility = "visible";
		return;
	}

	// parse string into int
	weight = parseInt(weight);
	height = parseInt(height);

	let resultCalc = weight / (height / 100) ** 2;
	resultCalc = resultCalc.toFixed(1);
	let categories;

	if (resultCalc >= 30) {
		categories = "Obesity";
	} else if (resultCalc >= 25) {
		categories = "Overweight";
	} else if (resultCalc >= 18.5) {
		categories = "Normal";
	} else {
		categories = "Underweight";
	}

	// output final result
	const response = `Your BMI is <strong>${resultCalc}</strong> which means You are <strong>${categories}</strong>`;
	result.innerHTML = response;
}
