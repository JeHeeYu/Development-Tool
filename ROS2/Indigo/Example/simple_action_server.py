#! /usr/bin/env python

# 필요한 패키지 import
import rospy
import time
import actionlib

# Timer.action 파일에서 자동으로 생성되는 메시지 클래스 import
from basics.msg import TimerAction, TimerGoal, TimerResult

# 새로운 목표를 수신했을 때 호출되는 함수 정의
# goal의 인자는 Timer.action의 목표 영역에 대응함
def do_timer(goal):

# 표준 파이썬 time.time() 함수를 이용하여 현재 시간 저장
# ROS duration 자료형인 time_to_wait 필드를 초 단위로 변경하여 목표에서 요청한 시간 동안 일시 정지
  start_time = time.time()
  time.sleep(goal.time_to_wait.to_sec())

# TimerResult의 값을 result에 대입
  result = TimerResult()

# 현재 시각에서 시작 시각을 차감하고 ROS duration 자료형으로 변환하여 time_elasped 필드를 채움
  result.time_elapsed = rospy.Duration.from_sec(time.time() - start_time)
  result.updates_send = 0

# set_succeeded를 호출하고 결과를 전송하여 SimpleActionServer에게 결과를 알림
  server.set_succeeded(result)
  
rospy.init_node('timer_action_server')
server = actionlib.SimpleActionServer('timer', TimerAction, do_timer, False)
server.start()
rospy.spin()
