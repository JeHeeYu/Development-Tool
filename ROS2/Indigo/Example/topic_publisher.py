# 운영체제에게 파이썬 파일 확인 및 파이썬 인터프리터로 전달
#!/usr/bin/env python 

# package.xml에 msgs 의존성 추가
# <depend>std_msgs</depend>
import rospy
from std_msgs.msg import In32

# 노드 초기화
rospy.init_node('topic_publisher')

# Publisher를 통하여 토픽 광고
pub = rospy.Publisher('coutner', Int32)

rate = rospy.Rate(2)
count = 0

# 반복문을 이용하여 count 값 발행
while not rospy.is_shutdown():
  pub.publish(count)
  count += 1
  rate.sleep()
