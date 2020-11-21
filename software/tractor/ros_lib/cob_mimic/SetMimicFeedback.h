#ifndef _ROS_cob_mimic_SetMimicFeedback_h
#define _ROS_cob_mimic_SetMimicFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_mimic
{

  class SetMimicFeedback : public ros::Msg
  {
    public:

    SetMimicFeedback()
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

    const char * getType(){ return "cob_mimic/SetMimicFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif