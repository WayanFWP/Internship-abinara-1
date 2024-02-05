#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

class TrigCalculatorNode : public rclcpp::Node
{
public:
  TrigCalculatorNode() : Node("Calculator_Node")
  {
    derajat = {0, 15, 30, 45, 60, 75, 90, 120, 135, 150, 180, 210, 225, 240, 270, 300, 315, 330, 360};
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "trig_operation", 10, std::bind(&TrigCalculatorNode::calculateTrigOperation, this, std::placeholders::_1));
    publisher_ = this->create_publisher<std_msgs::msg::Float64>("trig_result", 10);

    srand(time(NULL));
  }

private:
  void calculateTrigOperation(const std_msgs::msg::String::SharedPtr msg)
  {
    int random_index = rand() % derajat.size();
    int Derajat_penentu = derajat[random_index];

    double result = 0.0;
    double radian = Derajat_penentu * M_PI / 180.0; 

    if (msg->data == "sin")
    {
      result = sin(radian);
    }
    else if (msg->data == "cos")
    {
      result = cos(radian);
    }
    else if (msg->data == "tan")
    {
      result = tan(radian);
    }
    else if (msg->data == "asin")
    {
      result = asin(radian);
    }
    else if (msg->data == "acos")
    {
      result = acos(radian);
    }
    else if (msg->data == "atan")
    {
      result = atan(radian);
    }

    std_msgs::msg::Float64 result_msg;
    result_msg.data = result;
    RCLCPP_INFO(this->get_logger(), "Hasli dari %d derajat : %f", Derajat_penentu, result_msg.data);
    publisher_->publish(result_msg);
  }

  std::vector<int> derajat;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TrigCalculatorNode>());
  rclcpp::shutdown();
  return 0;
}
