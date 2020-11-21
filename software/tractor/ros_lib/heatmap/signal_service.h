#ifndef _ROS_SERVICE_signal_service_h
#define _ROS_SERVICE_signal_service_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "heatmap/wifi_signal.h"

namespace heatmap
{

static const char SIGNAL_SERVICE[] = "heatmap/signal_service";

  class signal_serviceRequest : public ros::Msg
  {
    public:

    signal_serviceRequest()
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

    const char * getType(){ return SIGNAL_SERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class signal_serviceResponse : public ros::Msg
  {
    public:
      typedef heatmap::wifi_signal _signal_type;
      _signal_type signal;

    signal_serviceResponse():
      signal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->signal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->signal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SIGNAL_SERVICE; };
    const char * getMD5(){ return "58da7ff476f57ac5f5a609923bf16293"; };

  };

  class signal_service {
    public:
    typedef signal_serviceRequest Request;
    typedef signal_serviceResponse Response;
  };

}
#endif
