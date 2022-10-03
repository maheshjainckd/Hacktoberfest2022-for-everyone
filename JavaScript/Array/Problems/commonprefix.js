var longestCommonPrefix = function (strs) {
  let result = [];

  if (strs.length == 0) return "error";

  let length,whichone;
  for (i = 0; i < strs.length; i++) {
    if (i == 0) {
      length = strs[i].length;
      
    } else {
      length = Math.min(length, strs[i].length);
    }
    whichone=i

  }
//   console.log(length);
  len=length
  let count = 1;
  for (let i = 0; i <= strs[whichone].length; i++) {
   
    for (let j = 1; j < strs.length; j++) {
    if(strs[0][i]!==strs[j][i]){
     return strs[0].slice(0,i);
    }
    
    }
  


  }

//   console.log(count);

  // if (strs[i].length <= strs[j].length) {
  //     return [strs[i], strs[j]];
  // }
  //   }
return strs[0]
};

console.log(longestCommonPrefix(["flower", "flow", "flight"]));
