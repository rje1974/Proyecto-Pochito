#ifndef _ROS_SERVICE_UnmodifiedTrajectory_h
#define _ROS_SERVICE_UnmodifiedTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ram_msgs/AdditiveManufacturingTrajectory.h"

namespace ram_utils
{

static const char UNMODIFIEDTRAJECTORY[] = "ram_utils/UnmodifiedTrajectory";

  class UnmodifiedTrajectoryRequest : public ros::Msg
  {
    public:
      typedef ros::Time _generated_type;
      _generated_type generated;

    UnmodifiedTrajectoryRequest():
      generated()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->generated.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->generated.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->generated.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->generated.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->generated.sec);
      *(outbuffer + offset + 0) = (this->generated.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->generated.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->generated.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->generated.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->generated.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->generated.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->generated.sec);
      this->generated.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->generated.nsec);
     return offset;
    }

    const char * getType(){ return UNMODIFIEDTRAJECTORY; };
    const char * getMD5(){ return "4da8f791d03b7341432be9295a569ab6"; };

  };

  class UnmodifiedTrajectoryResponse : public ros::Msg
  {
    public:
      typedef ram_msgs::AdditiveManufacturingTrajectory _trajectory_type;
      _trajectory_type trajectory;

    UnmodifiedTrajectoryResponse():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UNMODIFIEDTRAJECTORY; };
    const char * getMD5(){ return "07d02d79107649c0fed28e4a2dea028b"; };

  };

  class UnmodifiedTrajectory {
    public:
    typedef UnmodifiedTrajectoryRequest Request;
    typedef UnmodifiedTrajectoryResponse Response;
  };

}
#endif
