#ifndef _ROS_SERVICE_GetTrajectoryFrame_h
#define _ROS_SERVICE_GetTrajectoryFrame_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace ram_utils
{

static const char GETTRAJECTORYFRAME[] = "ram_utils/GetTrajectoryFrame";

  class GetTrajectoryFrameRequest : public ros::Msg
  {
    public:

    GetTrajectoryFrameRequest()
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

    const char * getType(){ return GETTRAJECTORYFRAME; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTrajectoryFrameResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;

    GetTrajectoryFrameResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETTRAJECTORYFRAME; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class GetTrajectoryFrame {
    public:
    typedef GetTrajectoryFrameRequest Request;
    typedef GetTrajectoryFrameResponse Response;
  };

}
#endif
