#include "rclcpp/rclcpp.hpp"
#include <chrono>

/* This example creates a basic ROS 2 node called "simple_node" 
that outputs a startup message when initialized. */

using namespace std::chrono_literals;

class SimpleNode : public rclcpp::Node
{
  public:
    SimpleNode()
    : Node("simple_node")
    {
      RCLCPP_INFO(this->get_logger(), "Simple node Is starting up...");

      timer_= this->create_wall_timer(500ms, std::bind(&SimpleNode::timer_callback, this));

    }


  private:
      void timer_callback()
      {
        RCLCPP_INFO(this->get_logger(), "Simple node Is Running Now...");
      }

    rclcpp::TimerBase::SharedPtr timer_;

  };
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleNode>());
  rclcpp::shutdown();
  return 0;
}