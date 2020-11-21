#ifndef _ROS_SERVICE_SetTriggerValue_h
#define _ROS_SERVICE_SetTriggerValue_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_phidgets
{

static const char SETTRIGGERVALUE[] = "cob_phidgets/SetTriggerValue";

  class SetTriggerValueRequest : public ros::Msg
  {
    public:
      typedef int8_t _index_type;
      _index_type index;
      typedef uint16_t _trigger_value_type;
      _trigger_value_type trigger_value;

    SetTriggerValueRequest():
      index(0),
      trigger_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->trigger_value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trigger_value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->trigger_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->index = u_index.real;
      offset += sizeof(this->index);
      this->trigger_value =  ((uint16_t) (*(inbuffer + offset)));
      this->trigger_value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->trigger_value);
     return offset;
    }

    const char * getType(){ return SETTRIGGERVALUE; };
    const char * getMD5(){ return "f5eabd2487a9b62214c60cbc4be257ee"; };

  };

  class SetTriggerValueResponse : public ros::Msg
  {
    public:

    SetTriggerValueResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETTRIGGERVALUE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetTriggerValue {
    public:
    typedef SetTriggerValueRequest Request;
    typedef SetTriggerValueResponse Response;
  };

}
#endif
