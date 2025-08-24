#include "robot_kinematics/tutlesim_rotation_node.hpp"

using namespace std::chrono_literals;

using std::placeholders::_1;


TutlesimRotationNode::TutlesimRotationNode() : Node("chatter_publisher")
{
    turtle1_sub_ =
        this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&TutlesimRotationNode::turtle1_pose_cb, this, _1));

    turtle2_sub_ =
        this->create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, std::bind(&TutlesimRotationNode::turtle2_pose_cb, this, _1));

    timer_ = this->create_wall_timer(500ms, std::bind(&TutlesimRotationNode::timer_callback, this));
}

void TutlesimRotationNode::timer_callback()
{
    float delat_theta=last_turtle2_pose_.theta-last_turtle1_pose_.theta;
    float Tx= last_turtle2_pose_.x*cos(delat_theta)-last_turtle2_pose_.y*sin(delat_theta);
    float Ty= last_turtle2_pose_.x*sin(delat_theta)+last_turtle2_pose_.y*cos(delat_theta)

    RCLCPP_INFO_STREAM(this->get_logger(), "Rotation vector between Turtle1 and Turtle2: \n"<<
    "Tx: "<<Tx <<"\n" <<
    "Ty: "<<Ty <<"\n");

}

void TutlesimRotationNode::turtle1_pose_cb(const turtlesim::msg::Pose &msg)
{
 last_turtle1_pose_=msg;
}

void TutlesimRotationNode::turtle2_pose_cb(const turtlesim::msg::Pose &msg)
{
    last_turtle2_pose_=msg;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TutlesimRotationNode>());
    rclcpp::shutdown();
    return 0;
}