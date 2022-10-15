package main

import (
	"crypto/tls"
	"fmt"
	"log"
	"net/smtp"
	"strings"
)

func main() {
	sendMail("...@gmail.com", []string{"bar@foo.com", "foo@bar.com"}, "Hello World")
	fmt.Println("Email successfully sent!")
}

func checkErr(err error) {
	if err != nil {
		log.Panic("ERROR: " + err.Error())
	}
}

func sendMail(from string, to []string, body string) {
	servername := "smtp.gmail.com:465"  //server SMTP and PORT
	host := "smtp.gmail.com" //host
	pass := "examplePass"
	auth := smtp.PlainAuth("Valchan", from, pass, host) //autenticação
	tlsConfig := &tls.Config{
		InsecureSkipVerify: true,
		ServerName:         host,
	}
	toHeader := strings.Join(to, ",")
	msg := "From: " + from + "\n" + "To: " + toHeader + "\n" + "Subject: Hello World\n\n" + body

	conn, err := tls.Dial("tcp", servername, tlsConfig)
	checkErr(err)

	c, err := smtp.NewClient(conn, host)
	checkErr(err)

	err = c.Auth(auth)
	checkErr(err)

	err = c.Mail(from)
	checkErr(err)

	for _, addr := range to {
		err = c.Rcpt(addr)
		checkErr(err)
	}

	w, err := c.Data()
	checkErr(err)

	_, err = w.Write([]byte(msg))
	checkErr(err)

	err = w.Close()
	checkErr(err)

	c.Quit()
}
