package database

import (
	"fmt"
	"os"

	"VSC/GoLang/JWT/error"
	"VSC/GoLang/JWT/models"

	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/postgres"
	"github.com/joho/godotenv"
)

var DB *gorm.DB

func Connect() {
	e := godotenv.Load(".env")

	error.Err(e)

	dialect := os.Getenv("DIALECT")
	host := os.Getenv("HOST")
	port := os.Getenv("PORT")
	user := os.Getenv("USER")
	dbname := os.Getenv("DBNAME")
	password := os.Getenv("PASSWORD")

	dbURI := fmt.Sprintf("host=%s port=%s user=%s password=%s dbname=%s sslmode=disable", host, port, user, password, dbname)

	connect, gorm_err := gorm.Open(dialect, dbURI)

	error.Err(gorm_err)

	DB = connect

	// defer connect.Close()

	connect.AutoMigrate(&models.User{})
}
