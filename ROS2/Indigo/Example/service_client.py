#!/usr/bin/env python

import rospy

from basics.srv import WordCount

import sys

rospy.init_node('service_client')

# 서버에서 서비스가 광고될 때까지 대기
rospy.wait_for_service('word_count')

# 지역 proxy 설정
word_counter = rospy.ServiceProxy('word_count', WordCount)

words = ' '.join(sys.argv[1:])

word_count = word_counter(words)

print words, '->', word_count.count
