/*****   ROS 설치 전 설정 항목   *****/

/*   인코딩 언어 체크   */
locale  
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
locale  
sudo apt update && sudo apt install curl gnupg2 lsb-release -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg
sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
sudo apt update
sudo apt install ros-foxy-desktop -y // ROS 설치 명령어

/*   Python pip 설치 명령어   */
sudo apt install -y python3-pip
pip3 install -U argcomplete

/*   센서 및 통신에 장애를 일으키는 문제 해결   */
sudo apt-get purge modemanager
sudo adduser [User Name]
sudo usermod -aG sudo [User Name]

/*   ROS 설치 후 update에서 NO_PUBKEY 에러가 발생할 경우   */
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys [Key Number]

/*   ROS 추가 패키지 설치   */
sudo apt install ros-foxy-rqt*
sudo apt install ros-foxy-image-view
sudo apt install ros-foxy-navigation2 ros-foxy-nav2-bringup 
sudo apt install ros-foxy-joint-state-publisher-gui
sudo apt install ros-foxy-xacro
rosdep install -i --from-path src --rosdistro foxy -y

/*   ROS 정상 설치 확인 테스트   */
// Terminal 1
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp talker
// Terminal 2
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_py listener

=============================================================================================================================

/*****   Gazebo 11 설치   *****/

/*   설치 명령어   */
sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
sudo apt update

sudo apt install gazebo11 libgazebo11-dev -y // 가제보 설치
sudo apt install ros-foxy-gazebo-ros-pkgs -y // 가제보 ROS 패키지 설치
sudo ubuntu-drivers autoinstall     // 그래픽 드라이버 자동 설치
sudo apt install nvidia-driver-440 -y   // 그래픽 드라이버 수동 설치
ubuntu-drivers devices      // 그래픽 드라이버 확인
gazebo // 가제보 실행 명령어

=============================================================================================================================

/*****   개발환경 셋업   *****/

/*   Colcon Build System 설치   */
sudo apt update
sudo apt install python3-colcon-common-extensions

/*   Workspace 설정   */
source /opt/ros/foxy/setup.bash
mkdir -p ~/ros2_workspace/src

/*   Tutorial   */
git clone https://github.com/ros/ros_tutorials.git -b foxy-devel

/*   Build   */
colcon build --symlink-install

/*   ROS Alias   */
alias eb='gedit ~/.bashrc'
alias sb='source ~/.bashrc'
alias cba='colcon build --symlink-install'
alias cbp='colcon build --symlink-install --packages-select'
alias killg='killall -9 gzserver && killall -9 gzclient && killall -9 rosmaster'
alias rosfoxy='source /opt/ros/foxy/setup.bash && source ~/gcamp_ros2_ws/install/local_setup.bash'

source /usr/share/colcon_cd/function/colcon_cd.sh
export _colcon_cd_root=~/gcamp_ros2_ws

/*   Turtlesim Test   */

// Terminal 1
rosfoxy
ros2 run turtlesim turtlesim_node
// Terminal 2
rosfoxy
ros2 run turtlesim turtle_teleop_key
