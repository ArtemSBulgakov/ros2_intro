#include <vector>
#include <string>
#include <friend_msgs/msg/friend_info.hpp>
#include "rclcpp/rclcpp.hpp"

// https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Using-Parameters-In-A-Class-CPP.html

class SetUserInfo : public rclcpp::Node
{
public:
  SetUserInfo()
  : Node("set_user_info_node")
  {
    declare_parameter("user_name", "r2d2");
    declare_parameter("user_id", 345);
    // TODO declare parameter for friends_names(vector of string) and friends_ids (you need to decide the type and why)
    declare_parameter("friends_names", std::vector<std::string>());
    declare_parameter("friends_ids", std::vector<int>());

    get_parameter("user_name", user_name_);
    RCLCPP_INFO_STREAM(get_logger(), "User name: " << user_name_);

    get_parameter("user_id", user_id_);
    RCLCPP_INFO_STREAM(get_logger(), "User id: "<< user_id_);

    // TODO get the friends_names and friends_ids parameters 

    get_parameter("friends_names", friends_names_);
    get_parameter("friends_ids", friends_ids_);

    if (friends_names_.size() != friends_ids_.size()) {
      RCLCPP_ERROR( get_logger(), "Friend names (%zu) !=  ids (%zu) ", friends_names_.size(), friends_ids_.size());
    } else {
      RCLCPP_INFO_STREAM(get_logger(), "Number of friends: " << friends_names_.size());
      for (size_t i = 0; i < friends_names_.size(); i++) {
        RCLCPP_INFO_STREAM(get_logger(), "\t" << friends_names_[i] << "\t - " << friends_ids_[i]);
      }
    }
  }

private:
  std::string user_name_;
  int user_id_;
  std::vector<std::string> friends_names_;
  std::vector<int64_t> friends_ids_;
  
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<SetUserInfo>();

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
