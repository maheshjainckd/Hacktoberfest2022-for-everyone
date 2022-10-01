from gtts import gTTS
from pygame import mixer
from variables import *


def read_file(inputTextFilePath):
    # Using readlines()
    file1 = open(inputTextFilePath, 'r')
    Lines = file1.readlines()

    count = 0
    lines = []

    for line in Lines:
        count += 1
        lines.append(line.replace('\n', ''))
        print("Line{}: {}".format(count, line.strip()))

    convertTextToSpeech(str(lines).replace('\n', ''), outputAudioFilePath)


def convertTextToSpeech(text, outputAudioFilePath):
    tts = gTTS(text)
    tts.save(outputAudioFilePath)
    mixer.init()
    mixer.music.load(outputAudioFilePath)
    mixer.music.play()


read_file('input.txt')
