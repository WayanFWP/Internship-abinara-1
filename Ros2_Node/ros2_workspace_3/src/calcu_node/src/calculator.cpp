#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"
#include <cstdlib>
#include <ctime>

class TrigCalculatorNode : public rclcpp::Node
{
public:
  TrigCalculatorNode() : Node("Node_dua_arah")
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("trig_operation", 10);
    subscription_ = this->create_subscription<std_msgs::msg::Float64>("trig_result", 10, std::bind(&TrigCalculatorNode::handleTrigResult, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(std::chrono::seconds(5), std::bind(&TrigCalculatorNode::publishTrigOperation, this));
  }

private:
  void publishTrigOperation()
  {
    std_msgs::msg::String msg;
    msg.data = generateRandomOperation();
    RCLCPP_INFO(this->get_logger(), "Operatornya: '%s'\n", msg.data.c_str());
    publisher_->publish(msg);
  }

  void handleTrigResult(const std_msgs::msg::Float64::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Received result: %f\n\n", msg->data);
  }

  std::string generateRandomOperation()
  {
    srand(time(NULL));
    std::string operations[] = {"sin", "cos", "tan", "asin", "acos", "atan"};
    return operations[rand() % 6];
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TrigCalculatorNode>());
  rclcpp::shutdown();
  return 0;
}
