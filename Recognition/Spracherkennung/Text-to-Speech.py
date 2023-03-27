# Import Google Text-to-Speech library
from gtts import gTTS
import os

mytext = 'Hello World!'
language = 'de'

# Passing the text and language to the engine
mySpeech = gTTS(text=mytext, lang=language, slow=False)

mySpeech.save("test.mp3") # Saving the converted audio in a mp3 file

os.system("test.mp3") # Playing the converted file
