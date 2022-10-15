package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"log"
	"strings"
)

// CSV : csv
type CSV struct {
	Name     string `json:"name"`
	Nickname string `json:"nickname"`
	Text     string `json:"text"`
}

func checkErr(err error) {
	if err != nil {
		log.Panic("ERROR: " + err.Error())
	}
}

func main() {
	//without file
	var csvFile = strings.NewReader(`name;nickname;text
	Valéria;Valchan;has been here!`)

	// with file
	//csvFile, err := os.Open("test.csv") // must create test.csv file
	//checkErr(err)

	reader := csv.NewReader(bufio.NewReader(csvFile))
	reader.Comma = ';'

	var person []CSV

	for {
		line, err := reader.Read()
		if err == io.EOF {
			break
		} else if err != nil {
			checkErr(err)
		}
		person = append(person, CSV{
			Name:     line[0],
			Nickname: line[1],
			Text:     line[2],
		})
	}

	// personJSON, err := json.Marshal(person) //convert to JSON
	// checkErr(err)
	// fmt.Println(string(personJSON)) //show data from csv
	// //[{"name":"name","nickname":"nickname","text":"text"},{"name":"Valéria","nickname":"Valchan","text":"has been here!"}]

	fmt.Println(person[1].Nickname + " " + person[1].Text)
	// Valchan has been here!
}
