// link - https://calm-refuge-93371.herokuapp.com/

const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");
const _ = require("lodash");
const date = require(__dirname + "/date.js");

const app = express();

app.set('view engine', 'ejs');

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

mongoose.connect("mongodb://localhost:27017/todolistDB"); // connecting database

// Creating Schema
const itemsSchema = {
  name: String
};

// Creating Model
const Item = mongoose.model(
  "Item", // Singular form
  itemsSchema
);

const item1 = new Item({
  name: "Welcome to your todolist!"
});

const item2 = new Item({
  name: "Hit + button to add a new item."
});

const item3 = new Item({
  name: "<-- Hit this to delete an item."
});

const defaultItems = [item1, item2, item3];

const listSchema = {
  name: String,
  items: [itemsSchema]
};

const List = mongoose.model("List", listSchema);


app.get("/", function (req, res) {
  const day = date.getDate();

  Item.find({}, function (err, foundItems) {
    //Inserting defalut Items in the Database
    if (foundItems.length === 0) {
      Item.insertMany(defaultItems, function (err) {
        if (err)
          console.log(err);
        else
          console.log("Successfully inserted items to Database.");
      });
    }
    else {
      res.render("list", { listTitle: day, newListItems: foundItems });
    }

  });

});

app.get("/:customListName", function (req, res) {
  const customListName = _.capitalize(req.params.customListName);

  List.findOne({ name: customListName }, function (err, foundList) {
    if (!err) {
      if (!foundList) {
        const list = new List({
          name: customListName,
          items: defaultItems
        });

        list.save();
        res.redirect("/" + customListName);
      }
      else {
        res.render("list", { listTitle: foundList.name, newListItems: foundList.items });
      }
    }
    else
      console.log(err);
  });

});


app.post("/", function (req, res) {
  const itemName = req.body.newItem;
  const listName = req.body.list;
  const day = date.getDate();

  const item = new Item({
    name: itemName
  });

  if (listName === day) {
    item.save();
    res.redirect("/");
  }
  else {
    List.findOne({ name: listName }, function (err, foundList) {
      foundList.items.push(item);
      foundList.save();
    });
    res.redirect("/" + listName);
  }

  // if (req.body.list === "Work") {
  //   workItems.push(item);
  //   res.redirect("/work");
  // } else {
  //   items.push(item);
  //   res.redirect("/");
  // }
});

app.post("/delete", function (req, res) {
  const checkedItemId = req.body.checkbox;
  const listName = req.body.listTitle;
  const day = date.getDate();

  if (listName === day) {
    Item.findByIdAndRemove(checkedItemId, function (err) {
      if (err) console.log(err);
      else {
        console.log("Item Deleted!");
        res.redirect("/");
      }
    });
  }
  else {
    List.findOneAndUpdate({ name: listName }, { $pull: { items: { _id: checkedItemId } } }, function (err, foundList) {
      if (!err) {
        res.redirect("/" + listName);
      }
    });

  }
});

app.get("/work", function (req, res) {
  res.render("list", { listTitle: "Work List", newListItems: workItems });
});

app.get("/about", function (req, res) {
  res.render("about");
});

let port = process.env.PORT;
if (port == null || port == "") {
  port = 3000;
}

app.listen(port, function () {
  console.log("Server started on port " + port);
});
