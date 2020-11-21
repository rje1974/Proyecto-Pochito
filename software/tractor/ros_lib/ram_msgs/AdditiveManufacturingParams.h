#ifndef _ROS_ram_msgs_AdditiveManufacturingParams_h
#define _ROS_ram_msgs_AdditiveManufacturingParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_msgs
{

  class AdditiveManufacturingParams : public ros::Msg
  {
    public:
      typedef uint32_t _movement_type_type;
      _movement_type_type movement_type;
      typedef uint32_t _approach_type_type;
      _approach_type_type approach_type;
      typedef float _blend_radius_type;
      _blend_radius_type blend_radius;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _laser_power_type;
      _laser_power_type laser_power;
      typedef float _feed_rate_type;
      _feed_rate_type feed_rate;

    AdditiveManufacturingParams():
      movement_type(0),
      approach_type(0),
      blend_radius(0),
      speed(0),
      laser_power(0),
      feed_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->movement_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->movement_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->movement_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->movement_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->movement_type);
      *(outbuffer + offset + 0) = (this->approach_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->approach_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->approach_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->approach_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->approach_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->blend_radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->laser_power);
      offset += serializeAvrFloat64(outbuffer + offset, this->feed_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->movement_type =  ((uint32_t) (*(inbuffer + offset)));
      this->movement_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->movement_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->movement_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->movement_type);
      this->approach_type =  ((uint32_t) (*(inbuffer + offset)));
      this->approach_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->approach_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->approach_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->approach_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->blend_radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->laser_power));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feed_rate));
     return offset;
    }

    const char * getType(){ return "ram_msgs/AdditiveManufacturingParams"; };
    const char * getMD5(){ return "5ec7c8aef9bbb21e5d08294f6320532f"; };

  };

}
#endif