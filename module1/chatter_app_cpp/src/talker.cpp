#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class ChatterPublisher : public rclcpp::Node
{
public:
  ChatterPublisher()
  : Node("chatter_publisher"), count_(0)
  {
     //10 = Quality of Service (QoS) history depth 
     //Queue size (how many messages are stored if the network is slow).
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);//Default QoS: KEEP_LAST, RELIABLE, VOLATILE.
    

     message_ = std_msgs::msg::String();

    timer_ = this->create_wall_timer(500ms, std::bind(&ChatterPublisher::timer_callback,this));
  }

private:

  void timer_callback(){
        
        message_.data = "Hello, world! " + std::to_string(this->count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message_.data.c_str());
        this->publisher_->publish(message_);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_; //unsigned long size_t
  std_msgs::msg::String message_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ChatterPublisher>());
  rclcpp::shutdown();
  return 0;
}