import cv2

vcap = cv2.VideoCapture(0) 

vcap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
vcap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480) 

casecade_xml = 'haarcascade_frontalface_default.xml'
face_cascade = cv2.CascadeClassifier(casecade_xml)


def videoDetector(vcap, face_cascade) :
    faces_cnt = 0 
    while True :

        ret, frame = vcap.read()
        frame = cv2.flip(frame, 1) 
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.1, 5)

        if faces_cnt != len(faces) :
            faces_cnt = len(faces)
            if faces_cnt != 0 :
                print("현재 검출된 얼굴 수 : ", str(faces_cnt))

        if len(faces) :
            for  x, y, w, h in faces :
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255,255,255), 2, cv2.LINE_4)

        cv2.imshow("VideoFrame", frame)

        if cv2.waitKey(1) == 27 :
            vcap.release()          
            cv2.destroyAllWindows() 
            break;                  

videoDetector(vcap, face_cascade)
