#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class BlueROV2 : public rclcpp::Node {
public:
    BlueROV2() : Node("bluerov2_node"), count_(0) {
        std::string device = "udp:192.168.2.1:14550";
        int baudrate = 115200;

        std::string ROV_name = "BlueROV2";
        std::string model_base_link = "/base_link";
        auto timer_callback = [this]() -> void {
        auto message = std_msgs::msg::String();
        };
        timer_ = this->create_wall_timer(500ms, timer_callback);
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BlueROV2>());
    rclcpp::shutdown();
    return 0;
}