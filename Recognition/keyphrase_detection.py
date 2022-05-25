import speech_recognition as sr
keyWord = "Game"
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
            print("Game Start")
    except sr.UnknownValueError:
        print("Google Speech Recognition could not understand audio")
    except sr.RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))
        

    '''# recognize speech using Sphinx
    try:
        print("Sphinx thinks you said " + r.recognize_sphinx(audio))
    except sr.UnknownValueError:
        print("Sphinx could not understand audio")
    except sr.RequestError as e: 
        print("Sphinx error; {0}".format(e))'''


