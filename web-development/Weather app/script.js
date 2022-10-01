// https://api.openweathermap.org/data/2.5/weather?q=Denver&units=metric&appid=45c65d1dcd93c827a04e471c42e67e1b

let weather = {
    "apikey" : "45c65d1dcd93c827a04e471c42e67e1b",
    fetchWeather: function(city){
        fetch(
            "https://api.openweathermap.org/data/2.5/weather?q="
            + city 
            + "&units=metric&appid="
            + this.apikey
            )
            .then((response) => response.json())
            .then((data) => this.displayWeather(data));
    },

    /* this is how we extract any data out from a json file */
    
    displayWeather: function(data){
        const { name } = data;
        const { icon, description } = data.weather[0];
        const { temp, humidity } = data.main;
        const { speed } = data.wind;
        console.log(name,icon,description,temp,humidity,speed);

        // displaying the stats

        document.querySelector(".city").innerText = "Weather in " + name;
        document.querySelector(".city").src = "https://openweathermap.org/img/wn/" + icon + ".png";
        // https://openweathermap.org/img/wn/icon.png
        document.querySelector(".description").innerText = description;
        document.querySelector(".temp").innerText = temp + "°C";
        document.querySelector(".humidity").innerText = "Humidity: " + humidity + "%";
        document.querySelector(".wind").innerText = "Wind Speed: " + speed + "km/h";
        document.querySelector(".weather").classList.remove("loading");

        
    },
    search: function (){
        this.fetchWeather(document.querySelector(".search-bar").value);
    }
    
}

document
    .querySelector(".search button")
    .addEventListener('click',function(){
        weather.search();
    })
document
    .querySelector(".search-bar")
    .addEventListener("keyup", (event) => {
        if (event.key == "Enter"){
            weather.search();
        }
    })

    weather.fetchWeather("Denver");