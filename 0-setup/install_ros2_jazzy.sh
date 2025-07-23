#!/bin/bash

# Install ROS 2 Jazzy on Ubuntu

# 1. Set up locale
sudo apt update && sudo apt install locales -y
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

# 2. Verify locale settings
locale

# 3. Add universe repository and update
sudo apt install software-properties-common -y
sudo add-apt-repository universe -y
sudo apt update && sudo apt install curl -y

# 4. Install ROS 2 apt source
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo $VERSION_CODENAME)_all.deb"
sudo dpkg -i /tmp/ros2-apt-source.deb

# 5. Install ROS development tools
sudo apt update && sudo apt install ros-dev-tools -y

# 6. Install ROS 2 Jazzy desktop
sudo apt update
sudo apt upgrade -y
sudo apt install ros-jazzy-desktop -y

echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc

# 8. Source it for the current session
source /opt/ros/jazzy/setup.bash
echo "ROS 2 Jazzy installation complete!"
echo "The environment has been sourced for this session and added to your ~/.bashrc file."
echo "You may need to open a new terminal or run 'source ~/.bashrc' for changes to take effect."
