
from gtts import gTTS
import os


def speak(phrase: str, language: str):
    phrase_mp3 = gTTS(text=phrase, lang=language, slow=False)
    phrase_mp3.save(os.getcwd() + "audio.temp.mp3")
    os.system("mpg123 " + os.getcwd() + "audio.temp.mp3")


if __name__ == '__main__':
    phrase = input("Please enter a phrase to say: ")
    lang = input("Please enter the language to say that phrase (short form like: en, de, es): ")
    speak(phrase, lang)


# Now he CAN speak spanish!
