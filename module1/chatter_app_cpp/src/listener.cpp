#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;
class ChatterSubscriber : public rclcpp::Node
{
public:
  ChatterSubscriber()
  : Node("chatter_subscriber")
  {
    subscription_ =
      this->create_subscription<std_msgs::msg::String>("chatter", 10, std::bind(&ChatterSubscriber::chatter_callback,this,_1));
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  void chatter_callback(const std_msgs::msg::String & msg){
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ChatterSubscriber>());
  rclcpp::shutdown();
  return 0;
}