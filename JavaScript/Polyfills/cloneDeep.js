function cloneDeep(object) {
  let newObj = {};
  Object.entries(object).forEach((entry) => {
    const [key, value] = entry;
    if (typeof value === "object") {
      newObj[key] = cloneDeep(value);
    }
    if (typeof value === "string") {
      newObj[key] = value;
    }
    if (typeof value === "number") {
      newObj[key] = value;
    }
  });

  return newObj;
}

let obj = { name: "smriti", age: 26, test: { test: "testing" } };
let obj2 = cloneDeep(obj);
obj2.test.test = "helllo";
console.log(obj, obj2);
