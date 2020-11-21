#ifndef _ROS_SERVICE_GetTrajectorySize_h
#define _ROS_SERVICE_GetTrajectorySize_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char GETTRAJECTORYSIZE[] = "ram_utils/GetTrajectorySize";

  class GetTrajectorySizeRequest : public ros::Msg
  {
    public:

    GetTrajectorySizeRequest()
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

    const char * getType(){ return GETTRAJECTORYSIZE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTrajectorySizeResponse : public ros::Msg
  {
    public:
      typedef uint32_t _trajectory_size_type;
      _trajectory_size_type trajectory_size;

    GetTrajectorySizeResponse():
      trajectory_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trajectory_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->trajectory_size =  ((uint32_t) (*(inbuffer + offset)));
      this->trajectory_size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trajectory_size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trajectory_size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trajectory_size);
     return offset;
    }

    const char * getType(){ return GETTRAJECTORYSIZE; };
    const char * getMD5(){ return "f9c0592406efff39d6571b7cdd49ea64"; };

  };

  class GetTrajectorySize {
    public:
    typedef GetTrajectorySizeRequest Request;
    typedef GetTrajectorySizeResponse Response;
  };

}
#endif
