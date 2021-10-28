#!/usr/bin/env python
# coding: utf-8

# # Face Recognition – Unlock Your Computer With Your Face!

# In[ ]:


import cv2
import numpy as np
import time


# In[ ]:


# Load HAAR face classifier
face_classifier = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')


# In[ ]:


# Load functions
def face_extractor(img):
    # Function detects faces and returns the cropped face
    # If no face detected, it returns the input image
    
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)              #Its a method used to convert an image from one color space to another

    #It detects objects of different sizes in the input image and returns rectangles positioned on the faces.
    #Ist argument-Image
    #IInd - Scale factor (How much the image size will be reduced at each image scale)
    #IIIrd - minNeighbours(how many nieghbours each rectangle should have)
    faces = face_classifier.detectMultiScale(gray, 1.3, 5)
    
    if faces is ():
        return None
    
    # Crop all faces found
    #x,y-are pixel location of faces.
    #w,h are width and height of faces.
    for (x,y,w,h) in faces:
        cropped_face = img[y:y+h, x:x+w]

    return cropped_face


# In[ ]:


# Initialize Webcam
cap = cv2.VideoCapture(0)
count = 0


# In[ ]:


# Collect 100 samples of your face from webcam input
while True:

    ret, frame = cap.read()
    if face_extractor(frame) is not None:
        count += 1
        face = cv2.resize(face_extractor(frame), (200, 200))
        face = cv2.cvtColor(face, cv2.COLOR_BGR2GRAY)

        # Save file in specified directory with unique name
        file_name_path = './faces/user/' + str(count) + '.jpg'
        cv2.imwrite(file_name_path, face)
        
        # Put count on images and display live count
        cv2.putText(face, str(count),ohkk (50, 50), cv2.FONT_HERSHEY_COMPLEX, 1, (0,255,0), 2)
        cv2.imshow('Face Cropper', face)
        time.sleep(0.1)
        
    else:
        print("Face not found")
        pass

    if cv2.waitKey(1) == 13 or count == 100: #13 is the Enter Key
        break
        
cap.release()
cv2.destroyAllWindows()      
print("Collecting Samples Complete")


# In[ ]:


cap.release()


# # Step 2 - Train model

# In[ ]:


import cv2
import numpy as np
from os import listdir
from os.path import isfile, join    #isfile is the function used for checkong whether the file exit in the specified path or not.
#join is used to join one or more path components intelligently.


# In[ ]:


# Get the training data we previously made
data_path = './faces/user/'
onlyfiles = [f for f in listdir(data_path) if isfile(join(data_path, f))]


# In[ ]:


# Create arrays for training data and labels
Training_Data, Labels = [], []


# In[ ]:


# Open training images in our datapath
# Create a numpy array for training data
for i, files in enumerate(onlyfiles):
    image_path = data_path + onlyfiles[i]
    images = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    Training_Data.append(np.asarray(images, dtype=np.uint8))
    Labels.append(i)


# In[ ]:


# Create a numpy array for both training data and labels
Labels = np.asarray(Labels, dtype=np.int32)


# In[ ]:


# Initialize facial recognizer
# model = cv2.face.createLBPHFaceRecognizer()
# NOTE: For OpenCV 3.0 use cv2.face.createLBPHFaceRecognizer()
# pip install opencv-contrib-python
# model = cv2.createLBPHFaceRecognizer()

vimal_model  = cv2.face_LBPHFaceRecognizer.create()
# Let's train our model 
vimal_model.train(np.asarray(Training_Data), np.asarray(Labels))
print("Model trained sucessefully")


# In[ ]:





# In[ ]:


os.environ["SenderMail"] = "ryash1921@gmail.com"


# In[ ]:





# # Send Mail

# In[ ]:


import smtplib
import os
import getpass
import imghdr
from email.message import EmailMessage

