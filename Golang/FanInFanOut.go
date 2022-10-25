package main

import (
	"fmt"
	"math/rand"
	"time"
)

func sleep() {
	time.Sleep(time.Duration(rand.Intn(1000)) * time.Millisecond)
}

// producer
// chan <- int mean write to the channel
func producer(ch chan<- int, name string) {
	for {
		// sleep at some random time
		sleep()

		// generate random time
		n := rand.Intn(100)

		// send the message
		fmt.Printf("%s: sending %d\n", name, n)
		ch <- n
	}
}

// consumer
// read from channel
func consumer(ch <-chan int, name string) {
	for n := range ch {
		fmt.Printf("consumer %s <- %d\n", name, n)
	}
}

func fanOut(chA <-chan int, chB, chC chan<- int) {
	for n := range chA {
		if n < 50 {
			chB <- n
		} else {
			chC <- n
		}
	}
}

func fanIn(chA, chB <-chan int, chC chan<- int) {
	var n int
	for {
		select {
		case n = <-chA:
			chC <- n
		case n = <-chB:
			chC <- n
		}
	}
}

func main() {
	chA := make(chan int)
	chB := make(chan int)
	chC := make(chan int)

	go producer(chA, "A")
	go producer(chB, "B")
	go consumer(chB, "B")
	go consumer(chC, "C")
	fanIn(chA, chB, chC)
	fanOut(chA, chB, chC)
}
