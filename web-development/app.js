const express = require("express");
const bodyParser = require("body-parser");
const app = express();
app.use(bodyParser.urlencoded({extended:true}))
var items = ["Buy food","Complete Express","Do Machine Leanring"]
var workItems = []
app.set("view engine", "ejs")
app.use("/public",express.static("public"))

app.get("/", function(req, res) {
  var today = new Date();
  var curDay = today.getDay();
  var day = ""
  var options = {
    weekday: "long",
    day: "numeric",
    month: "long"
  }
var day=today.toLocaleDateString("en-US",options)
  res.render("list", {listTitle: day,newListItems:items});
});

app.post("/",function(req,res){
    console.log(req.body);
  //console.log(req.body.newItem);
    var item=req.body.newItem;
  if(req.body.list==="Work")
  {
    workItems.push(item)
    res.redirect("/work")
  }else{
    items.push(item)
    res.redirect("/")
  }

  items.push(item);
  res.redirect("/");

})

app.get("/work",function(req,res){
  res.render("list",{listTitle:"Work List",newListItems:workItems})
})

app.post("/work",function(req,res){

  var item=req.body.newItem;
  workItems.push(item);
  res.redirect("/work")
})

app.listen(3000, function() {
  console.log("server is up and running at port 3000")
});
