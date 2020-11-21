#ifndef _ROS_SERVICE_GetTrajectoryInfos_h
#define _ROS_SERVICE_GetTrajectoryInfos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingTrajectoryInfo.h"

namespace ram_utils
{

static const char GETTRAJECTORYINFOS[] = "ram_utils/GetTrajectoryInfos";

  class GetTrajectoryInfosRequest : public ros::Msg
  {
    public:

    GetTrajectoryInfosRequest()
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

    const char * getType(){ return GETTRAJECTORYINFOS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTrajectoryInfosResponse : public ros::Msg
  {
    public:
      typedef ram_msgs::AdditiveManufacturingTrajectoryInfo _informations_type;
      _informations_type informations;

    GetTrajectoryInfosResponse():
      informations()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->informations.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->informations.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETTRAJECTORYINFOS; };
    const char * getMD5(){ return "672157b68af82b60d524f1f70f1e12c7"; };

  };

  class GetTrajectoryInfos {
    public:
    typedef GetTrajectoryInfosRequest Request;
    typedef GetTrajectoryInfosResponse Response;
  };

}
#endif
