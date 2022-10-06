//jshint esversion:6
const express = require('express')
const bodyParser= require("body-parser")
const app = express()
const port = 3000
//url encoded used when we get data from a html form
app.use(express.urlencoded({ extended: true }))
app.get('/', (req, res) => {
  res.sendFile(__dirname+"/index.html");
  //console.log(res);
})

app.post('/bmicalculator', (req, res) => {
  console.log(req.body.num1);
  var height=parseFloat(req.body.num1)
  var weight=parseFloat(req.body.num2)
  var answer=Math.round(weight/(height* height));
  res.send("Your BMI is "+ answer)
})

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})