const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mongoose = require("mongoose");

const app = express();

app.set('view engine', ejs);

app.use(bodyParser.urlencoded({ extended: true }));

mongoose.connect("mongodb://localhost:27017/wikiDB");

const articleSchema = {
   title: String,
   content: String
};

const Article = mongoose.model("Article", articleSchema);


/****************************   Requests targetting all articles   *****************************/


app.route("/articles")

   .get(function (req, res) {
      Article.find({}, function (err, articles) {
         if (!err)
            res.send(articles);
         else
            console.log(err);
      });
   })

   .post(function (req, res) {
      const newArticle = new Article({
         title: req.body.title,
         content: req.body.content
      });

      newArticle.save(function (err) {
         if (!err)
            res.send("Successfully added a new article.");
         else
            res.send(err);
      });

   })

   .delete(function (req, res) {
      Article.deleteMany(function (err) {
         if (!err) {
            res.send("Successfully deleted all articles.");
         }
         else {
            res.send(err);
         }
      });
   });


/****************************   Requests targetting a specific article   *****************************/


app.route("/articles/:articleTitle")

   .get(function (req, res) {
      Article.findOne({ title: req.params.articleTitle }, function (err, foundArtile) {
         if (foundArtile) {
            res.send(foundArtile);
         }
         else {
            res.send("No articles matching that title was found.");
         }
      });
   })

   .put(function (req, res) {
      Article.update(
         { title: req.params.articleTitle },
         { title: req.body.title, content: req.body.content },
         function (err) {
            if (!err)
               res.send("Successfuly updated the article.");
            else
               res.send(err);
         }
      );
   })

   .patch(function (req, res) {
      Article.update(
         { title: req.params.articleTitle },
         { $set: req.body },
         function (err) {
            if (!err)
               res.send("Successfully patched the article.");
            else
               res.send(err);
         }
      );
   })

   .delete(function (req, res) {
      Article.deleteOne(
         { title: req.params.articleTitle },
         function (err) {
            if (!err)
               res.send("Successfully deleted the article.");
            else
               res.send(err);
         }
      );
   });


app.listen(3000, function () {
   console.log("Server stated on port 3000");
});
