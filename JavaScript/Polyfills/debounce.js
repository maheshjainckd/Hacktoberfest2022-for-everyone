function debounce(task, time) {
  let timerId;
  return (val) => {
    if (timerId) {
      clearTimeout(timerId);
    }
    timerId = setTimeout(() => {
      task(val);
    }, time);
  };
}

function throttle(task, time) {
  let latestVal;
  let started;
  return (val) => {
    latestVal = val;
    if (started) {
      return;
    }
    started = true;
    setTimeout(() => {
      started = false;
      task(latestVal);
    }, time);
  };
}

let debounceCall = debounce((value) => {
  console.log("task complete " + value);
}, 500);

let throttlerCall = throttle((value) => {
  console.log("task complete " + value);
}, 400);

let count = 0;
let intervalId = setInterval(() => {
  if (count === 10) {
    clearInterval(intervalId);
  }
  // debounceCall(count);
  throttlerCall(count);
  count++;
}, 200);

setTimeout(() => {
    debounceCall("final");
}, 1500);


