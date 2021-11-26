import cv2

capturaVideo = cv2.VideoCapture(0)

if not capturaVideo.isOpened():
    print("No se enconctró ninguna cámara")
    exit()

while True:
    tipo, camara = capturaVideo.read()
    gris = cv2.cvtColor(camara, cv2.COLOR_BGR2GRAY)

    tipo,umbral = cv2.threshold(gris, 100, 255, cv2.THRESH_BINARY)
    contorno, jerarquia = cv2.findContours(umbral, cv2.RETR_LIST ,cv2.CHAIN_APPROX_SIMPLE,)
    cv2.drawContours(gris, contorno, -1,(251,60,50),2)

    cv2.imshow("En Vivo", gris)
    if cv2.waitKey(1) == ord("q"):
        break

capturaVideo.release()
cv2.destroyAllWindows()