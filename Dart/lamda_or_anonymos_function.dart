void main() {   
  var list = ["James","Patrick","Mathew","Tom"];  
  print("Example of anonymous function");  
  list.forEach((item) {  
      print('${list.indexOf(item)}: $item');  
});  
}  