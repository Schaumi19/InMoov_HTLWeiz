import speech_recognition as sr
from google.cloud import speech


def recognize_keyword(keyWord):
    while True:
        # obtain audio from the microphone
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Listening!")
            audio = r.listen(source)
            r.adjust_for_ambient_noise(source)

        # recognize speech using Google Speech Recognition
        try:
            text = r.recognize_google(audio)
            print(text) 
            if keyWord.lower() in text.lower():
                print("Word detected")
        except sr.UnknownValueError:
            print("Could not understand audio")
        except sr.RequestError as e:
            print("Could not request results from Google Speech Recognition service; {0}".format(e))
            
    




