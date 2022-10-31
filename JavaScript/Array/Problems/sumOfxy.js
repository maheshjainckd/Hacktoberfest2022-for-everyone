
//  sumOfxy
// here x and y are two arrays of equal length the function is expected to return a new array that gives the sum of the two arrays in the same index

function sum(a,b){
    let sumOfxy = [];
    for(let i = 0; i<a.length; i++)
    {
     sumOfxy.push(a[i]+b[i])
    }
    console.log(sumOfxy) 
    return sumOfxy
  }
 sum([1, 2, 3, 4, 5],[6, 7, 8, 9, 15]);


//  ProductOfxy
// here x and y are two arrays of equal length the function is expected to return a new array that gives the product of the two arrays in the same index


function product(x,y){
    let productOfxy = [];
    for(let i = 0; i<x.length; i++)
    {
     productOfxy.push(x[i]*y[i])
    }
    console.log(productOfxy) 
    return productOfxy
  }
 product([2, 2, 3, 4, 5],[6, 7, 8, 9, 10]);