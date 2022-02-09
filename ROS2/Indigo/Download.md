## ROS Basic Install
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu trusty main" > /etc/apt/sources.list.d/ros-latest.list'
<br>
wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
<br>
sudo apt-get update
<br>
sudo apt-get install ros-indigo-desktop-full python-rosinstall
<br>
sudo rosdep init
<br>
rosdep update
<br>
echo "source /opt/ros/indigo/setup.bash" >> ~/.bashrc
<br>
source ~/.bashrc
<br>
sudo apt-get install synaptic
<br>
