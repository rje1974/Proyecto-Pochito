#ifndef _ROS_SERVICE_GetFillParameters_h
#define _ROS_SERVICE_GetFillParameters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingParams.h"

namespace ram_utils
{

static const char GETFILLPARAMETERS[] = "ram_utils/GetFillParameters";

  class GetFillParametersRequest : public ros::Msg
  {
    public:

    GetFillParametersRequest()
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

    const char * getType(){ return GETFILLPARAMETERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetFillParametersResponse : public ros::Msg
  {
    public:
      typedef ram_msgs::AdditiveManufacturingParams _parameters_type;
      _parameters_type parameters;

    GetFillParametersResponse():
      parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->parameters.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETFILLPARAMETERS; };
    const char * getMD5(){ return "ae02bed2ce5a447c317cd3f47ef1db33"; };

  };

  class GetFillParameters {
    public:
    typedef GetFillParametersRequest Request;
    typedef GetFillParametersResponse Response;
  };

}
#endif
