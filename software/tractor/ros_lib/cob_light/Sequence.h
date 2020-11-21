#ifndef _ROS_cob_light_Sequence_h
#define _ROS_cob_light_Sequence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_light
{

  class Sequence : public ros::Msg
  {
    public:
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef float _hold_time_type;
      _hold_time_type hold_time;
      typedef float _cross_time_type;
      _cross_time_type cross_time;

    Sequence():
      color(),
      hold_time(0),
      cross_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_hold_time;
      u_hold_time.real = this->hold_time;
      *(outbuffer + offset + 0) = (u_hold_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hold_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hold_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hold_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hold_time);
      union {
        float real;
        uint32_t base;
      } u_cross_time;
      u_cross_time.real = this->cross_time;
      *(outbuffer + offset + 0) = (u_cross_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cross_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cross_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cross_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cross_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_hold_time;
      u_hold_time.base = 0;
      u_hold_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hold_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hold_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hold_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hold_time = u_hold_time.real;
      offset += sizeof(this->hold_time);
      union {
        float real;
        uint32_t base;
      } u_cross_time;
      u_cross_time.base = 0;
      u_cross_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cross_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cross_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cross_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cross_time = u_cross_time.real;
      offset += sizeof(this->cross_time);
     return offset;
    }

    const char * getType(){ return "cob_light/Sequence"; };
    const char * getMD5(){ return "7093bc102ba3b6d78256c69c48c6a43b"; };

  };

}
#endif