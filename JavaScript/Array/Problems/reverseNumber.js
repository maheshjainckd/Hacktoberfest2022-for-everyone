var reverse = function (x) {
//   console.log(x < (-2 ^ 31), x > (2 ^ 31));
  if (x > 2**31 || x < -((2**31)-1)) {
    console.log("rest")
    return 0;
  }
  let number = x;
  let rev = 0,
    temp;
  if (number < 0) {
    temp = -1;
  } else temp = 1;
  number = number * temp;

  while (number > 0) {
    rev = rev * 10 + (number % 10);
    // console.log(rev);
    number = Math.floor(number / 10);
  }

  if (rev * temp > 2**31 || rev * temp < -((2**31)-1)) {
    // console.log("rest")
    return 0;
  }
  return  rev * temp;
};

console.log(reverse(1534236469));
