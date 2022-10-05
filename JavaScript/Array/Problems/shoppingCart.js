const products = [
    { name: "flour", price: 200 },
    { name: "cookies", price: 50 },
    { name: "beer", price: 200 },
    { name: "milk", price: 150 },
    { name: "soda", price: 400 },
  ];
  
  let shoppingCart = [];
  
  let user = prompt("Hi, are you going to buy any product?");
  
  while (user !== "yes" && user !== "no") {
    alert("Please, enter yes or no");
    user = prompt("Hey, do you want to buy something? yes or no?");
  }
  
  if (user == "yes") {
    alert("Ok, this is our list of products:  ");
    let productsInStock = products.map(
      (product) => product.name + " " + product.price + "$"
    );
    alert(productsInStock.join(" - "));
  }else if (user === "no"){
      alert('Well, thank you very much for coming!!')
  }