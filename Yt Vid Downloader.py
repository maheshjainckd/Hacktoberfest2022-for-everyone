from tkinter import *
from pytube import YouTube

window = Tk()
window.geometry("600x700")
window.config(bg="red")
window.title("Youtube Video Downloader by Tharuka")

youtube_logo = PhotoImage(file="yt.png")
window.iconphoto(False, youtube_logo)

Label(window, text="Video Downloader", font=("Arial 30 bold"), bg="lightgreen").pack(padx=5, pady=50)

video_link = StringVar()

Label(window, text="Enter the Link : ", font=("Arial",25,"bold")).place(x=170, y=150)

Entry_link = Entry(window, width=50, font=35 , textvariable=video_link, bd=4).place(x=60, y=200)

def video_download():
    video_url = YouTube(str(video_link.get()))
    videos = video_url.streams.first()
    videos.download()

    Label(window, text="Download Completed  !!!", font=("Arial",35,"bold"),bg="lightpink",fg="Black").place(x=60, y=350)
    Label(window, text="Check out Download Folder", font=("Arial", 30, "bold"), bg="yellow").place(x=60, y=400)

Button(window, text=".DOWNLOAD.", font=("Arial", 25, "bold"), bg="lightblue", command=video_download).place(x=180, y=300)

window.mainloop()