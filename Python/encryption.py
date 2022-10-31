
def create_key(name, sid, age):
    id_sum = 0
    for i in sid:
        id_sum += int(i)

    
    mod_sum_age = id_sum % int(age)

    sid = int(sid)
    if mod_sum_age > 9:
        mod_sum_age = mod_sum_age - 10
    
    if mod_sum_age > 0:
        sid = sid << mod_sum_age
    else:
        sid = sid >> 1

    key = str(sid)+str(age)+str(len(name))
    with open("mykey.txt", "w") as w:
        w.write(key)
        w.close()

def encryption_steps():
    with open("mykey.txt", "r") as r:
        key = r.read()
        r.close()

    lenth_of_key = len(key)
    sum_of_digits = 0
    for i in key:
        sum_of_digits += int(i)

    avg = sum_of_digits//lenth_of_key

    return avg

def read_plain_text():
    with open("plain.txt", "r") as txt_file:
        data = txt_file.read()
        txt_file.close()
    print(data)

def import_data(my_file):
    try:
        with open(my_file, "r") as input_file:
            my_file_data = input_file.readlines()
            input_file.close()
    except:
        print("file does not exists...")
        return -1
    data_list = list()
    for val in my_file_data:
        data_list.append(val.rstrip("\n"))
    return data_list


def check_index_range(index):
    return index % 26
def check_number_lst_index(index):
    return index % 10

def encrypt_decrypt(data, key):

    alphabet_lst = 'abcdefghijklmnopqrstuvwxyz'
    number_lst = "0123456789"
    out_put_list = list()
    for val in data:
        temp = ""
        for i in val:
            if i == " ":
                temp += " "
            elif not i.isdigit():
                index = alphabet_lst.find(i)
                temp = temp+alphabet_lst[check_index_range(index + key)]
            else:
                index = number_lst.find(i)
                temp = temp+number_lst[check_number_lst_index(index + key)]
        out_put_list.append(temp)

    return out_put_list

def mix_key_data(encrypted_list):
    with open("mykey.txt", "r") as r:
        key = r.read()
        r.close()
    key_length = len(key)
    output_list = list()
    i = 0
    for val in encrypted_list:
        temp = ""
        for j in val:
            if i > key_length-1:
                i = 0
            temp += j + key[i]
        output_list.append(temp)
    

    return output_list

def encrypt(data):
    read_plain_text()
    create_key(name=data[0], sid=data[1], age=data[2])
    key_steps = encryption_steps()
    encrypted_list = encrypt_decrypt(data, key_steps)
    key_added = mix_key_data(encrypted_list)

    with open("cipher.txt", "w") as cipher_writer:
        cipher_writer.write(key_added[0]+"\n")
        cipher_writer.write(key_added[1]+"\n")
        cipher_writer.write(key_added[2]+"\n")

    cipher_writer.close()


def decrypt():
    data = import_data("cipher.txt")
    temp = list()
    for val in data:
        temp.append(val[0::2])
    data = temp
    
    key_steps = encryption_steps()
    decrypted_list = encrypt_decrypt(data, key_steps*-1)
    with open("original.txt", "w") as cipher_writer:
        cipher_writer.write(decrypted_list[0]+"\n")
        cipher_writer.write(decrypted_list[1]+"\n")
        cipher_writer.write(decrypted_list[2]+"\n")
        cipher_writer.close()



def main():
    id_num = input("Enter your ID :>> ")
    file_name = id_num+".txt"
    data = import_data(file_name)
    if data == -1:
        return

    while True:
        choice = int(input("Enter 1 to ENCRYPT, 2 to DECRYPT and 0 to EXIT \n:>> "))
        if choice == 0:
            break
        elif choice == 1:
            encrypt(data)
        else:
            decrypt()

if __name__ == '__main__':
    main()