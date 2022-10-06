# importing pytube
from pytube import YouTube

link = input("Enter video link:")

yt = YouTube(link)
video = yt.streams.first() # This captures the streams

try: 
    # downloading the video 
    video.download()
    print('Video downloaded') 

except: 
    print("Some Error occured!") 
    
