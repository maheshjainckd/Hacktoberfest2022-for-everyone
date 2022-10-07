package main
import "fmt"

func printFibonacciSeries(num int){
   a := 0
   b := 1
   c := b
   fmt.Printf("Series is: %d %d", a, b)
   for true{
      c = b
      b = a + b
      if b >= num{
         fmt.Println()
         break
      }
      a = c
      fmt.Printf(" %d", b)
   }
}

func main(){
   printFibonacciSeries(10)
   printFibonacciSeries(16)
   printFibonacciSeries(100)
}
