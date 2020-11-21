#ifndef _ROS_cob_script_server_StateResult_h
#define _ROS_cob_script_server_StateResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_script_server
{

  class StateResult : public ros::Msg
  {
    public:
      typedef int16_t _return_value_type;
      _return_value_type return_value;

    StateResult():
      return_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_return_value;
      u_return_value.real = this->return_value;
      *(outbuffer + offset + 0) = (u_return_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_return_value.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->return_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_return_value;
      u_return_value.base = 0;
      u_return_value.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_return_value.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->return_value = u_return_value.real;
      offset += sizeof(this->return_value);
     return offset;
    }

    const char * getType(){ return "cob_script_server/StateResult"; };
    const char * getMD5(){ return "cfe8a15d5e2e01586cd5e05f2094f7c2"; };

  };

}
#endif