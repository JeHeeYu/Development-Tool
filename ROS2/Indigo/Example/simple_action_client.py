#! /usr/bin/env python

import rospy
import actionlib
from basics.msg import TimerAction, TimerGoal, TimerResult

rospy.init_node('timer_action_client')

# SimpleActionClient 생성 함수
# 첫 번째 인자 timer : 액션 클라이언트의 이름으로 클라이언트가 서버와 통ㅅ니할 때 사용하는 토픽을 결정할 때 사용
# 두 번째 인자 TimerAction : 액션의 자료형으로, 통신할 서버와 동일해야 함
client = actionlib.SimpleActionClient('timer', TimerAction)

# 서버가 동작할 때까지 대기
client.wait_for_server()

# TimerGoal 자료형 객체 goal 생성
goal = TimerGoal()

# 타이머가 대기해야 할 시간을 5초로 설정
goal.time_to_wait = rospy.Duration.from_sec(5.0)

# 서버로 목표 메시지 전송
client.send_goal(goal)

# 서버로부터 결과가 도착하면 결과를 검색하고, time_elapsed 필드 출력
client.wait_for_result()
print('Time elapsed : %f'%(client.get_result().time_elapsed.to_sec()))
