alphabet = ["a","b","c","d","e","f","g","h","i","j","k"
,"l","m","n","o","p","q","r","s","t","u","v","w","x","y",
"z","a","b","c","d","e","f","g","h","i","j","k"
,"l","m","n","o","p","q","r","s","t","u","v","w","x","y",
"z"]

def encrypt(txt, shft):
    cipher_text = ""
    for i in txt:
        position = alphabet.index(i)
        new_position = position + shft
        cipher_text += alphabet[new_position]
    print(f"The encoded string is {cipher_text}")

def decrypt(cipher_text, shft):
    original_text = ""
    for j in cipher_text:
        position = alphabet.index(j)
        new_position = position - shft
        original_text += alphabet[new_position]
    print(f"The decoded string is {original_text}")

#if direction == "encode":
    #encrypt(txt = text, shft = shift)
#elif direction == "decode":
    #decrypt(cipher_text = text, shft = shift)

def caesar(direct, txt, shft):
    new_text = ""
    if direct == "decode":
            shft *= -1
    for t in txt:
        if t in alphabet:
            position = alphabet.index(t)
            new_position = position + shft
            new_text += alphabet[new_position]
        else:
            new_text += t
    print(f"The {direct}d string is {new_text}")

should_continue = True
while should_continue:
    direction = input("Type 'encode' to encrypt or type 'decode' to decrypt: ")
    text = input("Type your message: ").lower()
    shift = int(input("Type the shift number: "))
    shift = shift % 25
    caesar(direct = direction, txt = text, shft = shift)
    result = input("Do you want to continue? Yes or No: ")
    if result == "No":
        should_continue = False
        print("Good bye")

