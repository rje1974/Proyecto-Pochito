#ifndef _ROS_cob_light_SetLightModeFeedback_h
#define _ROS_cob_light_SetLightModeFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_light
{

  class SetLightModeFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _active_mode_type;
      _active_mode_type active_mode;
      typedef uint8_t _active_priority_type;
      _active_priority_type active_priority;

    SetLightModeFeedback():
      active_mode(0),
      active_priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_mode);
      *(outbuffer + offset + 0) = (this->active_priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->active_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_mode);
      this->active_priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_priority);
     return offset;
    }

    const char * getType(){ return "cob_light/SetLightModeFeedback"; };
    const char * getMD5(){ return "18daff0db423efd323f68cd039226daa"; };

  };

}
#endif