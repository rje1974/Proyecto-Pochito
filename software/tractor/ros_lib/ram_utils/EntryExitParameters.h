#ifndef _ROS_SERVICE_EntryExitParameters_h
#define _ROS_SERVICE_EntryExitParameters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char ENTRYEXITPARAMETERS[] = "ram_utils/EntryExitParameters";

  class EntryExitParametersRequest : public ros::Msg
  {
    public:
      typedef float _angle_type;
      _angle_type angle;
      typedef float _distance_type;
      _distance_type distance;
      typedef uint32_t _number_of_poses_type;
      _number_of_poses_type number_of_poses;

    EntryExitParametersRequest():
      angle(0),
      distance(0),
      number_of_poses(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      *(outbuffer + offset + 0) = (this->number_of_poses >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->number_of_poses >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->number_of_poses >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->number_of_poses >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_poses);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      this->number_of_poses =  ((uint32_t) (*(inbuffer + offset)));
      this->number_of_poses |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->number_of_poses |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->number_of_poses |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->number_of_poses);
     return offset;
    }

    const char * getType(){ return ENTRYEXITPARAMETERS; };
    const char * getMD5(){ return "f3865aa8f457a862542f034bc3253ebf"; };

  };

  class EntryExitParametersResponse : public ros::Msg
  {
    public:

    EntryExitParametersResponse()
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

    const char * getType(){ return ENTRYEXITPARAMETERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EntryExitParameters {
    public:
    typedef EntryExitParametersRequest Request;
    typedef EntryExitParametersResponse Response;
  };

}
#endif
