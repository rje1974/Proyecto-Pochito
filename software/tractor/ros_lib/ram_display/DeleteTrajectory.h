#ifndef _ROS_SERVICE_DeleteTrajectory_h
#define _ROS_SERVICE_DeleteTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_display
{

static const char DELETETRAJECTORY[] = "ram_display/DeleteTrajectory";

  class DeleteTrajectoryRequest : public ros::Msg
  {
    public:

    DeleteTrajectoryRequest()
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

    const char * getType(){ return DELETETRAJECTORY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteTrajectoryResponse : public ros::Msg
  {
    public:

    DeleteTrajectoryResponse()
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

    const char * getType(){ return DELETETRAJECTORY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteTrajectory {
    public:
    typedef DeleteTrajectoryRequest Request;
    typedef DeleteTrajectoryResponse Response;
  };

}
#endif
