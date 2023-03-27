import speech_recognition as sr
keyWord = "Game"
while True:
    # obtain audio from the microphone
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening!")
        audio = r.listen(source)
        r.adjust_for_ambient_noise(source)
    # recognize speech using Sphinx
    try:
        print("Sphinx thinks you said " + r.recognize_sphinx(audio))
    except sr.UnknownValueError:
        print("Sphinx could not understand audio")
    except sr.RequestError as e: 
        print("Sphinx error; {0}".format(e))