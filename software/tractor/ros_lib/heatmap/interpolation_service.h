#ifndef _ROS_SERVICE_interpolation_service_h
#define _ROS_SERVICE_interpolation_service_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace heatmap
{

static const char INTERPOLATION_SERVICE[] = "heatmap/interpolation_service";

  class interpolation_serviceRequest : public ros::Msg
  {
    public:
      typedef float _spacing_type;
      _spacing_type spacing;
      typedef float _shepard_power_type;
      _shepard_power_type shepard_power;

    interpolation_serviceRequest():
      spacing(0),
      shepard_power(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_spacing;
      u_spacing.real = this->spacing;
      *(outbuffer + offset + 0) = (u_spacing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spacing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spacing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spacing.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spacing);
      union {
        float real;
        uint32_t base;
      } u_shepard_power;
      u_shepard_power.real = this->shepard_power;
      *(outbuffer + offset + 0) = (u_shepard_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_shepard_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_shepard_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_shepard_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shepard_power);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_spacing;
      u_spacing.base = 0;
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spacing = u_spacing.real;
      offset += sizeof(this->spacing);
      union {
        float real;
        uint32_t base;
      } u_shepard_power;
      u_shepard_power.base = 0;
      u_shepard_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_shepard_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_shepard_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_shepard_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->shepard_power = u_shepard_power.real;
      offset += sizeof(this->shepard_power);
     return offset;
    }

    const char * getType(){ return INTERPOLATION_SERVICE; };
    const char * getMD5(){ return "b66f64912c684c7f11a22da3498c859e"; };

  };

  class interpolation_serviceResponse : public ros::Msg
  {
    public:
      typedef int64_t _b_type;
      _b_type b;

    interpolation_serviceResponse():
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_b.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_b.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_b.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_b.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_b.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->b = u_b.real;
      offset += sizeof(this->b);
     return offset;
    }

    const char * getType(){ return INTERPOLATION_SERVICE; };
    const char * getMD5(){ return "b5a3c6284d5ab11e232db053f443f102"; };

  };

  class interpolation_service {
    public:
    typedef interpolation_serviceRequest Request;
    typedef interpolation_serviceResponse Response;
  };

}
#endif
