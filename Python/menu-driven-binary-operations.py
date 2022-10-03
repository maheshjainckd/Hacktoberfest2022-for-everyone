import pickle
def Append(l):  
    fwb=open("student1.dat","ab")
    pickle.dump(l,fwb)
    fwb.close()
    print("data written succsessfully to binary file")

def read():
    frb=open("student1.dat","rb")
    l=pickle.load(frb)
    print(l)
    l=pickle.load(frb)
    print(l)
    l=pickle.load(frb)
    print(l)
    l=pickle.load(frb)
    print(l)
    frb.close()

def readall(file):
    frb=open(file,"rb")
    while True:
        try:
            l=pickle.load(frb)
            print(l)
        except EOFError:
            break
    frb.close()


def search_rno(r):
    frb=open("student1.dat","rb")
    found=0
    while True:
        try:
            l=pickle.load(frb)
            if r==l[0]:
                print(l)
                found=1
                break  #because rno is unique
        except EOFError:
            break
    if found==0:
        print("Roll no",r,"does not exist.")
    frb.close()


def search_name(n):
    #[1,'Aakarsh',99]
    frb=open("student1.dat","rb")
    found=0
    while True:
        try:
            l=pickle.load(frb)
            if n==l[1]:   #made changes
                print(l)
                found=1
        except EOFError:
            break
    if found==0:
        print("Name",n,"does not exist.")
    frb.close()


def update(r):
    import os
    frb=open("student1.dat","rb")
    fwb=open("temp.dat","wb")
    found=0
    while True:
        try:
            l=pickle.load(frb)
            if r==l[0]:
                l[1]=input("Enter the new name")
                l[2]=int(input("Enter the new marks"))
                pickle.dump(l,fwb)

                found=1
            else:
                pickle.dump(l,fwb)
        except EOFError:
            break

    frb.close()
    fwb.close()
    os.remove("student1.dat")
    os.rename("temp.dat","student1.dat")

    if found==0:
        print("Roll no",r,"does not exist.")
    else:
        print("Record updated....")
        readall()
    

def delete(r):
    import os
    frb=open("student1.dat","rb")
    fwb=open("temp.dat","wb")
    found=0
    while True:
        try:
            l=pickle.load(frb)
            if r!=l[0]: #record not be deleted
                pickle.dump(l,fwb)
            else:
                found=1
        except EOFError:
            break
    frb.close()
    fwb.close()
    os.remove("student1.dat")
    os.rename("temp.dat","student1.dat")

    if found==0:
        print("Roll no",r,"does not exist.")
    else:
        print("Record deleted....")
        readall()

#to copy records matching the criteria from student1.dat to hundred.dat : copy paste
def copy():
    
    frb=open("student1.dat","rb")
    fwb=open("hundred.dat","wb")
    count=0
    while True:
        try:
            l=pickle.load(frb)
            if l[2]==100: #record not be deleted
                pickle.dump(l,fwb)
                count+=1
            
        except EOFError:
            break
    frb.close()
    fwb.close()
    print(count,"records copied to hundred.dat")
    

#to move records matching the criteria from student1.dat to hundred1.dat : cut paste
def transfer():
    import os
    frb=open("student1.dat","rb") #master file
    fwb1=open("hundred1.dat","wb")#paste
    fwb2=open("temp.dat","wb")    #cut ..will be renamed to student1.dat later

    count=0
    while True:
        try:
            l=pickle.load(frb)
            if l[2]==100: #record not be deleted
                pickle.dump(l,fwb1)
                count+=1
            else:
                pickle.dump(l,fwb2)
        except EOFError:
            break
    frb.close()
    fwb1.close()
    fwb2.close()
    os.remove("student1.dat")
    os.rename("temp.dat","student1.dat")
    print(count,"records moved to hundred1.dat")

def searchmenu():
    while True:
        print("--------------SEARCH MENU----------------")

        print("1. Search by roll no")
        print("2. Search by name")
        print("3. Return to Main Menu")
        ch=int(input("Enter your choice:"))
        if ch==1:
            rno=int(input("Enter the roll no whose record is to be searched:"))
            search_rno(rno)
        elif ch==2:
            nm=input("Enter the name whose record is to be searched:")
            search_name(nm)
        elif ch==3:
            break
        


def mainmenu():
    while True:
    
        print("--------------BINARY FILE OPERATIONS----------------")

        print("1. Append records")
        print("2. Display all records")
        print("3. Search Records")
        print("4. Update Records")
        print("5. Delete Records")
        print("6. Copy Records")
        print("7. Transfer Records")
        print("8. EXIT")
        ch=int(input("Enter your choice:"))
        if ch==1:
            print("Enter the student record")
            rno=int(input("Enter the roll no:"))
            name=input("Enter the name:")
            marks=int(input("Enter the marks:"))
            rec=[rno,name,marks]
            Append(rec)
        elif ch==2:
            readall('student1.dat')
        elif ch==3:
            searchmenu()
        elif ch==4:
            rn=int(input("Enter the roll no whose record is to be updated:"))
            update(rn)
        elif ch==5:
            rn=int(input("Enter the roll no whose record is to be deleted:"))
            delete(rn)
        elif ch==6:
            copy()
        elif ch==7:
            transfer()    
        elif ch==8:
            break
mainmenu()

print("bye bye......")




#search_name('Aakriti')    
#search_rno(1)
#update(4)
#copy()

