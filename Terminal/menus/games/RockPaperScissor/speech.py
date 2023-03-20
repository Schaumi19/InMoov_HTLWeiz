from gtts import gTTS
import os
import speech_recognition as sr
from google.cloud import speech


def speak(phrase: str, language: str):
    phrase_mp3 = gTTS(text=phrase, lang=language, slow=False)
    phrase_mp3.save("audio.mp3")
    os.system("audio.mp3")

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
                break
        except sr.UnknownValueError:
            print("Could not understand audio")
        except sr.RequestError as e:
            print("Could not request results from Google Speech Recognition service; {0}".format(e))

if __name__ == '__main__':
    phrase = input("Please enter a phrase to say: ")
    lang = input("Please enter the language to say that phrase (short form like: en, de, es): ")
    speak(phrase, lang)


# Now he CAN speak spanish!
