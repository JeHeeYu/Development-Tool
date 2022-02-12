# 운영체제에게 파이썬 파일 확인 및 파이썬 인터프리터로 전달
#!/usr/bin/env python 

# catkin에서 생성된 코드 import
import rospy
from basics.srv import WordCount,WordCountResponse

# WordCountRequest 자료형을 가지는 인자를 받아 WordCountResponse 자료형 반환
def count_words(request):
  return WordCountResponse(len(request.words.split()))

# 노드 초기화
rospy.init_node('topic_publisher')

# word_count의 이름, WordCount의 자료형을 죽 서비스를 구현하는 count_words 콜백 지정후 서비스 광고
service = rospy.Service('word_count', WordCount, count_words)

rospy.spin()
