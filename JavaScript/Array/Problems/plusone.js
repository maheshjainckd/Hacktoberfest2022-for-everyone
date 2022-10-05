var plusOne = function (digits) {
  let len = digits.length;

digits[len - 1] = digits[len - 1] + 1;

while(digits[len-1]>9 && len>1){
    digits[len-1]=0
    digits[len - 2] = digits[len - 2] + 1;
    len--
}
if(digits[len-1]>9 && len==1){
    digits[len-1]=0
    return [1,...digits]
}
return digits


};

