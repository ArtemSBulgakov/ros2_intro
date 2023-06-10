#include <rclcpp/rclcpp.hpp>
#include <friend_msgs/msg/friend_info.hpp>

// https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html

using namespace std::chrono_literals;
 // TODO create timer that publish FriendInfo msg 10 times per second 
class SenderNode : public rclcpp::Node{
  public:
    SenderNode() : Node("SenderNode") {
      publisher = this->create_publisher<friend_msgs::msg::FriendInfo>("/r2d2_pose", 10);
      timer = this->create_wall_timer(
        100ms,
        std::bind(&SenderNode::timer_callback, this)
      );
    }

  private:
    rclcpp::Publisher<friend_msgs::msg::FriendInfo>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;

    void timer_callback() {
      auto message = friend_msgs::msg::FriendInfo();
      message.name = "r2d2";
      message.id = 456;
      publisher->publish(message);
    }
};

int main(int argc, char** argv){
  rclcpp::init(argc, argv);

  auto node = std::make_shared<SenderNode>();
  
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}