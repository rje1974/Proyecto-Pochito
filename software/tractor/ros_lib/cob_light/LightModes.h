#ifndef _ROS_cob_light_LightModes_h
#define _ROS_cob_light_LightModes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_light
{

  class LightModes : public ros::Msg
  {
    public:
      enum { NONE =            0            };
      enum { STATIC =          1            };
      enum { FLASH =           2            };
      enum { BREATH =          3            };
      enum { BREATH_COLOR =    4            };
      enum { FADE_COLOR =      5            };
      enum { SEQ =             6            };
      enum { CIRCLE_COLORS =   7            };
      enum { SWEEP =           8            };
      enum { DIST_APPROX =     9            };
      enum { GLOW =           10            };
      enum { XMAS =           11            };

    LightModes()
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

    const char * getType(){ return "cob_light/LightModes"; };
    const char * getMD5(){ return "a8bc2f81613e751ed7ec7ea0d8d7e7f4"; };

  };

}
#endif