package error

func Err(e error) {
	if e != nil {
		panic("failed to establish env")
	} else {
		print("success")
	}
}

// no return type
