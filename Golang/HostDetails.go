package main  
  
import (  
 "fmt"  
 "net"  
)  
  
func checkStringForIpOrHostname(host string) {  
 addr := net.ParseIP(host)  
 if addr == nil {  
  fmt.Println("Given String is a Domain Name")  
  
 } else {  
  fmt.Println("Given String is a Ip Address")  
 }  
}  
func main() {  
 checkStringForIpOrHostname("google.com")  
 checkStringForIpOrHostname("192.168.1.0")  
  
} 
