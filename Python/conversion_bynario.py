#Conversion of a number system to another number system (Decimal, Binary, Hexadecimal, Octal)

def converter_binario_para_hexadecimal(number):
    typed_number = number
    quotient = 1
    lista = []

    while quotient >= 1:
     rest = number%2
     lista.insert(0,rest)
     quotient = number // 2
     number = quotient

     binary = ''.join([str(item) for item in lista])
    print("The number",typed_number,", when converted to binary, is:",binary)

def converter_decimal_para_binario(number):
    typed_number = number
    quotient = 1
    lista = []

    while quotient >= 1:
     resto = number%2
     lista.insert(0,resto)
     quotient = number // 2
     number =  quotient

     binary = ''.join([str(item) for item in lista])
    print("The number",typed_number,", when converted to binary, is:",binary)


def converter_binario_para_decimal(number):
    typed_number = len(str(number))
    typed_value = number
    decimal = 0
    i = 0

    while  typed_number>= 0:
     rest = number % 10
     decimal = decimal + (rest * (2**i))
     typed_number =  typed_number - 1
     i = i + 1
     number = number // 10

    print("The typed (binary) number",typed_value,", in decimal base, is:",decimal)


if __name__ == "__main__":
    op = 0
    while(op!= 4):
     print("Enter which conversion you want to do")
     print(" 1: From binary to decimal\n 2: From decimal to binary\n 3: From binary to hex")
     op = int(input("op = "))
     if op == 1:
       number = int(input("Enter the binary number to convert to decimal"))
       converter_binario_para_decimal(number)
     elif op == 2:
        number = int(input("Enter the number in decimal to convert to binary"))
        converter_decimal_para_binario(number)
     elif op == 3:
        number = int(input("Enter the number in decimal to convert Octal "))
        converter_decimal_para_binario(number)