#ifndef PS5_HPP
#define PS5_HPP

#include "ps_base.hpp"

namespace ps5
{
class ps : public ps_base
{
public:
  void get_data(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    cross_btn = msg->buttons[0];
    circle_btn = msg->buttons[1];
    square_btn = msg->buttons[2];
    triangle_btn = msg->buttons[3];

    create_btn = bool(msg->buttons[4]);
    PS_btn = bool(msg->buttons[5]);
    options_btn = bool(msg->buttons[6]);

    L1_btn = bool(msg->buttons[9]);

    R1_btn = bool(msg->buttons[10]);

    joy_left_x = msg->axes[0];
    joy_left_y = msg->axes[1];

    joy_right_x = msg->axes[2];
    joy_right_y = msg->axes[3];

    R2 = msg->axes[4];
    R2_btn = std::abs(msg->axes[4] - 1) > 0.1;

    L2 = msg->axes[5];
    L2_btn = std::abs(msg->axes[5] - 1) > 0.1;

    d_pad_x = msg->axes[6];
    d_pad_y = msg->axes[7];

    d_pad2btn();
  }

  // virtual void sub_joy_thread(const sensor_msgs::msg::Joy::SharedPtr msg)
  // {
  //     get_data(msg);
  // }
};
}

#endif
