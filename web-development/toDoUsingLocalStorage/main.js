if(window.localStorage.getItem("id") == undefined){
	window.localStorage.setItem("id", 1);
}
function loader(){
	for(i=1; i<100; i++){
		if(window.localStorage.getItem("task" + i) == undefined){
			continue;
		}
		var task = window.localStorage.getItem("task" + i);
		var desc = window.localStorage.getItem("desc" + i);
		compo(task, desc, i);
	}
}
function send(){
	var task = document.getElementById("task").value;
	var desc = document.getElementById("desc").value;
	if(task=="" || desc==""){
		alert("Please enter some data");
	}
	else{
		var id = window.localStorage.getItem("id");
		window.localStorage.setItem("task" + id, task);
		window.localStorage.setItem("desc" + id, desc);
		document.getElementById("task").value = "";
		document.getElementById("desc").value = "";

		var Task = window.localStorage.getItem("task" + id);
		var Desc = window.localStorage.getItem("desc" + id);
		compo(Task, Desc, id);
		id++;
		window.localStorage.setItem("id", id);
	}
}
function compo(task, desc, id) {
	var div = document.createElement("div");
	var h1 = document.createElement("h1");
	var hr = document.createElement("hr");
	var p = document.createElement("p");
	var button = document.createElement("button");
	div.id = id;
	h1.innerHTML = task;
	p.innerHTML = desc;
	button.innerHTML = "Completed!";
	button.onclick = function(){
		document.getElementById(id).style.display = "none";
		window.localStorage.removeItem("task" + id);
		window.localStorage.removeItem("desc" + id);
	}
	div.append(h1, hr, p, button);
	document.getElementById("components").appendChild(div);
}
