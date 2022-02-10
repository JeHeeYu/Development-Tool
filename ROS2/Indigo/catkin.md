## Catkin Setting

mkdir -p ~/catkin_ws/src
<br>
cd ~/catkin_ws/src<br>
catkin_init_workspace <br>
cd ~/catkin_ws<br>
catkin_make <br>
<br>
catkin_init_workspace : catkin 작업 공간 초기화 명령어로, init 시 CMakeLists.txt 파일 생성<br>
catkin_make : catkin 관련 make 명령어로, make 시 build, devel, src 폴더 생성<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;build : C++ 사용 시 라이브러리 및 실행 프로그램과 같은 캣킨 작업 결과의 일부를 저장하는 폴더로, 파이썬 사용 시 필요 없음<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;devel : 환경설정 파일로, 실행 시 시스템이 현재 작업 공간과 그 안에 포함된 코드를 사용하도록 설정
