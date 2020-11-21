#ifndef _ROS_cob_light_SetLightModeGoal_h
#define _ROS_cob_light_SetLightModeGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_light/LightMode.h"

namespace cob_light
{

  class SetLightModeGoal : public ros::Msg
  {
    public:
      typedef cob_light::LightMode _mode_type;
      _mode_type mode;

    SetLightModeGoal():
      mode()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->mode.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->mode.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_light/SetLightModeGoal"; };
    const char * getMD5(){ return "cf64533ba011e7f531cecce5a35c9b83"; };

  };

}
#endif