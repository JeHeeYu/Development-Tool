#! /usr/bin/env python

import rospy
import time
import actionlib
from basics.msg import TimerAction, TimerGoal, TimerResult, TimerFeedback

# 피드백 메시지를 받을 때 호출될 피드백 함수로, 피드백의 내용 출력
def feedback_cb(feedback):
	print('[Feedback] Time elapsed: %f'%(feedback.time_elapsed.to_sec()))
	print('[Feedback] Time remaining: %f'%(feedback.time_remaining.to_sec()))

# 노드 초기화
rospy.init_node('timer_action_client')
client = actionlib.SimpleActionClient('timer', TimerAction)
client.wait_for_server()

goal = TimerGoal()
goal.time_to_wait = rospy.Duration.from_sec(5.0)

# send_goal 함수 호출 시 feedback 함수를 인자로 전달
#goal.time_to_wait = rospy.Duration.from_sec(500.0)
client.send_goal(goal, feedback_cb=feedback_cb)

#time.sleep(3.0)
#client.cancle_goal()

# 결과 출력
client.wait_for_result()
print('[Result] State: %d'%(client.get_state()))
print('[Result] Status: %s'%(client.get_goal_status_text()))
print('[Result] Time elapsed: %F'%(client.get_result().time_elapsed.to_sec()))
print('[Result] Updates send: %d'%(client.get_result().updates_sent))
