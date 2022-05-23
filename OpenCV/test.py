import cv2 as cv
import numpy as np

from flask import *
from common import *
from logging.config import dictConfig

jehee = True

dictConfig({
    'version': 1,
    'formatters': {
        'default': {
            'format': '[%(asctime)s] %(levelname)s in %(module)s: %(message)s',
        }
    },
    'handlers': {
        'file': {
            'level': 'INFO',
            'class': 'logging.handlers.RotatingFileHandler',
            'filename': 'test_error.log',
            'maxBytes': 1024 * 1024 * 5,  # 5 MB
            'backupCount': 5,
            'formatter': 'default',
        },
    },
    'root': {
        'level': 'INFO',
        'handlers': ['file']
    }
})

app = Flask(__name__)

cap = cv.VideoCapture(CAMERA_PATH)  

def gen_frames():
  if(jehee == True):
    while True:
      print("jehee : ", jehee)
      ret, frame = cap.read()
      if(cap == False):
        print("Server Camera Read is Fail")
      else:      
        cv.circle(frame,(256,256),50,(0,255,0),-1)
        ret, buffer = cv.imencode('.jpg', frame)
        frame = buffer.tobytes()
        yield (b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')
  else:
    print("IMAGE_SHOW is zero")

@app.route('/')
def index():
  return render_template(template_name_or_list='index.html')    

@app.route('/video_feed')
def video_feed():
  return Response(gen_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/calculate', methods=['POST', 'GET'])
def calculate(num=None):
  if request.method == 'POST':
    #temp = request.form['num']
    IMAGE_SHOW = 0
  else:
    temp = None

  return render_template(template_name_or_list='index.html')    


@app.route("/ajax_page", methods=['POST'])
def ajax_page():
  jehee = False
  data = request.get_json()
  print(data)
  calc_result = calc(data['inputdata'])
  rdata = {}
  rdata['inputdata']=data['inputdata']
  rdata['rlt']=calc_result
  print(rdata)
  print("jehee : ", jehee)
  return jsonify(rdata)

def calc(inputdata):
	return str(eval(inputdata))



if __name__ == '__main__':
  app.run(host='0.0.0.0')
  
