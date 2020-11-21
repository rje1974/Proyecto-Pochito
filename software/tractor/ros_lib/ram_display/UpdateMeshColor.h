#ifndef _ROS_SERVICE_UpdateMeshColor_h
#define _ROS_SERVICE_UpdateMeshColor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace ram_display
{

static const char UPDATEMESHCOLOR[] = "ram_display/UpdateMeshColor";

  class UpdateMeshColorRequest : public ros::Msg
  {
    public:
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;

    UpdateMeshColorRequest():
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UPDATEMESHCOLOR; };
    const char * getMD5(){ return "3e04b62b1b39cd97e873789f0bb130e7"; };

  };

  class UpdateMeshColorResponse : public ros::Msg
  {
    public:

    UpdateMeshColorResponse()
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

    const char * getType(){ return UPDATEMESHCOLOR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class UpdateMeshColor {
    public:
    typedef UpdateMeshColorRequest Request;
    typedef UpdateMeshColorResponse Response;
  };

}
#endif
