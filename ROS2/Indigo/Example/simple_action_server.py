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

# SimpleActionServer 생성
# 첫 번째 인자 timer : 토픽이 광고될 이름공간을 결정하는 서버의 이름
# 두 번째 인자 TimerAAction : 서버가 처리하는 액션의 자료형
# 세 번째 인자 do_timer : 목표 콜백이며, 위에 정의한 do_timer() 함수
# 네 번째 인자 False : 서버의 자동 시작 여부
server = actionlib.SimpleActionServer('timer', TimerAction, do_timer, False)

# 액션 서버를 생성 후 명시적으로 시작하는 함수
server.start()
rospy.spin()
