# 운영체제에게 파이썬 파일 확인 및 파이썬 인터프리터로 전달
#!/usr/bin/env python 

# package.xml에 msgs 의존성 추가
# <depend>std_msgs</depend>
import rospy
from std_msgs.msg import In32

# 이벤트 구동 시스템 콜백 함수 정의 및 메시지 출력
def callback(msg):
  print msg.data

# 노드 초기화
rospy.init_node('topic_publisher')

# 'counter' 토픽 구독
sub = rospy.Subscriber('counter', Int32, callback)

# 구독이 시작되면 ROS에게 제어권을 넘김
rospy.spin()
