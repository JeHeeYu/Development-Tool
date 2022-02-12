#! /usr/bin/env python

# ros 관련 import
import rospy
import actionlib

# ros 자료형 import
from basics.msg import TimerAction, TimerGoal, TimerResult, TimerFeedback


def do_timer(goal):
	# 현재 시간 저장
	start_time = time.time()
	
	# 피드백 발생 횟수 변수 초기화
	update_count = 0
	
	# 오류 확인 조건문으로 타이머 시간 제한 설정
	if goal.time_to_wait.to_sec() > 60.0:
		result = TimerResult()
		result.time_elapsed = rospy.Duration.from_sec(time.time() - start_time)
		result.updates_sent = update_count
		server.set_aborted(result, "Timer aborted due to too-long wait")
		return
	
	# 선점 확인 및 피드백 반복문
	while(time.time() - start_time) < goal.time_to_wait.to_sec():
		if server.is_preempt_requested():
			result = TimerResult()
			result.time_elapsed = \
				rospy.Duration.from_sec(time.time() - start_time)
			result.updates_send = update_count
			server.set_preempted(result, "Timer preempted")
			return

		# TimerFeedBack 자료형을 사용하여 피드백을 보냄
		feedback = TimerFeedBack()
		feedback.time_elapsed = rospy.Duration.from_sec(time.time() - start_time)
		feedback.time_remaining = goal.time_to_wait - feedback.time_elapsed
		server.publish_feedback(feedback)
		update_count += 1

		time.sleep(1.0)

	# 성공적으로 일시 정지했다는 것을 클라이언트에게 전송
	result = TimerResult()
	result.time_elapsed = rospy.Duration.from_sec(time.time() - start_time)
	result.updates_send = update_count
	server.set_succeeded(result, "Timer completed successfully")

# 노드 초기화 후 액션 서버르 생성하고 목표 대기
rospy.init_node('timer_action_server')
server = actionlib.SimpleActionServer('timer', TimerAction, do_timer, False)
server.start()
rospy.spin()