def send_email():
    
    message = EmailMessage()
    
    
    
    SenderMail = os.environ.get("SenderMail")
    #SenderPass = os.environ.get("SenderPass")
    #Recvmail = os.environ.get("Recvmail")
    print(SenderMail)
    #print(SenderPass)
    #print(Recvmail)
    
    #SenderMail = "@gmail.com"
    #SenderMail = str(input("Enter sender mail:"))
    SenderPass = str(getpass.getpass("Enter sender pass:"))
    #RecvMail = str(input("Enter receiver mail"))
    Recvmail = os.environ.get("SenderMail")
    
    
    
    print("Sending mail....")
    
    message['subject'] = "This is text code by pratik"
    message['from'] = SenderMail
    message['to'] = Recvmail
    message.set_content("Welcome to Face recognition app" )#it will only display if html content is not visible
    html_message = open("demo.html").read()
    message.add_alternative(html_message , subtype = "html")
    
    with open("./image/Crop.jpg" , "rb") as attach_file:
        image_name = attach_file.name
        image_type = imghdr.what(attach_file.name)
        image_data = attach_file.read()
        
    message.add_attachment(image_data , maintype = "image",
                          subtype = image_type , filename = "FaceLock.png"
                          )
    
    with smtplib.SMTP_SSL("smtp.gmail.com",465) as smtp:#to connect with gmail server
        smtp.login(SenderMail,SenderPass)
        smtp.send_message(message)
        
    print("Mail Sent sucessfully")
    
#send_email()


# In[ ]:


import smtplib
import os
import getpass
import imghdr
from email.message import EmailMessage


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:


cap.release()


# In[ ]:





# # Send Whats App Message

# In[ ]:


import pywhatkit              #pywhatkit library is used for whatsapp operation using python
from datetime import datetime #datetime module to get current time

def wpmsg():
    now = datetime.now()           # Get current time
    hr = int(now.strftime("%H"))   # Current Hour
    min = int( now.strftime("%M"))  # Current mint
    
    pywhatkit.sendwhatmsg("+919156566687","Hi Pratik , Someone tried to access your app", hr,min+1 ,wait_time=10)


# In[ ]:





# # Access

# In[ ]:


def access():
    if FaceDetect == 50:
        unlock = cv2.imread("unlock.jpg")
        
        cv2.putText(unlock, "Access", (45, 50) , cv2.FONT_HERSHEY_COMPLEX, 1, (0,0,255), 2)
        cv2.putText(unlock, "Granted", (45, 100) , cv2.FONT_HERSHEY_COMPLEX, 1, (0,0,255), 2)
        cv2.imshow("lock" , unlock)
        cv2.waitKey(2000)
        cv2.destroyAllWindows()
        print("Launching aws infrastructure with terraform")
        print("Installing required plugins")
        stream = os.popen('terraform init')
        output = stream.readlines()
        #output
        for line in output:
            print(line.strip())
            
        print("Deploying infrastructure")
        stream = os.popen('terraform apply')
        output = stream.readlines()
        #output
        for line in output:
            print(line.strip())
        
            
            
        print("Infra deployed")
        
        
    elif Anon == 120:
        lock = cv2.imread("lock.jpg")
        cv2.putText(lock, "Access", (45, 50) , cv2.FONT_HERSHEY_COMPLEX, 1, (0,0,255), 2)
        cv2.putText(lock, "Denied", (45, 100) , cv2.FONT_HERSHEY_COMPLEX, 1, (0,0,255), 2)
        cv2.imshow("lock" , lock)
        cv2.waitKey(2000)
        cv2.destroyAllWindows()
        cv2.imshow("lock" , image)
        cv2.waitKey(2000)
        cv2.destroyAllWindows()
        cimg1 = image[y:y+h, x:x+w,  : ]
        cv2.imwrite("./image/Crop.jpg",cimg1)  
        print("We are sending mail")
        send_email()
        print("EMail sent sucessfully")


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




