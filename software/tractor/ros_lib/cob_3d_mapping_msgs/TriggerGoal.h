#ifndef _ROS_cob_3d_mapping_msgs_TriggerGoal_h
#define _ROS_cob_3d_mapping_msgs_TriggerGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_3d_mapping_msgs
{

  class TriggerGoal : public ros::Msg
  {
    public:
      typedef bool _start_type;
      _start_type start;

    TriggerGoal():
      start(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.real = this->start;
      *(outbuffer + offset + 0) = (u_start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.base = 0;
      u_start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start = u_start.real;
      offset += sizeof(this->start);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TriggerGoal"; };
    const char * getMD5(){ return "676aa7bfb3ec2071e814f2368dfd5fb5"; };

  };

}
#endif