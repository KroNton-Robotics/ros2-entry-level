#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"

class TutlesimRotationNode : public rclcpp::Node
{

public:
    TutlesimRotationNode(/* args */);
    ~TutlesimRotationNode();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle1_sub_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle2_sub_;
    turtlesim::msg::Pose last_turtle1_pose_;
    turtlesim::msg::Pose last_turtle2_pose_;

    void timer_callback();
    void turtle1_pose_cb(const turtlesim::msg::Pose &msg);
    void turtle2_pose_cb(const turtlesim::msg::Pose &msg);
};
