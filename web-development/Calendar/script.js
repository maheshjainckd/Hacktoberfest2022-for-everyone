var h2 = document.getElementById("dateDayH2");
var h3 = document.getElementById("monthH3");

var monthArr = [
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December",
];

var dayArr = [
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thrusday",
  "Friday",
  "Saturday",
];

var day31monthArr = [
  "January",
  "March",
  "May",
  "July",
  "August",
  "October",
  "December",
];

var d = new Date();

var obj = getDate();
function getDate() {
  var month = d.getMonth();
  month = monthArr[month];

  var day = d.getDay();
  day = dayArr[day];

  var date = d.getDate();

  h2.innerHTML = date + ", " + day;
  h3.innerHTML = month;

  return { m: month, dy: day, dt: date, yr: d.getFullYear() };
}

function makeCalender() {
  var days;
  if (obj.m === "February" && obj.yr % 4 !== 0) {
    days = 28;
  } else if (obj.m === "February" && obj.yr % 4 === 0) {
    days = 29;
  } else if (day31monthArr.includes(obj.m)) {
    days = 31;
  } else {
    days = 30;
  }

  var LocalDayArr = [
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thrusday",
    "Friday",
    "Saturday",
    "Sunday",
  ];

  var startOfMonth = moment().clone().startOf("month").format("dddd");

  var dayIndex = LocalDayArr.indexOf(startOfMonth);

  for(var  j =0 ; j<dayIndex;j++){
      var element  = document.createElement("div");
      element.classList = "calender_num_empty";
      document.getElementById("cd").appendChild(element);

  }

  for(var k =1 ; k<= days;k++){
      var element = document.createElement("div");
      obj.dt === k  
      ?(element.className="calender_num calender_num--current")
      :(element.className = "calender_num");

      element.appendChild(document.createTextNode(k));
      document.getElementById("cd").appendChild(element);

  }
}
makeCalender();


const backgroundChange =(imageSrcc)=>{
  let contBack = document.getElementsByClassName('naturalBg')[0].style;
  let contBack1 = document.getElementsByClassName('calender_pic')[0].style;

  contBack.background = `url(${imageSrcc})`;
  contBack.backgroundSize = 'cover';
  contBack.backgroundPosition = 'center';
  
  contBack1.background = `url(${imageSrcc})`;
  contBack1.backgroundSize = 'cover';
  contBack1.backgroundPosition = 'center';
}


const apiCall = ()=>{
  const URL = "https://api.unsplash.com/photos/random?query= natural";
  fetch(URL,{
      headers:{
          'Authorization': 'Client-ID au1HfKd9cz7xIAxq6jkzHNVMBzKU7D8-atKUsYnRwIE'
      }
  }).then(res=>res.json())
      .then(res => {
          imageUrl = res.urls.small;
          backgroundChange(imageUrl);
      })
      .catch(error => console.log(error))
}
apiCall();
