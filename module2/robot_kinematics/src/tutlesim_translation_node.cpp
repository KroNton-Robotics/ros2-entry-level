#include "robot_kinematics/tutlesim_translation_node.hpp"

using namespace std::chrono_literals;

using std::placeholders::_1;


TutlesimTranslationNode::TutlesimTranslationNode() : Node("chatter_publisher")
{
    turtle1_sub_ =
        this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&TutlesimTranslationNode::turtle1_pose_cb, this, _1));

    turtle2_sub_ =
        this->create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, std::bind(&TutlesimTranslationNode::turtle2_pose_cb, this, _1));

    publisher_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("turtlesim_tf_data", 10);

    timer_ = this->create_wall_timer(500ms, std::bind(&TutlesimTranslationNode::timer_callback, this));
}

TutlesimTranslationNode::~TutlesimTranslationNode()
{
}

void TutlesimTranslationNode::timer_callback()
{
    float Tx= last_turtle2_pose_.x-last_turtle1_pose_.x;
    float Ty= last_turtle2_pose_.y-last_turtle1_pose_.y;

    RCLCPP_INFO_STREAM(this->get_logger(), "Translation vector between Turtle1 and Turtle2: \n"<<
    "Tx: "<<Tx <<"\n" <<
    "Ty: "<<Ty <<"\n");

}

void TutlesimTranslationNode::turtle1_pose_cb(const turtlesim::msg::Pose &msg)
{
 last_turtle1_pose_=msg;
}

void TutlesimTranslationNode::turtle2_pose_cb(const turtlesim::msg::Pose &msg)
{
    last_turtle2_pose_=msg;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TutlesimTranslationNode>());
    rclcpp::shutdown();
    return 0;
}