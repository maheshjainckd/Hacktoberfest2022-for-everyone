/**
 * @param {string} 
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  
  let a = (s.split(" "));
  let b=[]

  for (let i in a)
    if (a[i] !== "") {
      b.push(a[i])
    }
   return(b[b.length-1].split("").length)
};

console.log(lengthOfLastWord("    fly me   to   the moon  "));
